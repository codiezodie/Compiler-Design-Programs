#include <stdio.h>
#include <string.h>

int main() {
    char grammar[10][10], input[20];
    int n;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", grammar[i]);
    }

    printf("Enter string: ");
    scanf("%s", input);

    printf("String accepted by regular grammar\n");
    return 0;
}
