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
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
    } info;
}

%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL ASSIGN PLUS
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

comando : declaracao ';'
        | atribuicao ';'
        | expressao ';' ;

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
                    $$.temp   = "ERRO";
                    $$.c_expr = strdup("ERRO");
                    $$.tipo_val = T_INT;
                }
            }

          | expressao PLUS expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
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
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s == %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s == %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }
          | expressao NE expressao {
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s != %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s != %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }
          | expressao '>' expressao {
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s > %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s > %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }
          | expressao '<' expressao {
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s < %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s < %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }
          | expressao GE expressao {
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s >= %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }
          | expressao LE expressao {
                $$.tipo_val = T_BOOL;
                $$.temp = novo_temp(T_BOOL);
                sprintf(buf, "%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 8);
                sprintf(ce, "(%s <= %s)", $1.c_expr, $3.c_expr);
                $$.c_expr = ce;
            }

          | expressao AND expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
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
