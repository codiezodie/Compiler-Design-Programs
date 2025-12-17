%{
#include <stdio.h>
%}

%%
(0|1)*      { printf("Matched: (0+1)*\n"); }
0*1*        { printf("Matched: 0*1*\n"); }
.|\n        { printf("Invalid character: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
int yywrap() { return 1; }
