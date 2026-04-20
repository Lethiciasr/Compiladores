%{
#include <string.h>
#include <stdlib.h>
#include "sin.tab.h" /* Certifique-se que o nome do arquivo .h gerado pelo Bison é este */
%}

%option noyywrap

%%

"int"       { return TOKEN_INT; }
"float"     { return TOKEN_FLOAT; }
"char"      { return TOKEN_CHAR; }
"bool"      { return TOKEN_BOOL; }
"true"      { yylval.valor_str = strdup("1"); return BOOL_LIT; }
"false"     { yylval.valor_str = strdup("0"); return BOOL_LIT; }

"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }
"<"         { return '<'; }
">"         { return '>'; }
"=="        { return EQ; }

[0-9]+      { 
                yylval.valor_str = strdup(yytext); 
                return NUM_INT; 
            }

[a-zA-Z_][a-zA-Z0-9_]* { 
                yylval.valor_str = strdup(yytext); 
                return ID; 
            }

[0-9]+\.[0-9]+ { 
                yylval.valor_str = strdup(yytext);
                return NUM_FLOAT; 
                }

'[a-zA-Z0-9]' { yylval.valor_str = strdup(yytext); return CHAR_LIT; }

"="         { return ASSIGN; }
"+"         { return PLUS; }
";"         { return ';'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }

[ \t\n]+    { /* Ignora espaços, tabs e quebras de linha */ }

.           { return yytext[0]; }

%%