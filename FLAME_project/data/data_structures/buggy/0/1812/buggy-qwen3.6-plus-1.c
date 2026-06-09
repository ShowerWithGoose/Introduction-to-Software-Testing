#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ The logic for handling characters and expansion is flawed. It prints characters immediately upon encountering them, but if a subsequent '-' triggers an expansion, the previously printed character (the start of the range) has already been output, and the expansion logic modifies the string buffer which might not be reflected in output correctly or leads to double printing/missing characters. Specifically, for 'B-F', 'B' is printed by this line. Then when '-' is processed, it expands to CDE. Then 'F' is printed by the next iteration. However, the expansion logic here modifies the string `s` in place while iterating over it, which is dangerous and incorrect because `strlen(s)` changes and indices shift. The reference approach of printing directly without modifying the source string during iteration is safer. But looking closely at the specific error: Input `a-uB-F`. Output `acdefghijklmnopqrstuBDEF`. Expected `abcdefghijklmnopqrstuBCDEF`.
        // The issue is that the code prints characters *before* knowing if they are part of an expansion range that needs special handling, OR it handles expansion by modifying the array but continues iterating incorrectly.
        // Let's trace `B-F`.
        // i points to 'B'. Prints 'B'.
        // i points to '-'. Checks condition. True. Expands in-place. String becomes something like `...B[CDEF]F...`.
        // The loop continues. The indices have shifted.
        // Actually, the main bug is that standard characters are printed unconditionally before checking if they are part of a valid expansion sequence that should replace the hyphen logic.
        // Wait, the problem says "expand a-d to abcd". This implies 'a' and 'd' are also part of the output.
        // In the provided buggy code:
        // 1. It prints 'a'.
        // 2. It sees '-', expands 'b'..'t' into the string.
        // 3. It continues.
        // The specific failure is `B-F` -> `BDEF` instead of `BCDEF`.
        // The code prints 'B' immediately.
        // Then it processes '-'. It calculates n = 'F' - 'B' - 2 = 4.
        // It shifts the rest of the string.
        // It inserts 'C', 'D', 'E' into the string.
        // The character 'F' is still in the string later.
        // When the loop reaches 'F', it prints 'F'.
        // So we get B (printed) + CDE (inserted and presumably printed? No, the insertion just modifies `s`. The loop continues based on index `i`).
        // The loop index `i` increments. The inserted characters are in `s`, but `i` moves past them or skips them depending on how `strlen` and shifting worked.
        // Actually, if `s` is modified in place, the `for` loop condition `s[i]!='\0'` uses the new length.
        // However, the inserted characters `C`, `D`, `E` are placed in `s`. Does the loop print them?
        // The loop only prints if `s[i]` is alpha/digit.
        // If the insertion works correctly, `s` contains `...B C D E F...`.
        // `i` was at `-`. After processing, `i` increments.
        // The next char in `s` at `i+1` is now `C` (due to shift/insert).
        // So it should print `C`, `D`, `E`.
        // Why did it output `BDEF`? Missing `C`.
        // Let's look at the insertion loop:
        // `n = 4`. `j` starts at end. Shifts right by 4.
        // `m = i` (index of `-`).
        // `c` starts at `B+1 = C`.
        // `s[m] = C`. `m` becomes `i+1`. `c` becomes `D`.
        // `s[m] = D`. `m` becomes `i+2`. `c` becomes `E`.
        // `s[m] = E`. `m` becomes `i+3`. `c` becomes `F`.
        // Loop condition `m <= i + n + 1` => `i+3 <= i+5`. True.
        // `s[m] = F`. `m` becomes `i+4`. `c` becomes `G`.
        // Loop condition `i+4 <= i+5`. True.
        // `s[m] = G`. ...
        // The insertion loop overwrites the original `F` and subsequent characters incorrectly or extends too far.
        // The range to fill is `i` to `i+n`. The original `s[i+1]` (which is `F`) should remain at `i+n+1`?
        // No, the expansion of `B-F` is `BCDEF`. The `-` is replaced by `CDE`. `B` and `F` stay.
        // So `s[i]` (`-`) should become `C`? No, `B` is at `i-1`. `-` is at `i`. `F` is at `i+1`.
        // We want `B C D E F`.
        // `s[i-1]` is `B`.
        // `s[i]` should become `C`.
        // `s[i+1]` should become `D`.
        // `s[i+2]` should become `E`.
        // `s[i+3]` should become `F` (originally at `i+1`, shifted to `i+3`? No, `F` is the end char, it stays as the end char).
        // Actually, usually expansion means `a-d` -> `abcd`. The `-` is removed/replaced.
        // If we replace `-` with `bcd`, then `a` is before, `d` is after.
        // Here `B-F`. `B` is before. `F` is after.
        // We need to insert `CDE` between `B` and `F`.
        // So `s[i]` (was `-`) becomes `C`.
        // `s[i+1]` (was `F`) needs to shift to `i+3`.
        // And `s[i+1]` becomes `D`, `s[i+2]` becomes `E`.
        // The current code sets `s[m]` starting at `i`.
        // It writes `C` at `i`.
        // It writes `D` at `i+1`.
        // It writes `E` at `i+2`.
        // It writes `F` at `i+3`.
        // It writes `G` at `i+4`.
        // This overwrites the original `F` at `i+1` (shifted) and corrupts data.
        // The loop bound `m <= i + n + 1` is wrong. It should stop before overwriting the end character `F` if `F` is supposed to be preserved from the input?
        // Wait, if `F` is preserved, it should be at `i + n + 1`?
        // `n = 2` (count of chars between B and F? `F-B-2 = 70-66-2 = 2`? No. `C,D,E` is 3 chars. `F-B-1 = 3`. `F-B-2 = 2`.
        // `n` calculation: `s[i+1] - s[i-1] - 2`. `70 - 66 - 2 = 2`.
        // But there are 3 chars to insert: C, D, E.
        // So `n` is incorrect. It should be `s[i+1] - s[i-1] - 1`.
        
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]);
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ Incorrect calculation of number of characters to insert. For 'B' and 'F', difference is 4. Characters between are C, D, E (3 chars). Formula gives 4-2=2. Should be `s[i+1] - s[i-1] - 1`.
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ Loop bound and logic are incorrect due to wrong `n` and overwriting the end character.
                s[m] = c;
            }
        }
    }
    return 0;
}