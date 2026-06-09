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
        for (int i = 0; num[i] != '.'; i++) { // @@ [If there's no decimal point in the input, this loop will run past the end of the string, causing undefined behavior.]
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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zeros or if the string ends early, this loop may access memory beyond the string length, leading to undefined behavior. Also, `temp` is only updated inside the loop, so if the loop doesn't run (first digit after '.' is non-zero), `temp` remains 0, which is incorrect.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) {
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one. For example, "0.001" should be "1e-3", but this code outputs "e-2" because `xiao` starts at 1 and counts zeros starting from index 2.]
    }
    printf("\n");

    return 0;
}