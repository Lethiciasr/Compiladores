%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }

char buf[200];
%}

%union {
    char* valor_str;
    struct {
        char* temp;
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

%type <info> expressao

%%

programa : comandos ;

comandos : comando comandos | ;

comando : declaracao ';' 
        | atribuicao ';' 
        | expressao ';' 
        | expressao ;

declaracao : TOKEN_INT ID    { inserir($2, T_INT); }
           | TOKEN_FLOAT ID  { inserir($2, T_FLOAT); }
           | TOKEN_CHAR ID   { inserir($2, T_CHAR); }
           | TOKEN_BOOL ID   { inserir($2, T_BOOL); };

atribuicao : ID ASSIGN expressao {
    Simbolo *s = buscar($1); 
    if (!s) {
        yyerror("Variável não declarada");
    } else {
        char* valor_final = $3.temp;
        
        // Conversão Implícita na Atribuição (Coerção)
        if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
            valor_final = gerar_cast($3.temp, T_FLOAT);
        } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
            valor_final = gerar_cast($3.temp, T_INT);
        }
        
        // Removido o comentário e as tags de cite
        sprintf(buf, "%s = %s;\n", s->temp, valor_final);
        strcat(instrucoes, buf); 
    }
};

expressao : NUM_INT { 
                $$.tipo_val = T_INT; 
                $$.temp = novo_temp(T_INT); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf); 
            }
          | NUM_FLOAT { 
                $$.tipo_val = T_FLOAT; 
                $$.temp = novo_temp(T_FLOAT); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf); 
            }
          | CHAR_LIT { 
                $$.tipo_val = T_CHAR; 
                $$.temp = novo_temp(T_CHAR); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf);
            }
          | BOOL_LIT { 
                $$.tipo_val = T_BOOL; 
                $$.temp = novo_temp(T_BOOL); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf);
            }
          | ID { 
                Simbolo *s = buscar($1); 
                if(s) { 
                    // Mudança principal aqui: Geração de um novo temporário para leitura
                    $$.tipo_val = s->tipo; 
                    $$.temp = novo_temp(s->tipo); 
                    sprintf(buf, "%s = %s;\n", $$.temp, s->temp);
                    strcat(instrucoes, buf);
                } else { 
                    yyerror("Var não declarada"); 
                } 
            }
          
          /* Aritmética com Coerção Automática */
          | expressao PLUS expressao { 
                if ($1.tipo_val != $3.tipo_val) {
                    if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                    else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                }
                $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                $$.temp = novo_temp($$.tipo_val); 
                sprintf(buf, "%s = %s + %s;\n", $$.temp, $1.temp, $3.temp); 
                strcat(instrucoes, buf);
            }
          | expressao '-' expressao { 
                if ($1.tipo_val != $3.tipo_val) {
                    if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                    else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                }
                $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                $$.temp = novo_temp($$.tipo_val); 
                sprintf(buf, "%s = %s - %s;\n", $$.temp, $1.temp, $3.temp); 
                strcat(instrucoes, buf); 
            }
          | expressao '*' expressao { 
                if ($1.tipo_val != $3.tipo_val) {
                    if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                    else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                }
                $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                $$.temp = novo_temp($$.tipo_val); 
                sprintf(buf, "%s = %s * %s;\n", $$.temp, $1.temp, $3.temp); 
                strcat(instrucoes, buf); 
            }
          | expressao '/' expressao { 
                if ($1.tipo_val != $3.tipo_val) {
                    if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                    else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                }
                $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                $$.temp = novo_temp($$.tipo_val); 
                sprintf(buf, "%s = %s / %s;\n", $$.temp, $1.temp, $3.temp); 
                strcat(instrucoes, buf); 
            }

          /* Relacionais */
          | expressao EQ expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s == %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao NE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s != %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao '>' expressao { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s > %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao '<' expressao { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s < %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao GE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao LE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }

          /* Lógicos */
          | expressao AND expressao { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s && %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao OR expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s || %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | NOT expressao           { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = !%s;\n", $$.temp, $2.temp); strcat(instrucoes, buf); }

          /* Casts Explícitos - Agora gerando a string diretamente aqui */
          | '(' TOKEN_INT ')' expressao %prec CAST { 
                $$.tipo_val = T_INT;   
                $$.temp = novo_temp(T_INT);
                sprintf(buf, "%s = (int) %s;\n", $$.temp, $4.temp);
                strcat(instrucoes, buf);
            }
          | '(' TOKEN_FLOAT ')' expressao %prec CAST { 
                $$.tipo_val = T_FLOAT; 
                $$.temp = novo_temp(T_FLOAT);
                sprintf(buf, "%s = (float) %s;\n", $$.temp, $4.temp);
                strcat(instrucoes, buf);
            }
          | '(' expressao ')' { $$ = $2; }
          ;

%%

int main() {
    yyparse();
    printf("Codigo Intermediario:\n");
    printf("%s\n%s", declaracoes, instrucoes);   
    return 0;
}