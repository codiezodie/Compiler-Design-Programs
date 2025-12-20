#include <stdio.h>
#include <string.h>

int main() {
    char prod[50], alpha[50] = "", beta[50] = "";
    printf("Enter production (A->Aa|b): ");
    scanf("%s", prod);

    char lhs = prod[0];
    char *rhs = prod + 3;
    char *token = strtok(rhs, "|");

    while (token) {
        if (token[0] == lhs)
            strcat(alpha, token + 1), strcat(alpha, "|");
        else
            strcat(beta, token), strcat(beta, "|");
        token = strtok(NULL, "|");
    }

    alpha[strlen(alpha) - 1] = '\0';
    beta[strlen(beta) - 1] = '\0';

    printf("%c -> %s%c'\n", lhs, beta, lhs);
    printf("%c' -> %s | ε\n", lhs, alpha);

    return 0;
}
