#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not standard C. Use fgets() instead.]
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0') // @@ [This loop increments i before checking, so it skips the first character after the decimal point. Also, it does not check for the decimal point '.' before the zeros, leading to incorrect handling of numbers like "0.001".]
            ++cnt;
        ++cnt;
        if(i == strlen(num) - 1) // @@ [If the loop exits because num[i] is not '0', i may be out of bounds or not point to the last character; this condition is incorrect for determining if there is only one significant digit.]
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); // @@ [This prints the first non-zero digit, but the loop above may have skipped the decimal point, so num[i] might be the decimal point or another character.]
            for (; i < strlen(num); i++) {
                printf("%c", num[i]); // @@ [This prints all remaining characters including the decimal point, which should be omitted in scientific notation.]
            }
            printf("e-%d", cnt);
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.') // @@ [This increments i after checking, so after the loop, i is one past the decimal point position, causing cnt to be off by one.]
            ++cnt;
        if (cnt == 0) {
            printf("%s", num); // @@ [For numbers with no decimal point (e.g., "123"), this prints the whole number, but scientific notation requires a single digit before the decimal point.]
            printf("e%d", cnt);
        }
        else {
            printf("%c.", num[0]);
            for (i = 1; i < strlen(num); i++) {
                if (num[i] != '.')
                    printf("%c", num[i]); // @@ [This prints all digits after the decimal point, but does not handle the case where the number has no decimal point or has trailing zeros incorrectly.]
            }
            printf("e%d", cnt); // @@ [The exponent cnt is calculated incorrectly due to the off-by-one error in the while loop.]
        }
    }
    
    return 0;
}