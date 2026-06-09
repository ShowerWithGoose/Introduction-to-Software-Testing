#include <stdio.h>

int main() {
    char c[101];//
    gets(c);
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) {
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) {
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ The loop condition `c[i - 1] < c[i + 1]` combined with printing `c[i - 1] + 1` causes the last character (the end of the range) to be printed twice. For input B-F, it prints C, D, E, F inside the loop, and then the main loop prints F again because c[i-1] was modified to 'E' (wait, if it modifies c[i-1], let's trace carefully).
                    // Actually, the bug is simpler: The reference logic usually prints start+1 to end-1.
                    // Let's look at the first two blocks: `c[i-1]+1 < c[i+1]`. This prints up to `c[i+1]-1`.
                    // The third block uses `c[i-1] < c[i+1]`. This prints up to `c[i+1]`.
                    // Since the character `c[i+1]` (the end of the range) will be printed by the `else` branch or subsequent iteration if not handled, or specifically here, the loop modifies `c[i-1]`.
                    // Wait, the code modifies `c[i-1]` in the loop! This is destructive.
                    // However, the specific error requested is likely the off-by-one in the condition compared to the other branches or the double printing.
                    // In the first two branches, the loop runs while `start + 1 < end`. It prints `start + 1`. So it prints from `start+1` to `end-1`.
                    // In the third branch, the loop runs while `start < end`. It prints `start + 1`. So it prints from `start+1` to `end`.
                    // The character `end` (c[i+1]) is NOT skipped in the main loop automatically unless we skip it. The main loop continues. The next char is c[i+1].
                    // So if the loop prints `end`, and then the main loop processes c[i+1] (which is `end`), it prints it again.
                    // Thus, the condition should be `c[i - 1] + 1 < c[i + 1]` to match the other branches and avoid printing the last character twice.
                    printf("%c", c[i - 1] + 1);
                    }
                }
            } else {
                printf("%c", c[i]);
            }
        } else {
            printf("%c", c[i]);
        }
    }

    return 0;
}