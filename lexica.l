%{
#include "sintatica.tab.h"
#include <string.h>
%}

%%

"int"   { return INT; }
"float" { return FLOAT; }
"char"  { return CHAR; }
"bool"  { return BOOL; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.texto = strdup(yytext);
    return ID;
}

";" { return ';'; }

[ \t\n] ;

%%

int yywrap() {
    return 1;
}