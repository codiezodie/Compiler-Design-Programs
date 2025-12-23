#include <stdio.h>
#include <string.h>

char input[50];
int pos = 0;

int A(), B(), C();

int match(char ch) {
    if (input[pos] == ch) {
        pos++;
        return 1;
    }
    return 0;
}

int A() {
    if (match('a') && match('b')) {
        while (input[pos] == 'a' && input[pos+1] == 'b') {
            match('a'); match('b');
        }
        return 1;
    }
    return 0;
}

int B() {
    if (match('b')) {
        while (input[pos] == 'b')
            match('b');
        return 1;
    }
    return 0;
}

int C() {
    if (match('c')) {
        while (input[pos] == 'c')
            match('c');
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter string: ");
    scanf("%s", input);

    if (A() && B() && C() && input[pos] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
