#include <stdio.h>
#include <string.h>

int main() {
    char regex[50];
    printf("Enter Regular Expression: ");
    scanf("%s", regex);

    FILE *fp = fopen("grammar.txt", "w");

    fprintf(fp, "S -> ");
    for (int i = 0; i < strlen(regex); i++) {
        if (regex[i] != '|') {
            fprintf(fp, "%cS | ", regex[i]);
        }
    }
    fprintf(fp, ε);

    fclose(fp);
    printf("Grammar written to grammar.txt\n");

    return 0;
}
