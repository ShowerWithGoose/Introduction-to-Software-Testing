#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ The condition does not check if the start character is strictly less than the end character (s[i-1] < s[i+1]). Also, the logic structure using independent 'if's instead of 'else if' causes multiple blocks to potentially execute or fall through incorrectly. Specifically, if the first 'if' is true, it prints the expansion, but then falls through to the final 'else' attached only to the last 'if', printing a '-' unnecessarily if the last 'if' is false. More critically, the expansion loop uses `j < s[i+1]` which excludes the end character, whereas the problem implies inclusive expansion (a-d -> abcd).
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ The loop condition `j < s[i + 1]` excludes the last character. It should be `j <= s[i + 1]`. Also, the starting point `s[i - 1] + 1` is correct for excluding the start char if it was already printed, but the previous character `s[i-1]` is printed in the `else` block of the previous iteration or will be printed if we don't handle skipping. In this code structure, `s[i-1]` has already been printed by the `else` block in the previous iteration. So we start from `s[i-1]+1`. However, we must include `s[i+1]`.
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Same logical errors: missing `s[i-1] < s[i+1]` check, incorrect loop bound excluding end char, and flawed control flow with independent `if`s causing potential double output or incorrect '-' output.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Loop should be `j <= s[i + 1]` to include the end character.
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Same logical errors: missing `s[i-1] < s[i+1]` check, incorrect loop bound, and flawed control flow.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Loop should be `j <= s[i + 1]` to include the end character.
                    printf("%c", j);
            } else { // @@ This `else` is only associated with the `isdigit` check. If `islower` or `isupper` was true and executed, this `else` might still execute if `isdigit` is false, leading to an extra '-' being printed after a valid expansion. It should be part of an `else if` chain or handled with a flag.
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}