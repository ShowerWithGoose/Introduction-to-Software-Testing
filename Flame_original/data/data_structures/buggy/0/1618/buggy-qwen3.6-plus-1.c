#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) { // @@ Compilation error: parameter name is missing in function definition.
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ Semantic error: ('1' - '0') evaluates to 1, making the multiplication redundant and confusing.
    }
}

int main() {

    gets(str); // @@ Compilation/Security error: gets() is deprecated and removed in C11 due to buffer overflow risks; use fgets() instead.
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ Logical error: potential out-of-bounds access when i=0 (str[-1]) or i is at the last index.
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