#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ potential out-of-bounds if i is at the beginning or end of the string, because str[i-1] or str[i+1] may be invalid.
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0'));
    }
}

int main() {

    gets(str); // unsafe function; may cause buffer overflow, but not a logical error in this context.
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ potential out-of-bounds when i == 0 or i == len-1
                if (str[i - 1] < str[i + 1]) { // @@ also accesses out-of-bounds if the previous condition was false due to bounds, but here it's already accessed.
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ potential out-of-bounds
                if (str[i - 1] < str[i + 1]) { // @@ potential out-of-bounds
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ potential out-of-bounds
                if (str[i - 1] < str[i + 1]) { // @@ potential out-of-bounds
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