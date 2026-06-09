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
        for (int i = 2; num[i] == '0'; i++) { // @@ The loop starts from index 2, but for input "0.9", num[2] is '9' which is not '0', so the loop body never executes, leaving xiao=1 and temp=0. This incorrectly assumes there is one leading zero after the decimal point, when there are actually zero leading zeros.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ Since temp remains 0, temp+1 = 1, so the loop starts from index 1, which is '.' in "0.9". This causes the '.' to be printed as part of the output, resulting in "..9e-1" instead of "9e-1".
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