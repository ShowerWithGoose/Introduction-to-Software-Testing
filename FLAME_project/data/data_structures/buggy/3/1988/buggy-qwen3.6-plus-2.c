#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[10000];
int main() {
    scanf("%s", str);
    if(str[0] == '0'){
        int len = strlen(str), cnt1=0, cnt0=0;
        for(int i=2; i<len; i++){
            if(str[i]!='0'){
                cnt1++;
            }else{
                cnt0++;
            }
            if(cnt1 == 1){
                printf("%c", str[i]);
            }else if(cnt1 == 2){
                printf(".%c", str[i]);
            }else if(cnt1 > 1){
                printf("%c", str[i]);
            }
        }
        printf("e-%d", cnt0+1); // @@ The exponent calculation is incorrect. For input 0.00000009123456789012, the first non-zero digit '9' is at index 9 (0-indexed). The number of leading zeros after the decimal point before the first significant digit is 7 (indices 2 to 8 are '0'). So cnt0 becomes 7. The exponent should be -(cnt0 + 1) = -8. However, the loop counts zeros until the first non-zero digit is found. Let's trace: i=2 ('0') -> cnt0=1. i=3 ('0') -> cnt0=2. ... i=8 ('0') -> cnt0=7. i=9 ('9') -> cnt1=1. Loop continues but doesn't change cnt0. The formula cnt0+1 gives 8. The output is e-8. Wait, the buggy output says e-9. Let's re-read the code logic carefully.
        // Actually, let's look at the "Buggy Output" provided in the prompt: 9.123456789012e-9.
        // And Expected: 9.123456789012e-8.
        // The code prints `e-%d`, so it prints a negative sign.
        // If the code printed `e-9`, then `cnt0+1` must have evaluated to 9.
        // This implies `cnt0` was 8.
        // Input: 0.00000009123456789012
        // Indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'0', 5:'0', 6:'0', 7:'0', 8:'0', 9:'9'...
        // Loop starts at i=2.
        // i=2: '0' -> cnt0=1
        // i=3: '0' -> cnt0=2
        // i=4: '0' -> cnt0=3
        // i=5: '0' -> cnt0=4
        // i=6: '0' -> cnt0=5
        // i=7: '0' -> cnt0=6
        // i=8: '0' -> cnt0=7
        // i=9: '9' -> cnt1=1. First sig digit printed.
        // The loop continues to end of string. No more zeros are encountered before next non-zeros?
        // Wait, the `else` branch for `cnt0++` only executes if `str[i]=='0'`.
        // Once `cnt1 >= 1`, the `if/else if` chain handles printing, but the `if(str[i]!='0')` check for incrementing `cnt1` vs `cnt0` happens BEFORE the printing logic?
        // No, the structure is:
        // if(str[i]!='0') { cnt1++; } else { cnt0++; }
        // THEN printing logic.
        // So for i=9 ('9'), cnt1 becomes 1.
        // For i=10 ('1'), cnt1 becomes 2.
        // For i=11 ('2'), cnt1 becomes 3.
        // ...
        // cnt0 remains 7.
        // So `cnt0+1` is 8.
        // The code prints `e-8`.
        // Why does the prompt say Buggy Output is `e-9`?
        // Perhaps I am misinterpreting the input or the code provided in the "Source Code" section is different from the "Reference Program" section?
        // The prompt asks to identify errors in the program BELOW. The program below is the one starting with `#include <stdio.h>` ... `char str[10000];`.
        // The "Reference Program" is likely the correct implementation or a different buggy one? No, usually "Reference Program" means the correct one. But the reference program looks buggy too (it handles signs, but the problem says no sign).
        // Let's look at the Source Code provided for annotation again.
        // If the source code produces e-8, and expected is e-8, it would be correct.
        // But the prompt states: "Buggy Output: 9.123456789012e-9".
        // This implies the code provided IS producing e-9.
        // How can `cnt0+1` be 9? Only if `cnt0` is 8.
        // This would happen if there are 8 zeros after the decimal point before the first non-zero digit.
        // Input: 0.00000009123456789012
        // Digits after decimal: 0,0,0,0,0,0,0,9...
        // There are seven 0s.
        // Is it possible the input string has a different format? "0.00000009123456789012"
        // Maybe the code counts the '0' before the decimal? No, loop starts at i=2.
        // Maybe the logic for `cnt0` is flawed in a way I'm missing?
        // Ah, look at the condition: `if(str[i]!='0'){ cnt1++; } else { cnt0++; }`.
        // This counts ALL zeros in the rest of the string if they appear after non-zeros? No, `cnt0` increments for ANY zero.
        // But `cnt1` increments for ANY non-zero.
        // The exponent depends only on the position of the first non-zero digit.
        // The variable `cnt0` accumulates zeros throughout the entire remaining string?
        // Yes! `cnt0` is not reset. It counts every '0' character from index 2 to the end.
        // In "9123456789012", there is a '0' at the end (...89012).
        // So `cnt0` will be 7 (leading zeros) + 1 (trailing zero in mantissa) = 8.
        // Then `cnt0+1` = 9.
        // So it prints `e-9`.
        // The error is that `cnt0` should only count the leading zeros before the first significant digit, not all zeros in the string.
    }else if(str[1] == '.'){
        printf("%se0", str);
    }else{
        int i=0, len = strlen(str);
        while(str[i]!='.'){
            i++;
        }
        printf("%c.", str[0]);
        for(int j=1; j<len; j++){
            if(str[j]!='.'){
                printf("%c", str[j]);
            }
        }
        printf("e%d", i-1);
    }
    return 0;
}