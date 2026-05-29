%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

extern void entrar_escopo();
extern void sair_escopo();
extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }

char buf[200];
extern char c_decl[5000], c_body[5000], instrucoes[5000];
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        char* label;
        int tipo_val;
    } info;
}

%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT STRING_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL ASSIGN PLUS
%token AND OR EQ NE LE GE NOT
%token TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO TOKEN_FOR TOKEN_BREAK TOKEN_CONTINUE TOKEN_PRINT TOKEN_READ

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT
%right CAST
%right UMINUS

%type <info> expressao comando

%%

programa : comandos ;

comandos : comando comandos 
         | /* vazio */ ;

comando : declaracao ';' { $$.temp = ""; $$.c_expr = ""; $$.label = ""; $$.tipo_val = 0; }
        | atribuicao ';' { $$.temp = ""; $$.c_expr = ""; $$.label = ""; $$.tipo_val = 0; }
        | expressao ';'  { $$ = $1; } 
        | TOKEN_PRINT expressao ';' {
            if ($2.tipo_val == T_INT || $2.tipo_val == T_BOOL) sprintf(buf, "printf(\"%%d\\n\", %s);\n", $2.c_expr);
            else if ($2.tipo_val == T_FLOAT) sprintf(buf, "printf(\"%%f\\n\", %s);\n", $2.c_expr);
            else if ($2.tipo_val == T_CHAR) sprintf(buf, "printf(\"%%c\\n\", %s);\n", $2.c_expr);
            else if ($2.tipo_val == T_STRING) sprintf(buf, "printf(\"%%s\\n\", %s);\n", $2.c_expr);
            strcat(c_body, buf);
            sprintf(buf, "param %s;\ncall print, 1;\n", $2.temp);
            strcat(instrucoes, buf);
            $$.temp = ""; $$.c_expr = ""; $$.label = ""; $$.tipo_val = 0;
        }
        | TOKEN_IF '(' expressao ')' <info> {
           if ($3.tipo_val != T_BOOL) {
                yyerror("Erro Semantico: Condicao do IF deve ser do tipo BOOL.");
                YYERROR;
            }
            $$.label = novo_label();
            sprintf(buf, "ifFalse %s goto %s;\n", $3.temp, $$.label);
            strcat(instrucoes, buf);
        } bloco {
            sprintf(buf, "%s:\n", $5.label);
            strcat(instrucoes, buf);
        }
        | bloco { $$.temp = ""; $$.c_expr = ""; $$.label = ""; $$.tipo_val = 0; }
        ;

bloco : '{' { entrar_escopo(); } lista_comandos '}' { sair_escopo(); }
      ;

      

lista_comandos : /* vazio */
               | lista_comandos comando
               ;

declaracao : TOKEN_INT   ID {
                inserir($2, T_INT);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID {
                inserir($2, T_FLOAT);
                sprintf(buf, "float %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR  ID {
                inserir($2, T_CHAR);
                sprintf(buf, "char %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_BOOL  ID {
                inserir($2, T_BOOL);
                sprintf(buf, "int %s;\n", $2);
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
          | STRING_LIT {
                $$.tipo_val = T_STRING;
                $$.temp   = novo_temp(T_STRING);
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
          | ID {
                Simbolo *s = buscar($1);
                if (s) {
                    $$.tipo_val = s->tipo;
                    $$.temp   = s->temp;
                    $$.c_expr = strdup(s->nome);
                } else {
                    yyerror("Var nao declarada");
                    $$.temp   = strdup("ERRO");
                    $$.c_expr = strdup("ERRO");
                    $$.tipo_val = T_INT;
                }
            }
          | expressao PLUS expressao {
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Operadores booleanos nao sao permitidos em operacoes aritmeticas (+).");
                    $$.tipo_val = T_INT; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Operadores booleanos nao sao permitidos em operacoes aritmeticas (-).");
                    $$.tipo_val = T_INT; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Operadores booleanos nao sao permitidos em operacoes aritmeticas (*).");
                    $$.tipo_val = T_INT; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Operadores booleanos nao sao permitidos em operacoes aritmeticas (/).");
                    $$.tipo_val = T_INT; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
          | expressao EQ expressao {
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao relacional (==) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao relacional (!=) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao de grandeza (>) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao de grandeza (<) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao de grandeza (>=) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($1.tipo_val == T_BOOL || $3.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e permitido fazer essa operacao de grandeza (<=) envolvendo tipo bool.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
          | expressao AND expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos exclusivamente booleanos.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                    yyerror("Erro Semantico: Operador OR requer operandos exclusivamente booleanos.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                    yyerror("Erro Semantico: Operador NOT requer um operando booleano.");
                    $$.tipo_val = T_BOOL; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
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
                if ($2.tipo_val == T_BOOL) {
                    yyerror("Erro Semantico: Nao e possivel aplicar o operador de inversao (-) a um tipo booleano.");
                    $$.tipo_val = T_INT; $$.temp = strdup("ERRO"); $$.c_expr = strdup("ERRO");
                } else {
                    $$.tipo_val = $2.tipo_val;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = -%s;\n", $$.temp, $2.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen($2.c_expr) + 4);
                    sprintf(ce, "(-%s)", $2.c_expr);
                    $$.c_expr = ce;
                }
            }
          ;

%%

int main() {
    yyparse();

    /* Codigo Intermediario */
    printf("=== Codigo Intermediario ===\n");
    printf("%s\n%s\n", c_decl, instrucoes);

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