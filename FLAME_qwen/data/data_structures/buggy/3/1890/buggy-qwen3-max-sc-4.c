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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zeros or if there's no non-zero digit, this loop may run past the end of the string. Also, `temp` is only updated inside the loop, so if the loop doesn't run (first digit after '.' is non-zero), `temp` remains 0, leading to incorrect indexing.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the number is like "0.0", then `temp` remains 0, and this loop starts at i=1, but `num[1]` is '.', and the logic fails to handle cases with no significant digits after zeros. Also, if the input is "0.1", the first loop doesn't run, so temp=0, then i starts at 1, which is '.', and it prints '.' as a digit.]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [The exponent calculation is off by one in some cases. For "0.1", xiao remains 1, so it prints e-1, but correct exponent should be e-1 (which is okay), but for "0.01", xiao becomes 2, prints e-2, which is correct. However, due to earlier logic errors, this may not trigger correctly.]
    }
    printf("\n");

    return 0;
}