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
        for (int i = 0; num[i] != '.'; i++) { // @@ [If the input has no decimal point, this loop will run past the end of the string, causing undefined behavior.]
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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zeros or if there's no non-zero digit, this loop may access beyond the string length, leading to undefined behavior. Also, `temp` remains 0 if loop doesn't run, causing incorrect indexing later.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the input is like "0.0", `temp` stays 0, so `temp+1=1`, but `num[1]` is '.', and the loop may print nothing or crash. Also, if there's only one significant digit, it should not print a decimal point.]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one; for "0.001", xiao becomes 3 but exponent should be -3, yet due to initialization `xiao=1`, it becomes -3 only if loop runs twice, which is inconsistent.]
    }
    printf("\n");

    return 0;
}