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
    int temp = 0, flag = 0; // @@ temp should be initialized to 1 for numbers without leading zeros to correctly locate the first non-zero digit.
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
        for (int i = 2; num[i] == '0'; i++) { // @@ This loop does not handle the case with no leading zeros; temp remains 0, causing downstream errors.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ Uses temp which may be 0, causing i to start at index 1 (the decimal point) instead of the first non-zero digit.
            if (i == temp + 1 && i != n - 1) { // @@ Condition assumes first non-zero digit is at temp+1; if no leading zeros, temp+1=1 which is the decimal point.
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