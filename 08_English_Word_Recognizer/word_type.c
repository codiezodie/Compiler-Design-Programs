#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLower(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

int main() {
    char word[50];
    printf("Enter an English word: ");
    scanf("%s", word);
    toLower(word);

    int len = strlen(word);

    if (len >= 3 && strcmp(word + len - 3, "ing") == 0)
        printf("Verb (Present participle)\n");
    else if (len >= 2 && strcmp(word + len - 2, "ed") == 0)
        printf("Verb (Past tense)\n");
    else if (len >= 2 && strcmp(word + len - 2, "ly") == 0)
        printf("Adverb\n");
    else if (len >= 3 && strcmp(word + len - 3, "ous") == 0)
        printf("Adjective\n");
    else if (len >= 4 && strcmp(word + len - 4, "ness") == 0)
        printf("Noun\n");
    else
        printf("Unknown word type\n");

    return 0;
}
