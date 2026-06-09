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
                    // Actually, the loop modifies `c[i-1]`. If input is B-F. c[i-1]='B', c[i+1]='F'.
                    // Iter 1: 'B' < 'F'. Print 'C'. c[i-1] becomes 'C'.
                    // Iter 2: 'C' < 'F'. Print 'D'. c[i-1] becomes 'D'.
                    // Iter 3: 'D' < 'F'. Print 'E'. c[i-1] becomes 'E'.
                    // Iter 4: 'E' < 'F'. Print 'F'. c[i-1] becomes 'F'.
                    // Loop ends.
                    // The main loop continues. The next character in string is 'F'. It prints 'F'.
                    // So output is BCDEFF. The error is that the loop includes the upper bound character in its output via `c[i-1]+1` when `c[i-1]` reaches `c[i+1]-1`.
                    // The standard expansion usually excludes the endpoints if they are already printed or handles them specifically.
                    // In the previous blocks, the condition was `c[i-1]+1 < c[i+1]`, which stops before printing the last char.
                    // Here, the condition is `c[i-1] < c[i+1]`. When `c[i-1]` is `E` (one less than `F`), it enters, prints `F`.
                    // Then `c[i-1]` becomes `F`. Loop terminates.
                    // Then the main loop processes the next char `c[i+1]` which is `F`? No, `i` is index of `-`. Next iteration `i` increments.
                    // Wait, the loop modifies `c[i-1]`. This is destructive to the original string buffer used for context?
                    // Regardless, the specific bug causing double 'F' is that this branch prints up to and including the end character, while the other branches do not. And the main loop will also print the character after '-' in the next iteration?
                    // Let's check the flow.
                    // Input: a-uB-F
                    // i points to first '-'. Expands a-u. Prints b..t. (Condition `c[i-1]+1 < c[i+1]` stops at t).
                    // Next i points to 'u'. Prints 'u'.
                    // Next i points to 'B'. Prints 'B'.
                    // Next i points to second '-'.
                    // Enters uppercase block.
                    // c[i-1] is 'B'. c[i+1] is 'F'.
                    // Loop:
                    // 1. B < F. Print C. c[i-1] becomes C.
                    // 2. C < F. Print D. c[i-1] becomes D.
                    // 3. D < F. Print E. c[i-1] becomes E.
                    // 4. E < F. Print F. c[i-1] becomes F.
                    // Loop ends.
                    // Next iteration of main loop: i increments. c[i] is now c[original_i+1].
                    // The character at original_i+1 is 'F'.
                    // So it prints 'F' again.
                    // Result: ...BCDEFF.
                    // The fix should be consistent with the other blocks: `c[i - 1] + 1 < c[i + 1]`.
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