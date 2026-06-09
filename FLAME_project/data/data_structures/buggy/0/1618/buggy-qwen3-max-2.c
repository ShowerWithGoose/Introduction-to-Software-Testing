#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ [This computes the difference in ASCII values, but the loop below incorrectly assumes digit-like step using ('1' - '0') which is 1, but for letters this causes wrong output; also, it prints only intermediate characters, not including the endpoints, and uses a fixed step of 1 which is okay, but the multiplication by ('1'-'0') is misleading and unnecessary. However, the main issue is that the function does not handle different character types correctly and skips printing the surrounding characters which are printed elsewhere, but the logic of expansion is flawed.]
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Multiplying by ('1' - '0') equals 1, so it's effectively adding k, which is correct for consecutive characters, but the expression is confusing and error-prone. More critically, this only prints the characters between the two ends, assuming the caller prints the rest, but the main loop prints non-'-' characters directly, so the endpoints are printed twice or inconsistently. Also, if c <= 1, the loop doesn't run, but the condition in main ensures str[i-1] < str[i+1], so c >= 2, but still the expansion logic is misaligned with requirements.]
    }
}

int main() {

    gets(str); // @@ [Using gets() is unsafe and deprecated; more importantly, the reference program uses scanf("%s", str), which reads until whitespace, while gets() reads entire line including spaces. But the bigger issue is potential buffer overflow and undefined behavior. However, the immediate bug causing wrong output is elsewhere.]
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [Accessing str[i - 1] when i=0 leads to out-of-bounds read (undefined behavior). Similarly, accessing str[i + 1] when i is last index is also out-of-bounds. This causes crashes or wrong behavior on edge cases like string starting or ending with '-'.]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ [Same out-of-bounds access issue as above.]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ [Same out-of-bounds access issue as above.]
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