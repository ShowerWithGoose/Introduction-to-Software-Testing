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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zero or if there's no non-zero digit, this loop may access beyond the string length, leading to undefined behavior. Also, `temp` is only updated inside the loop, so if the loop doesn't run (i.e., first digit after '.' is non-zero), `temp` remains 0, which breaks logic.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the input is like "0.0", then `temp` remains 0, and this loop starts at i=1, but num[1] is '.', and the non-zero digit may not exist, leading to incorrect or missing output. Also, if there's only one significant digit after zeros, it should not print a decimal point, but this code always prints one when i != n-1.]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one. For "0.001", xiao becomes 3, but exponent should be -3, yet due to initialization `xiao = 1`, and incrementing per zero, it actually computes -3 correctly in some cases, but logic is fragile and inconsistent with standard scientific notation rules. However, more critically, if there are no leading zeros after "0.", e.g., "0.5", then the first loop doesn't run, `xiao` remains 1, and exponent becomes -1, which is correct, but `temp` is still 0, so printing starts at index 1 (which is '.'), causing wrong output.]
    }
    printf("\n");

    return 0;
}