#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) { // @@ [Missing parameter name; should be something like 'char str[]' to use the array. Also, the function uses global variable 'str', which is confusing but works.]
    int c = str[i + 1] - str[i - 1]; // @@ [Potential out-of-bounds access: when i is 0 or at the end of the string, str[i-1] or str[i+1] may access invalid memory.]
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0'));
    }
}

int main() {

    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [Out-of-bounds access when i is 0 or i is the last index. Also similar in the following else-if branches.]
                if (str[i - 1] < str[i + 1]) { // @@ [Same out-of-bounds issue.]
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ [Out-of-bounds access.]
                if (str[i - 1] < str[i + 1]) { // @@ [Out-of-bounds access.]
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ [Out-of-bounds access.]
                if (str[i - 1] < str[i + 1]) { // @@ [Out-of-bounds access.]
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