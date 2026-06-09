#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Incorrectly assumes all character types increment by ('1' - '0') = 1, which only works for digits; for letters, this adds 1 correctly but the multiplication is unnecessary and misleading. However, the real critical error is use of gets() which is unsafe and may cause compilation warnings or errors in modern compilers, and more importantly, the program fails to handle cases where '-' appears at the start or end of string, leading to out-of-bounds access (e.g., str[-1] or str[len]). But the immediate compilation error likely stems from using 'gets' which has been removed in C11 and later standards, causing a compilation failure if compiler enforces strict standard compliance.]
    }
}

int main() {

    gets(str); // @@ [Use of deprecated/removed function 'gets' which is unsafe and causes compilation error in modern C standards (e.g., C11+). Should be replaced with fgets or similar.]
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