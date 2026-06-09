#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ [This computes the difference between characters, but the loop below incorrectly uses ('1' - '0') which equals 1 only for digits; it fails for letters because it assumes step size of 1 in ASCII but applies digit-based scaling]
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Using ('1' - '0') = 1 is coincidentally correct numerically, but conceptually wrong and misleading; however, the real issue is that the loop runs from k=1 to k<c, which skips the last character. For example, expanding a-d should include 'd', but this prints only b and c. Also, if c <= 1 (e.g., adjacent chars like a-b), loop doesn't run, missing output entirely.]
    }
}

int main() {

    gets(str); // @@ [Use of gets() is unsafe and deprecated; more critically, if input has leading '-', str[i-1] becomes str[-1] which is out-of-bounds. Similarly, trailing '-' leads to str[i+1] being out-of-bounds. The code does not check bounds before accessing str[i-1] or str[i+1].]
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [Accesses str[i-1] and str[i+1] without checking if i > 0 or i < strlen(str)-1, leading to undefined behavior on strings starting or ending with '-']
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-"); // @@ [When expansion condition fails (e.g., d-a), it prints '-', but according to problem, the entire original segment should be output unchanged. However, the non-expansion case already prints '-' here, but the surrounding characters are printed separately in the else clause, causing duplication or misordering. More critically, the logic doesn't handle sequences like a-b-c properly.]
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ [Same out-of-bounds access issue as above]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ [Same out-of-bounds access issue]
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