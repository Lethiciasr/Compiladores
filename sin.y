%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }
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

/* Precedência para resolver o Syntax Error em expressões complexas */
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

comando : declaracao ';' | atribuicao ';' ;

declaracao : TOKEN_INT ID    { inserir($2, T_INT); }
           | TOKEN_FLOAT ID  { inserir($2, T_FLOAT); }
           | TOKEN_CHAR ID   { inserir($2, T_CHAR); }
           | TOKEN_BOOL ID   { inserir($2, T_BOOL); };

atribuicao : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) printf("Erro: Variável %s não declarada.\n", $1);
    else printf("%s = %s; // Atribuicao para %s\n", s->temp, $3.temp, $1);
};

expressao : NUM_INT { 
                $$.temp = novo_temp(); $$.tipo_val = T_INT;
                printf("%s = %s;\n", $$.temp, $1); 
            }
          | NUM_FLOAT { 
                $$.temp = novo_temp(); $$.tipo_val = T_FLOAT;
                printf("%s = %s;\n", $$.temp, $1); 
            }
          | CHAR_LIT { 
                $$.temp = novo_temp(); $$.tipo_val = T_CHAR;
                printf("%s = %s;\n", $$.temp, $1); 
            }
          | BOOL_LIT { 
                $$.temp = novo_temp(); $$.tipo_val = T_BOOL;
                printf("%s = %s;\n", $$.temp, $1); 
            }
          | ID {
                Simbolo *s = buscar($1);
                if(s) { $$.temp = s->temp; $$.tipo_val = s->tipo; }
                else { yyerror("Var não declarada"); }
            }
          /* Aritmética */
          | expressao PLUS expressao { $$.temp = novo_temp(); printf("%s = %s + %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao '-' expressao  { $$.temp = novo_temp(); printf("%s = %s - %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao '*' expressao  { $$.temp = novo_temp(); printf("%s = %s * %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao '/' expressao  { $$.temp = novo_temp(); printf("%s = %s / %s;\n", $$.temp, $1.temp, $3.temp); }
          /* Relacionais (Onde estava dando o erro) */
          | expressao EQ expressao  { $$.temp = novo_temp(); printf("%s = %s == %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao NE expressao  { $$.temp = novo_temp(); printf("%s = %s != %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao '>' expressao  { $$.temp = novo_temp(); printf("%s = %s > %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao '<' expressao  { $$.temp = novo_temp(); printf("%s = %s < %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao GE expressao  { $$.temp = novo_temp(); printf("%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao LE expressao  { $$.temp = novo_temp(); printf("%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp); }
          /* Lógicos */
          | expressao AND expressao { $$.temp = novo_temp(); printf("%s = %s && %s;\n", $$.temp, $1.temp, $3.temp); }
          | expressao OR expressao  { $$.temp = novo_temp(); printf("%s = %s || %s;\n", $$.temp, $1.temp, $3.temp); }
          /* Casts e Parênteses */
          | '(' TOKEN_INT ')' expressao %prec CAST { $$.temp = novo_temp(); printf("%s = (int)%s;\n", $$.temp, $4.temp); }
          | '(' TOKEN_FLOAT ')' expressao %prec CAST { $$.temp = novo_temp(); printf("%s = (float)%s;\n", $$.temp, $4.temp); }
          | '(' expressao ')' { $$ = $2; }
          ;

%%

int main() {
    yyparse();
    return 0;
}