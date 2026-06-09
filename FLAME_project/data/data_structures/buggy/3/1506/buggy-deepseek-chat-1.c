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
        while (num[++i] == '0') // @@ [Error: The loop increments i before checking, so it skips the first digit after the decimal point. For input "0.00000009123456789012", it starts checking from index 2 (the first '0' after '.'), missing the '.' at index 1 and incorrectly counting zeros. This causes the exponent to be off by one and the first significant digit to be missed.]
            ++cnt;
        ++cnt;
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); // @@ [Error: Due to the incorrect loop, i points to the wrong digit. For the given input, i becomes 9 (the '9' after the zeros), but the first significant digit should be '9' at index 9, which is correct here, but the exponent cnt is miscalculated as 8 instead of 9, leading to the wrong output.]
            for (; i < strlen(num); i++) {
                printf("%c", num[i]);
            }
            printf("e-%d", cnt); // @@ [Error: The exponent cnt is incorrectly calculated. For input "0.00000009123456789012", the correct exponent should be -9 (since the number is 9.123456789012e-8), but the code outputs -8 due to the off-by-one error in counting zeros.]
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.') // @@ [Error: This loop increments i after checking, so when the loop exits, i is one past the decimal point. This causes cnt to be off by one for numbers with multiple digits before the decimal point.]
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
            printf("e%d", cnt); // @@ [Error: The exponent cnt is off by one due to the loop increment issue. For example, for input "12.34", cnt becomes 2 instead of 1, so the output would be "1.234e2" instead of "1.234e1".]
        }
    }
    
    return 0;
}