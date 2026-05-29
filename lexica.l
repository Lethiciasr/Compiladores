%{
#include <string.h>
#include <stdlib.h>
#include "sin.tab.h" 
%}

%option noyywrap
%%

"if"        { return TOKEN_IF; }
"else"      { return TOKEN_ELSE; }
"while"     { return TOKEN_WHILE; }
"do"        { return TOKEN_DO; }
"for"       { return TOKEN_FOR; }
"break"     { return TOKEN_BREAK; }
"continue"  { return TOKEN_CONTINUE; }
"print"     { return TOKEN_PRINT; }
"read"      { return TOKEN_READ; }

"int"       { return TOKEN_INT; }
"float"     { return TOKEN_FLOAT; }
"char"      { return TOKEN_CHAR; }
"bool"      { return TOKEN_BOOL; }
"true"      { yylval.valor_str = strdup("true"); return BOOL_LIT; }
"false"     { yylval.valor_str = strdup("false"); return BOOL_LIT; }

"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }
"=="        { return EQ; }

"{"         { return '{'; }
"}"         { return '}'; }
";"         { return ';'; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"<"         { return '<'; }
">"         { return '>'; }

\"([^\"\\\\]|\\\\.)*\" { 
                yylval.valor_str = strdup(yytext); 
                return STRING_LIT; 
            }

[0-9]+\.[0-9]+ { 
                yylval.valor_str = strdup(yytext);
                return NUM_FLOAT; 
            }

[0-9]+      { 
                yylval.valor_str = strdup(yytext); 
                return NUM_INT; 
            }

'[a-zA-Z0-9]' { 
                yylval.valor_str = strdup(yytext); 
                return CHAR_LIT; 
            }

[a-zA-Z_][a-zA-Z0-9_]* { 
                yylval.valor_str = strdup(yytext); 
                return ID; 
            }

[ \t\r\n]+  { /* Ignora espaços em branco */ }

.           { return yytext[0]; }

%%