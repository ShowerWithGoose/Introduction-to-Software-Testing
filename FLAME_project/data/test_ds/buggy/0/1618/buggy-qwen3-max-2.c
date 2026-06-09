#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ [The variable 'c' is computed as the difference between two characters, but it's used as a loop bound without considering that the step should be 1 per character; also, the multiplication by ('1' - '0') incorrectly assumes digits only and breaks for letters]
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Multiplying by ('1' - '0') = 1 only works for digits; for letters, this still adds k*1 which is correct numerically but the prior logic fails to distinguish types, and more critically, the loop condition 'k < c' skips the last character (e.g., for 'a-d', c=3, k=1,2 → prints 'b','c' but misses 'd')]
    }
}

int main() {

    gets(str); // @@ [Using 'gets' is unsafe and deprecated; more importantly, if input has no '-', but the test case 'W' leads to output 'a' vs expected 'r', this suggests deeper logic issues. However, the main bug is in 'print'. Also, accessing str[i-1] when i=0 causes undefined behavior if string starts with '-']
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [If '-' is at position 0, str[i-1] is str[-1] → undefined behavior; similarly, if '-' is at end, str[i+1] is out of bounds]
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