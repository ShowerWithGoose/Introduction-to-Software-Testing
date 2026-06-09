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
        for (int i = 2; num[i] == '0'; i++) { // @@ The loop condition `num[i] == '0'` fails to stop at the first significant digit if it is not '0', but more importantly, it doesn't handle the case where the digit after '0.' is non-zero correctly in the subsequent printing logic. For input "0.9", `num[2]` is '9'. The loop `for (int i = 2; num[i] == '0'; i++)` does not execute because `num[2]` ('9') is not '0'. Thus `temp` remains 0.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ Since `temp` is 0, this loop starts at `i = 1`. `num[1]` is '.'. The condition `if (i == temp + 1 && i != n - 1)` becomes `if (1 == 1 && 1 != 2)`, which is true. So it prints `num[1]` ('.') followed by '.'. This results in "..". Then it continues to print '9'. The output becomes "..9". The logic for identifying the first significant digit and constructing the mantissa is flawed for numbers like 0.9.
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