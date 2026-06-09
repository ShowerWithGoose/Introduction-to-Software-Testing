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
        for (int i = 2; num[i] == '0'; i++) { // @@ The loop condition `num[i] == '0'` fails to stop at the first non-zero digit or end of string correctly for cases like "0.9" where there are no leading zeros after decimal. It also doesn't handle the case where the digit after '0.' is immediately non-zero. For "0.9", i starts at 2. num[2] is '9'. The loop condition `num[2]=='0'` is false. Loop doesn't run. temp remains 0.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ Since temp is 0 for "0.9", this loop starts at i=1. num[1] is '.'. The logic below prints "." again if i==temp+1 (1==1) and i!=n-1 (1!=2). So it prints ".". Then i=2, prints "9". Resulting in "..9". The starting index should be the first significant digit, which is at index 2.
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