%{
#include <stdio.h>
%}

%%
ab*c        { printf("Matched: ab*c\n"); }
(def)+      { printf("Matched: (def)+\n"); }
a*d+e       { printf("Matched: a*d+e\n"); }
.|\n        { printf("Invalid character: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
int yywrap() { return 1; }
