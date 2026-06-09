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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after the decimal are zero or the string ends early, this loop may access memory beyond the string length, leading to undefined behavior. Also, `temp` is only updated inside the loop, so if the loop doesn't run (first digit after '.' is non-zero), `temp` remains 0, which is incorrect.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the number is like "0.000", then `temp` might be uninitialized or pointing beyond valid digits, and this loop may not print anything, violating output format. Also, if there's only one significant digit after zeros, it should not print a decimal point, but this code prints "%c." unconditionally when `i == temp+1 && i != n-1`, which is wrong.]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one. For "0.001", xiao becomes 3, but exponent should be -3, yet due to initial xiao=1 and incrementing per zero, it may produce -3 correctly in some cases, but logic is fragile and fails when there are no leading zeros after decimal (e.g., "0.1" gives xiao=1 → e-1, which is correct, but the loop condition and temp handling are flawed). However, primary issue is lack of handling when there are no trailing digits after non-zero.]
    }
    printf("\n");

    return 0;
}