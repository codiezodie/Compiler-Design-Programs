#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, i, m;
char prod[10][10], firstSet[10][10];

void first(int x, int y);
void removeDuplicates();

int main() {
    int j;
    printf("Enter number of productions (use @ for epsilon): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter production %d: ", i);
        scanf("%s", prod[i]);
    }

    for (i = 1; i <= n; i++) {
        m = 0;
        first(i, 0);
    }

    removeDuplicates();

    printf("\nFIRST Sets:\n");
    for (i = 1; i <= n; i++) {
        if (prod[i][0] != ' ') {
            printf("FIRST(%c) = { ", prod[i][0]);
            for (j = 0; j < strlen(firstSet[i]); j++)
                printf("%c ", firstSet[i][j]);
            printf("}\n");
        }
    }
    return 0;
}

void first(int x, int y) {
    int j;
    for (j = 1; j <= n; j++) {
        if (prod[j][0] == prod[x][y]) {
            if (!isupper(prod[j][3]) && prod[j][3] != '@') {
                firstSet[i][m++] = prod[j][3];
            } else if (prod[j][3] == '@') {
                firstSet[i][m++] = '@';
            } else {
                first(j, 3);
            }
        }
    }
}

void removeDuplicates() {
    int j, k;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < strlen(firstSet[i]); j++) {
            for (k = j + 1; k < strlen(firstSet[i]); k++) {
                if (firstSet[i][j] == firstSet[i][k])
                    firstSet[i][k] = ' ';
            }
        }
    }
}
