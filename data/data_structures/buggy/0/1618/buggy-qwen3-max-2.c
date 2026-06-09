#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Incorrectly assumes digit expansion logic applies to letters; '1'-'0' equals 1, but this is misleading and unnecessary. More critically, it works numerically for digits but coincidentally for letters due to ASCII, yet the multiplication is redundant and confusing. However, the real critical error is using gets() which is unsafe and may be undefined in modern compilers, causing compilation failure.]
    }
}

int main() {

    gets(str); // @@ [Use of deprecated and unsafe function 'gets()' which has been removed from C11 standard; many compilers no longer support it, leading to a compilation error.]

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