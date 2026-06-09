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
        while (num[++i] == '0') // @@ The loop condition checks num[++i], which increments i before checking. If the string is "0.0...", i becomes 2 (skipping '.'). More importantly, this loop skips all zeros after the decimal point but fails to stop correctly at the first non-zero digit or handle the decimal point properly in the count logic.
            ++cnt;
        ++cnt; // @@ This increment attempts to account for the exponent adjustment but is incorrect because the previous loop's logic for finding the first significant digit and calculating the exponent is flawed.
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); // @@ num[i] is the first non-zero digit. This part is conceptually okay for printing the base, but the exponent 'cnt' calculated above is wrong.
            for (; i < strlen(num); i++) {
                printf("%c", num[i]); // @@ This loop prints the current digit (the first non-zero one) again, causing duplication. For input 0.0000000912..., if i points to '9', it prints "9." then enters loop printing "912...". Result: "9.912...". It should start printing from i+1.
            }
            printf("e-%d", cnt);
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