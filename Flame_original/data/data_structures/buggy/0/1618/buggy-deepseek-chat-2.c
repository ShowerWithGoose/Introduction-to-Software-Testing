#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ Error: The expression `k * ('1' - '0')` is incorrect. `'1' - '0'` equals 1, but this is not the correct way to increment characters. For digits, it might accidentally work, but for letters it fails because it doesn't account for the actual character values. The correct approach is to simply add `k` to `str[i-1]`, i.e., `str[i-1] + k`.
    }
}

int main() {

    gets(str); // @@ Error: `gets` is unsafe and deprecated; it can cause buffer overflow. The reference program uses `scanf("%s", s)`, which is safer. Also, `gets` does not check for the length of input.
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