#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num);
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0') @@ // The loop condition skips the '.' and starts checking from index 2, but the first character after '0.' is at index 2 only if input is "0.x..."; however, ++i in condition skips index 1 (which is '.') and then checks index 2 onward. But if the input is "0.000...", then index 1 is '.', and we should start scanning from index 2. However, the logic of incrementing `i` inside the condition causes it to skip the correct first non-zero digit. Also, `cnt` counts zeros incorrectly because it increments once before even checking.
            ++cnt;
        ++cnt; @@ // This extra increment leads to an off-by-one error in exponent calculation. For "0.00000009...", there are 7 zeros after decimal before '9', so exponent should be -8, but this makes it -8 due to double counting? Actually, combined with the loop, it overcounts.
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); @@ // This prints the first significant digit correctly, but the following loop starts from current `i`, which is already at the first non-zero digit, so it prints that digit again in the fractional part, causing duplication (e.g., "9.9123..." instead of "9.123...").
            for (; i < strlen(num); i++) { @@ // Loop starts at `i` which points to first non-zero digit, so it prints that digit again after the decimal point, duplicating it.
                printf("%c", num[i]);
            }
            printf("e-%d", cnt);
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.') @@ // This loop increments `i` after checking, so when '.' is found, `i` is one past the '.'. But `cnt` counts the number of digits before '.', which is correct only if we stop before incrementing on '.'. However, the logic may miscount if the number has no decimal point (though problem says it does). Also, if input has no decimal, this loops beyond string.
            ++cnt;
        if (cnt == 0) {
            printf("%s", num);
            printf("e%d", cnt);
        }
        else {
            printf("%c.", num[0]);
            for (i = 1; i < strlen(num); i++) {
                if (num[i] != '.')
                    printf("%c", num[i]);
            }
            printf("e%d", cnt);
        }
    }
    
    return 0;
}