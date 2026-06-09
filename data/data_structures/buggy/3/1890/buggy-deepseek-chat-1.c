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
        for (int i = 2; num[i] == '0'; i++) { // @@ The loop condition `num[i] == '0'` will cause an infinite loop if the string ends with '0' or if there is no non-zero digit after the decimal point, because it does not check for the end of the string. Additionally, `xiao` is initialized to 1 but should start counting from 1 (the position after the decimal point), and the loop increments `xiao` for each leading zero, but the logic for `temp` and `xiao` is flawed.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ If no leading zeros are found (e.g., input "0.5"), the loop `for (int i = 2; num[i] == '0'; i++)` will not execute, leaving `temp` uninitialized (0), causing incorrect indexing here.
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ The exponent calculation is incorrect. For input like "0.00123", the exponent should be -3, but `xiao` counts the number of leading zeros plus the initial 1, resulting in an incorrect value.
    }
    printf("\n");

    return 0;
}