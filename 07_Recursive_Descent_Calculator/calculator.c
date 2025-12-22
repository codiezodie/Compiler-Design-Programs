#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *expr;

int expression();
int term();
int factor();

int factor() {
    if (isdigit(*expr)) {
        int num = 0;
        while (isdigit(*expr)) {
            num = num * 10 + (*expr - '0');
            expr++;
        }
        return num;
    }
    if (*expr == '(') {
        expr++;
        int result = expression();
        if (*expr == ')') expr++;
        return result;
    }
    return 0;
}

int term() {
    int result = factor();
    while (*expr == '*' || *expr == '/') {
        char op = *expr++;
        if (op == '*') result *= factor();
        else result /= factor();
    }
    return result;
}

int expression() {
    int result = term();
    while (*expr == '+' || *expr == '-') {
        char op = *expr++;
        if (op == '+') result += term();
        else result -= term();
    }
    return result;
}

int main() {
    char input[100];
    printf("Enter expression: ");
    scanf("%s", input);
    expr = input;
    printf("Result = %d\n", expression());
    return 0;
}
