%{
#include <stdio.h>
%}

%%
ab*c*d         { printf("Matched: ab*c*d\n"); }
([ab]*[cd]*)+  { printf("Matched: ((a+b)*(c+d)*)+\n"); }
.|\n           { printf("Invalid character: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
int yywrap() { return 1; }
