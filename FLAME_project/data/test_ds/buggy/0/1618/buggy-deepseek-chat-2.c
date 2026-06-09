#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ Error: This calculates the difference in ASCII values, but the loop uses it incorrectly. The loop should iterate from str[i-1]+1 to str[i+1]-1, not use a count based on ASCII difference multiplied by ('1'-'0').
    for (int k = 1; k < c; k++) { // @@ Error: The loop condition and increment are wrong. It should iterate from the character after str[i-1] to the character before str[i+1], printing each character.
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ Error: Multiplying by ('1'-'0') which is 1 is unnecessary but not the main issue. The main issue is that the loop does not correctly print the range of characters.
    }
}

int main() {

    gets(str); // @@ Error: gets() is unsafe and deprecated. It can cause buffer overflow. Use fgets() instead.
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else {
                printf("-");
            }
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}