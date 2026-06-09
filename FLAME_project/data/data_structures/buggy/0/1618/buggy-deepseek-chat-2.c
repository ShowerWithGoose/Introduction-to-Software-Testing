#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ Error: This calculates the difference between ASCII values, but the loop uses '1' - '0' which is 1, so it prints characters from str[i-1]+1 to str[i+1]-1, but the multiplication by ('1'-'0') is unnecessary and confusing; also the function does not print the starting character str[i-1] and the ending character str[i+1], which should be printed by the main function, but the main function prints str[i] (the '-') instead of handling the expansion correctly.
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ Error: The multiplication by ('1' - '0') is redundant and incorrect; it should just be str[i-1] + k. Also, the loop condition k < c means it prints c-1 characters, but it should print all characters between str[i-1] and str[i+1] inclusive, which would be c+1 characters total, but the main function prints the endpoints separately, so this loop should print c-1 characters, which is correct, but the calculation of c is off by one.
    }
}

int main() {

    gets(str);
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