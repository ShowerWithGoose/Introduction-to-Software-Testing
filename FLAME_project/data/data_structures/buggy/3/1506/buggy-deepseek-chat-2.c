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
        while (num[++i] == '0') // @@ [Error: The loop increments i before checking, so it skips the first digit after the decimal point. For input "0.00000009123456789012", it starts at index 2 (the first '0' after the decimal), missing the '.' at index 1. This causes incorrect counting of leading zeros and wrong starting position for the significant digit.]
            ++cnt;
        ++cnt;
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); // @@ [Error: Due to the incorrect loop, i points to the wrong digit. For the given input, i becomes 9 (pointing to '9'), but the correct first significant digit is at index 10 (the '9' after the leading zeros). This causes the output to start with '9' instead of '9' from the correct position, and the exponent is also off by one.]
            for (; i < strlen(num); i++) {
                printf("%c", num[i]); // @@ [Error: This prints from the wrong starting index, including the '9' at index 9 and then '1', '2', etc., but misses the correct sequence. The expected output should start with '9' at index 10, then '1', '2', etc.]
            }
            printf("e-%d", cnt); // @@ [Error: The exponent cnt is calculated incorrectly due to the loop error. For the input, cnt becomes 8, but the correct exponent should be -8 (since there are 8 zeros after the decimal point before the first non-zero digit). The buggy output shows e-8, which matches the expected exponent by coincidence, but the base is wrong.]
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.')
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