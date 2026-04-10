%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    int inteiro;
    float real;
    char* texto;
}

%token <texto> ID
%token <inteiro> NUM
%token INT FLOAT BOOL CHAR

%%

PROGRAMA:
    DECLARACOES
;

DECLARACOES:
    DECLARACOES DECL
  | DECL
;

DECL:
    TIPO ID ';' {
        printf("Declarou variável %s\n", $2);
    }
;

TIPO:
    INT   { printf("Tipo int\n"); }
  | FLOAT { printf("Tipo float\n"); }
  | BOOL  { printf("Tipo bool\n"); }
  | CHAR  { printf("Tipo char\n"); }
;

%%

void yyerror(const char *s) {
    printf("Erro: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}