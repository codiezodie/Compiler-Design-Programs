#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10], followSet[10][10];
int n, i, m;

void follow(int x, int y);
void first(int x, int y);

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter production %d: ", i);
        scanf("%s", prod[i]);
    }

    for (i = 1; i <= n; i++) {
        m = 0;
        follow(i, 0);
    }

    printf("\nFOLLOW Sets:\n");
    for (i = 1; i <= n; i++)
        printf("FOLLOW(%c) = %s\n", prod[i][0], followSet[i]);

    return 0;
}

void follow(int x, int y) {
    int u, v;

    if (prod[x][y] == prod[1][0])
        followSet[i][m++] = '$';

    for (u = 1; u <= n; u++) {
        for (v = 3; v < strlen(prod[u]); v++) {
            if (prod[u][v] == prod[x][y]) {
                if (islower(prod[u][v + 1]))
                    followSet[i][m++] = prod[u][v + 1];
                else if (isupper(prod[u][v + 1]))
                    first(u, v + 1);
            }
        }
    }
}

void first(int x, int y) {
    int u;
    for (u = 1; u <= n; u++) {
        if (prod[u][0] == prod[x][y]) {
            if (islower(prod[u][3]))
                followSet[i][m++] = prod[u][3];
            else
                first(u, 3);
        }
    }
}
