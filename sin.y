%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

int escopo_atual = 0;
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
    } info;
}

%token TOKEN_FOR
%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT STRING_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL TOKEN_STRING ASSIGN PLUS
%token TOKEN_PRINT TOKEN_READ TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO
%token TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK
%token TOKEN_CONTINUE
%token AND OR EQ NE LE GE NOT

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT
%right CAST
%right UMINUS

%type <info> expressao

%%

programa : comandos ;

comandos : comando comandos | ;

bloco : '{' { escopo_atual++; } comandos_bloco '}' {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
    ;

comandos_bloco : comando comandos_bloco
                |
                ;

/* --- REGRA AUXILIAR DO IF --- */
if_cond : TOKEN_IF '(' expressao ')' {
    if ($3.tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    
    sprintf(buf, "ifFalse %s goto %s;\n", $3.temp, l_false);
    strcat(instrucoes, buf);
    
    sprintf(buf, "if (%s) {\n", $3.c_expr);
    strcat(c_body, buf);
    
    $<valor_str>$ = l_false; /* Passa o label pra frente */
}
;

/* --- REGRA AUXILIAR DO FOR --- */
incremento_for : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        // Guarda o código em vez de imprimir direto nos buffers principais
        sprintf(inc_3ac, "%s = %s;\n", s->temp, $3.temp);
        sprintf(inc_c, "%s = %s;\n", s->nome, $3.c_expr);
    }
}
;

casos_lista : caso casos_lista
            | default_caso
            | /* vazio */
            ;

caso : TOKEN_CASE expressao ':' {
        // 1. Gera rótulo pro próximo case (se este falhar)
        char* l_proximo = novo_label();
        
        // 2. Compara a expressão do Switch com a expressão do Case
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, $2.temp);
        strcat(instrucoes, buf);
        
        // 3. Se falso, pula pro próximo case
        sprintf(buf, "ifFalse %s goto %s;\n", t_cmp, l_proximo);
        strcat(instrucoes, buf);
        
        // 4. Código C
        sprintf(buf, "case %s:\n", $2.c_expr);
        strcat(c_body, buf);
        
        $<valor_str>$ = l_proximo; // Salva o l_proximo em $4
        
    } comandos_bloco TOKEN_BREAK ';' {
        // 5. Fim do case: pula pro fim do switch (break do 3AC)
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);
        
        // 6. Imprime o rótulo do próximo case (recupera de $4)
        sprintf(buf, "%s:\n", $<valor_str>4);
        strcat(instrucoes, buf);
        
        // 7. Break do C
        strcat(c_body, "break;\n");
    }
    ;

default_caso : TOKEN_DEFAULT ':' {
        strcat(c_body, "default:\n");
    } comandos_bloco {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
    ;

comando : declaracao ';'
        | atribuicao ';'
        | expressao ';' 
        | bloco ;
        | TOKEN_PRINT '(' expressao ')' ';' {
            // 1. Gera o Código Intermediário (3AC)
            sprintf(buf, "print %s;\n", $3.temp);
            strcat(instrucoes, buf);

            // 2. Descobre o formato para o printf do C
            char* formato = "";
            if ($3.tipo_val == T_INT || $3.tipo_val == T_BOOL) formato = "%d";
            else if ($3.tipo_val == T_FLOAT) formato = "%f";
            else if ($3.tipo_val == T_CHAR) formato = "%c";
            else if ($3.tipo_val == T_STRING) formato = "%s";

            // 3. Gera o Código C
            sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, $3.c_expr);
            strcat(c_body, buf);
        }
        /* --- COMANDO DE ENTRADA (READ) --- */
        | TOKEN_READ '(' ID ')' ';' {
            Simbolo *s = buscar($3);
            if (!s) {
                char erro_msg[100];
                sprintf(erro_msg, "Erro: Variavel '%s' nao declarada para leitura.", $3);
                yyerror(erro_msg);
            } else {
                // 1. Gera o Código Intermediário (3AC)
                sprintf(buf, "read %s;\n", s->nome); 
                strcat(instrucoes, buf);

                // 2. Descobre o formato para o scanf do C
                char* formato = "";
                if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
                else if (s->tipo == T_FLOAT) formato = "%f";
                else if (s->tipo == T_CHAR) formato = " %c"; 

                // 3. Gera o Código C 
                if (s->tipo == T_STRING) {
                    sprintf(buf, "%s = (char*) malloc(256);\n", s->nome);
                    strcat(c_body, buf);
                    sprintf(buf, "scanf(\"%%s\", %s);\n", s->nome);
                } else {
                    sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->nome);
                }
                strcat(c_body, buf);
            }
        } 
        | if_cond comando {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", $<valor_str>1); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
        | if_cond comando TOKEN_ELSE {
            // METADE DO ELSE
            char* l_fim = novo_label();
            
            // 1. O 'true' pula pro fim
            sprintf(buf, "goto %s;\n", l_fim);
            strcat(instrucoes, buf);
            
            // 2. Imprime o label do 'false' (que veio do if_cond)
            sprintf(buf, "%s:\n", $<valor_str>1);
            strcat(instrucoes, buf);
            
            // 3. Código C
            strcat(c_body, "} else {\n");
            
            // Passa o label de fim para o próximo bloco
            $<valor_str>$ = l_fim; 
            
        } comando {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", $<valor_str>4); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        } 
        | TOKEN_WHILE {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        } '(' expressao ')' {
            if ($4.tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
            
            char* l_fim = novo_label();
            sprintf(buf, "ifFalse %s goto %s;\n", $4.temp, l_fim);
            strcat(instrucoes, buf);
            sprintf(buf, "while (%s) {\n", $4.c_expr);
            strcat(c_body, buf);
            $<valor_str>$ = l_fim; 
            
            // --- LINHAS NOVAS 2 e 3: Salva o fim e sobe a pilha ---
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++; 
            
        } comando {
            // --- LINHA NOVA 4: Desce a pilha pois o laço acabou ---
            topo_laco--; 
            
            sprintf(buf, "goto %s;\n", $<valor_str>2); 
            strcat(instrucoes, buf);
            sprintf(buf, "%s:\n", $<valor_str>6); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
        | TOKEN_DO {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio;
            strcat(c_body, "do {\n");
        } comando TOKEN_WHILE '(' expressao ')' ';' {
            // Agora a expressao é o $6, porque:
            // 1=TOKEN_DO, 2={...}, 3=comando, 4=WHILE, 5='(', 6=expressao
            
            if ($6.tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'do-while' deve ser booleana.");
            }
            
            // Pula para o início se for verdadeiro
            sprintf(buf, "if %s goto %s;\n", $6.temp, $<valor_str>2);
            strcat(instrucoes, buf);
            
            // Código C
            sprintf(buf, "} while (%s);\n", $6.c_expr);
            strcat(c_body, buf);
        }
        | TOKEN_FOR '(' atribuicao ';' {
            // 1. A inicialização já foi impressa pela 'atribuicao'.
            
            // 2. Marca o rótulo de INÍCIO
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio; // Salva na posição $5
            
        } expressao ';' {
            // 3. Verifica a CONDIÇÃO
            if ($6.tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'for' deve ser booleana.");
            }
            char* l_fim = novo_label();
            sprintf(buf, "ifFalse %s goto %s;\n", $6.temp, l_fim);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_fim; // Salva na posição $8
            
            // Converte o FOR num WHILE no código C gerado (mesma semântica!)
            sprintf(buf, "while (%s) {\n", $6.c_expr);
            strcat(c_body, buf);
            
        } incremento_for ')' comando {
            // 4. Chegamos no final do laço!
            
            // Imprime o incremento que estava "guardado"
            strcat(instrucoes, inc_3ac);
            
            // Imprime o incremento no C
            sprintf(buf, "%s", inc_c);
            strcat(c_body, buf);
            
            // Pula de volta pro início
            sprintf(buf, "goto %s;\n", $<valor_str>5);
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM
            sprintf(buf, "%s:\n", $<valor_str>8);
            strcat(instrucoes, buf);
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
        | TOKEN_SWITCH '(' expressao ')' {
            // 1. Salva a variável avaliada e gera o rótulo de saída
            strcpy(switch_exp, $3.temp);
            strcpy(switch_fim, novo_label());
            
            // 2. Código C
            sprintf(buf, "switch (%s) {\n", $3.c_expr);
            strcat(c_body, buf);
            
        } '{' casos_lista '}' {
            // 3. Fim do Switch: imprime o rótulo de saída
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);
            
            strcat(c_body, "}\n");
        }
        /* --- COMANDOS DE PULO --- */
        | TOKEN_BREAK ';' {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'break' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de FIM do laço atual
                sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "break;\n");
            }
        }
        | TOKEN_CONTINUE ';' {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'continue' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de INÍCIO do laço atual
                sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "continue;\n");
            }
        }

declaracao : TOKEN_INT   ID {
                inserir($2, T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID {
                inserir($2, T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR  ID {
                inserir($2, T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_BOOL  ID {
                inserir($2, T_BOOL, escopo_atual);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);
             }
            | TOKEN_STRING ID {
                inserir($2, T_STRING, escopo_atual);
                sprintf(buf, "char* %s;\n", $2);
                strcat(c_decl, buf);
             }
           ;

atribuicao : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variavel '%s' nao declarada.", $1);
        yyerror(erro_msg);
    } else {
        char* valor_final  = $3.temp;
        char* c_expr_final = $3.c_expr;
        int sem_erro = 1;

        if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
            valor_final = gerar_cast($3.temp, T_FLOAT);
            char *tmp = (char*) malloc(strlen(c_expr_final) + 16);
            sprintf(tmp, "(float)(%s)", c_expr_final);
            c_expr_final = tmp;
        } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
            valor_final = gerar_cast($3.temp, T_INT);
            char *tmp = (char*) malloc(strlen(c_expr_final) + 16);
            sprintf(tmp, "(int)(%s)", c_expr_final);
            c_expr_final = tmp;
        } else if (s->tipo != $3.tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }

        if (sem_erro) {
            sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            strcat(instrucoes, buf);

            sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
            strcat(c_body, buf);
        }
    }
};

expressao : NUM_INT {
                $$.tipo_val = T_INT;
                $$.temp   = novo_temp(T_INT);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | NUM_FLOAT {
                $$.tipo_val = T_FLOAT;
                $$.temp   = novo_temp(T_FLOAT);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | CHAR_LIT {
                $$.tipo_val = T_CHAR;
                $$.temp   = novo_temp(T_CHAR);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | BOOL_LIT {
                $$.tipo_val = T_BOOL;
                $$.temp   = novo_temp(T_BOOL);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
            | STRING_LIT {
                $$.tipo_val = T_STRING;
                $$.temp   = novo_temp(T_STRING);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | ID {
                Simbolo *s = buscar($1);
                if (s) {
                    $$.tipo_val = s->tipo;
                    $$.temp   = s->temp;
                    $$.c_expr = strdup(s->nome);
                } else {
                    yyerror("Var nao declarada");
                    $$.temp   = "ERRO";
                    $$.c_expr = strdup("ERRO");
                    $$.tipo_val = T_INT;
                }
            }

          /* --- ARITMÉTICA --- */
          | expressao PLUS expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s + %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s + %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }
          | expressao '-' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de subtracao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s - %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s - %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }
          | expressao '*' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s * %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }
          | expressao '/' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s / %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s / %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }

          /* --- RELACIONAIS (C/ Checagem de Tipo) --- */
          | expressao EQ expressao {
                if (($1.tipo_val == T_BOOL && $3.tipo_val != T_BOOL) ||
                    ($1.tipo_val != T_BOOL && $3.tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '==' entre tipos incompativeis.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s == %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s == %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao NE expressao {
                if (($1.tipo_val == T_BOOL && $3.tipo_val != T_BOOL) ||
                    ($1.tipo_val != T_BOOL && $3.tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '!=' entre tipos incompativeis.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s != %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s != %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao '>' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s > %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s > %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao '<' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s < %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s < %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao GE expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>=' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s >= %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao LE expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<=' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s <= %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }

          /* --- LÓGICOS E PARÊNTESES --- */
          | expressao AND expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s && %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s && %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao OR expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador OR requer operandos booleanos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s || %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                    sprintf(ce, "(%s || %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | NOT expressao {
                if ($2.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador NOT requer operando booleano.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = !%s;\n", $$.temp, $2.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($2.c_expr) + 4);
                    sprintf(ce, "(!%s)", $2.c_expr);
                    $$.c_expr = ce;
                }
            }

          | '(' TOKEN_INT ')' expressao %prec CAST {
                char* temp_copia = novo_temp($4.tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                strcat(instrucoes, buf);
                $$.tipo_val = T_INT;
                $$.temp = novo_temp(T_INT);
                sprintf(buf, "%s = (int) %s;\n", $$.temp, temp_copia);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($4.c_expr) + 16);
                sprintf(ce, "(int)(%s)", $4.c_expr);
                $$.c_expr = ce;
            }
          | '(' TOKEN_FLOAT ')' expressao %prec CAST {
                char* temp_copia = novo_temp($4.tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                strcat(instrucoes, buf);
                $$.tipo_val = T_FLOAT;
                $$.temp = novo_temp(T_FLOAT);
                sprintf(buf, "%s = (float) %s;\n", $$.temp, temp_copia);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($4.c_expr) + 16);
                sprintf(ce, "(float)(%s)", $4.c_expr);
                $$.c_expr = ce;
            }
          | '(' expressao ')' {
                $$ = $2;
            }
          | '-' expressao %prec UMINUS {
                $$.tipo_val = $2.tipo_val;
                $$.temp = novo_temp($$.tipo_val);
                sprintf(buf, "%s = -%s;\n", $$.temp, $2.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($2.c_expr) + 4);
                sprintf(ce, "(-%s)", $2.c_expr);
                $$.c_expr = ce;
            }
          ;

%%

int main() {
    yyparse();

    /* Codigo Intermediario */
    printf("=== Codigo Intermediario ===\n");
    printf("%s\n%s\n", declaracoes, instrucoes);

    /* Codigo C */
    printf("=== Codigo C ===\n");
    printf("#include <stdio.h>\n\nint main() {\n");

    char tmp1[5000], tmp2[5000];

    strcpy(tmp1, c_decl);
    for (char *l = strtok(tmp1, "\n"); l; l = strtok(NULL, "\n"))
        printf("    %s\n", l);

    printf("\n");

    strcpy(tmp2, c_body);
    for (char *l = strtok(tmp2, "\n"); l; l = strtok(NULL, "\n"))
        printf("    %s\n", l);

    printf("    return 0;\n}\n");
    return 0;
}