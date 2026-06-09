#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char num[200];

int main()
{
    scanf("%s", num);
    int n = strlen(num);
    int zheng = 0, xiao = 1;
    int temp = 0, flag = 0;
    if (num[0] != '0') {
        for (int i = 0; num[i] != '.'; i++) {
            zheng++;
        }
        printf("%c.", num[0]);
        for (int i = 1; i < n; i++) {
            if(num[i]!='.')
                printf("%c", num[i]);
        }
        printf("e%d", zheng - 1);
    }
    else {
        for (int i = 2; num[i] == '0'; i++) { // @@ The loop condition `num[i] == '0'` will stop at the first non-zero digit, but `xiao` is initialized to 1 and incremented for each zero, which incorrectly counts the decimal point position. Also, `temp` is not updated correctly when the loop exits because `i` increments after the last check, so `temp` may be off by one.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ If no zeros were found (e.g., input "0.123"), the loop `for (int i = 2; num[i] == '0'; i++)` never executes, leaving `temp` uninitialized (0), causing this loop to start from index 1, which is the decimal point, leading to incorrect output.
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao);
    }
    printf("\n");

    return 0;
}