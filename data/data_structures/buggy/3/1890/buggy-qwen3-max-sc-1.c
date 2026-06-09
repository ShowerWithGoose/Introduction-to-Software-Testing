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
        for (int i = 0; num[i] != '.'; i++) { // @@ [If the input has no decimal point, this loop will read beyond the string bounds, causing undefined behavior.]
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
        for (int i = 2; num[i] == '0'; i++) { // @@ [If all digits after "0." are zeros or if there's no non-zero digit, this loop may run past the end of the string, leading to undefined behavior. Also, `temp` is only updated inside the loop, so if the loop never runs (i.e., first digit after '.' is non-zero), `temp` remains 0, which breaks logic.]
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
        printf("e%d", -xiao); // @@ [The exponent calculation is incorrect in cases where the first non-zero digit is immediately after "0."; it should be -(position_after_decimal), but current logic miscounts due to initialization and update issues.]
    }
    printf("\n");

    return 0;
}