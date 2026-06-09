#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ The logic for handling characters and expansion is flawed. It prints characters immediately upon encountering them, but if a subsequent '-' triggers an expansion, the previously printed character (the start of the range) has already been output, and the expansion logic modifies the string buffer which might not be reflected in output correctly or leads to double printing/missing characters. Specifically, for 'B-F', 'B' is printed by this line. Then when '-' is processed, it expands to CDE. Then 'F' is printed by the next iteration. However, the expansion logic here modifies the string `s` in place while iterating over it, which is extremely error-prone and incorrect because `strlen(s)` changes and indices shift. The reference approach of printing directly is safer. But looking at the specific failure: Input `a-uB-F`. Output `acdefghijklmnopqrstuBDEF`. Expected `abcdefghijklmnopqrstuBCDEF`.
        // The issue is that the code prints characters *before* knowing if they are part of an expansion range start.
        // For `a-u`: 'a' is printed. Then `-` is found. Expansion `bc...t` is printed? No, the code modifies `s`.
        // Let's trace `a-u`.
        // i=0: 'a' is lower. Prints 'a'.
        // i=1: '-'. Checks neighbors 'a' and 'u'. Both lower. 'a' < 'u'.
        // n = 'u' - 'a' - 2 = 20 - 2 = 18.
        // j = strlen(s). Shifts rest of string right by 18.
        // Fills s[1] to s[1+18+1] with 'b'...'t'.
        // So far so good for the first part.
        // Now the string is much longer.
        // i=2: s[2] is 'b'. Prints 'b'.
        // ...
        // i=20: s[20] is 't'. Prints 't'.
        // i=21: s[21] is 'u'. Prints 'u'.
        // i=22: s[22] is 'B'. Prints 'B'.
        // i=23: s[23] is '-'. Neighbors 'B' and 'F'. Both upper. 'B' < 'F'.
        // n = 'F' - 'B' - 2 = 4.
        // Shifts rest of string right by 4.
        // Fills s[23]... with 'C','D','E'.
        // i=24: s[24] is 'C'. Prints 'C'.
        // i=25: s[25] is 'D'. Prints 'D'.
        // i=26: s[26] is 'E'. Prints 'E'.
        // i=27: s[27] is 'F'. Prints 'F'.
        // Wait, the buggy output is `acdefghijklmnopqrstuBDEF`.
        // Where did 'b' go? And why is 'a' followed by 'c'?
        // Ah, look at the first expansion loop:
        // int m = i; // m = 1
        // for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) {
        //    s[m] = c;
        // }
        // s[1] becomes 'b'.
        // But 'a' was already printed at i=0.
        // Then at i=1, we modified s[1] to 'b'.
        // At i=2, we print s[2] which is 'c'.
        // So 'b' is printed at i=2? No, s[2] was originally 'u' or shifted?
        // The shifting happens BEFORE filling.
        // Original: a - u B - F \0
        // i=1. n=18.
        // Shift s[2..end] to s[20..end+18].
        // s[2] becomes whatever was at s[2-18]? No, loop is j >= i+1.
        // for (; j >= i + 1; j--) { s[j + n] = s[j]; }
        // This shifts characters to the right.
        // Then fills s[1] to s[19] with b..t.
        // So s[1]='b', s[2]='c', ..., s[19]='t'.
        // s[20] is 'u' (shifted from original s[2]).
        // Loop continues.
        // i=2. s[2] is 'c'. Prints 'c'.
        // So 'b' is NEVER printed because i=1 was the '-' case, which didn't print 'b', it inserted it into the string.
        // The loop increments i to 2. So s[1] ('b') is skipped!
        // That explains why 'b' is missing.
        // Similarly for the second expansion.
        // 'B' is printed at i=22 (assuming indices shifted).
        // Then '-' at i=23. Expands to C,D,E.
        // Inserts C,D,E into s[23], s[24], s[25].
        // Original 'F' is shifted to s[26].
        // Loop increments i to 24.
        // s[23] ('C') is SKIPPED.
        // s[24] ('D') is printed.
        // s[25] ('E') is printed.
        // s[26] ('F') is printed.
        // So 'C' is missing.
        // This matches the buggy output: `a` (printed) `c...t` (b skipped) `u` `B` (printed) `D` `E` `F` (C skipped).
        // Wait, the buggy output is `acdefghijklmnopqrstuBDEF`.
        // My analysis: `a` printed. `b` skipped. `c` printed. ... `t` printed. `u` printed. `B` printed. `C` skipped. `D` printed. `E` printed. `F` printed.
        // Result: `acdefghijklmnopqrstuBDEF`.
        // This matches exactly.
        // The error is that after expanding, the index `i` is incremented by the for loop, skipping the first character of the newly inserted expansion sequence.
        // To fix this, one should not use this complex in-place modification with a forward iterator, or adjust `i` to point to the last inserted character so the next increment points to the first valid new character? No, if we set `i` to `m-1` (last inserted), then `i++` makes it point to `m` (first char after expansion? No).
        // Actually, the simplest fix for this specific "print as you go" logic broken by insertion is to avoid printing characters that might be start of ranges until sure, OR use the reference solution's approach.
        // However, I must annotate the error location.
        // The fundamental logical error is in the structure: printing characters before checking if they are part of an expansion that shifts them or skips them.
        // But specifically, the skipping happens because `i` advances past the inserted characters.
        // The line `for (int i = 0; s[i]!='\0'; i++)` combined with the insertion logic causes the skip.
        // I will mark the line where the expansion logic ends or the loop increment implicitly causes the skip.
        // Actually, the most direct cause is that the code does not account for the fact that `s[i]` (the '-') is replaced/expanded, but the loop moves to `i+1`, skipping the first new character.
        
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]);
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2;
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) {
                s[m] = c;
            }
            // @@ After inserting characters into the string, the loop's i++ will skip the first inserted character (at index i). The index i should be adjusted to compensate, e.g., i += n; or similar, but since the structure is fixed, this logic is fundamentally flawed for a forward scanning loop that prints immediately.
        }
    }
    return 0;
}