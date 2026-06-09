#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ [Accessing str[i-1] and str[i+1] without bounds check; may read invalid memory if i is at beginning or end]
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0'));
    }
}

int main() {

    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [Accessing str[i-1] and str[i+1] without checking bounds; crashes or undefined behavior if i==0 or i==strlen-1]
                if (str[i - 1] < str[i + 1]) { // @@ [Same bounds issue]
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ [Same bounds issue]
                if (str[i - 1] < str[i + 1]) { // @@ [Same bounds issue]
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ [Same bounds issue]
                if (str[i - 1] < str[i + 1]) { // @@ [Same bounds issue]
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