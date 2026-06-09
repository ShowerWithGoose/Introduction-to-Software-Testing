#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ The calculation for the character increment is incorrect. It uses ('1' - '0') which equals 1, but this logic is fragile and confusing. More importantly, it fails to handle the case where the range is just 1 character difference correctly or misses the end character depending on loop bounds. However, the primary issue in the provided test case "W" vs "r" suggests a completely different input/output mismatch or logic error in how single characters or non-expansion cases are handled, but looking at the specific bug: if input is "a-c", c='c'-'a'=2. k=1. prints 'a'+1 = 'b'. It misses 'c'. The loop should be k <= c or similar, and the step is just 1. The multiplier is unnecessary and potentially wrong if types were mixed (though they are checked). The main logical error here is that it doesn't print the last character of the expansion.
    }
}

int main() {

    gets(str);
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