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
        while (num[++i] == '0') // @@ The loop condition checks num[++i], which increments i before checking. If the string is "0.0...", i becomes 2 (checking '.'). If it is "0.00...", it skips zeros. However, the logic for finding the first significant digit is flawed because it doesn't stop at the decimal point explicitly in the condition, relying on '0' check. More critically, the subsequent printing logic is wrong.
            ++cnt;
        ++cnt;
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]);
            for (; i < strlen(num); i++) { // @@ The loop starts from the current value of i (the first significant digit) and prints ALL remaining characters including the current one again if not handled, but here it prints num[i] which is the significant digit, then increments. Wait, the previous line printed num[i] and a dot. This loop should print the REST of the digits. However, the loop condition `i < strlen(num)` and body `printf("%c", num[i])` will print the digit at `i` again? No, `i` was used in `printf("%c.", num[i])`. Then the loop starts with that same `i`. So it prints the significant digit AGAIN. For input 0.0000000912..., i points to '9'. It prints "9.". Then loop prints '9', '1', '2'... resulting in "9.912...". This causes the duplicate digit error.
                printf("%c", num[i]);
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