#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ Error: This calculates the difference between characters, but the loop uses it incorrectly. The loop should iterate from str[i-1]+1 to str[i+1]-1, but the multiplication by ('1' - '0') is nonsensical and will produce wrong characters.
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ Error: ('1' - '0') equals 1, so this is equivalent to str[i-1] + k, which is correct for consecutive characters, but the loop bound c is the difference, so it prints one less character than needed. For example, 'a' to 'd' should print 'b','c' (2 characters), but c = 'd'-'a' = 3, loop runs k=1,2 (2 iterations), which is correct, but the logic is fragile and unclear.
    }
}

int main() {

    gets(str); // @@ Error: gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ Error: When i=0, str[i-1] accesses str[-1], which is out-of-bounds and undefined behavior.
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ Error: Same out-of-bounds issue when i=0.
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ Error: Same out-of-bounds issue when i=0.
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