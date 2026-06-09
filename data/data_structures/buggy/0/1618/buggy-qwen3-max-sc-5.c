#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Incorrect expansion logic: multiplying by ('1' - '0') which is 1 only works for digits, but this function is also used for letters. For letters, it should just add k without scaling.]
    }
}

int main() {

    gets(str); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also may lead to compilation error/warning in modern compilers. Should use fgets instead.]
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