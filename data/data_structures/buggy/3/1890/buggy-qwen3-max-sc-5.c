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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zeros or if there's no non-zero digit, this loop may access beyond the string length, leading to undefined behavior. Also, `temp` is only updated inside the loop, so if the loop doesn't run (first digit after '.' is non-zero), `temp` remains 0, which is incorrect.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the number is like "0.0", then `temp` might be uninitialized or pointing incorrectly, and this loop may not print anything, violating output format. Also, if the first non-zero digit is the last character, it should not print a decimal point, but the condition `i != n - 1` is flawed.]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one. For "0.001", xiao becomes 3, but exponent should be -3, yet due to initialization `xiao=1` and loop logic, it may produce wrong exponent. Correct exponent is -(position of first non-zero after decimal).]
    }
    printf("\n");

    return 0;
}