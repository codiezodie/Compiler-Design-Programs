#include <stdio.h>
#include <string.h>

int main() {
    char prod[50];
    printf("Enter production (A->Aa|b): ");
    scanf("%s", prod);

    char lhs = prod[0];
    char *rhs = prod + 3;
    char *token = strtok(rhs, "|");

    while (token) {
        if (token[0] == lhs) {
            printf("Left Recursion Present\n");
            return 0;
        }
        token = strtok(NULL, "|");
    }
    printf("No Left Recursion\n");
    return 0;
}
