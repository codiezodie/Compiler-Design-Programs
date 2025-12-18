%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"return"|"if"|"else"|"while"|"for"   { printf("Keyword: %s\n", yytext); }
[0-9]+                                                    { printf("Number: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                                    { printf("Identifier: %s\n", yytext); }
"=="|"!="|">="|"<="|"="|"+"|"-"|"*"|"/"|"%"|"&&"|"||"      { printf("Operator: %s\n", yytext); }
[{}()\[\];,]                                              { printf("Symbol: %s\n", yytext); }
[ \t\n]                                                   { }
.                                                         { printf("Unknown: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
int yywrap() { return 1; }
