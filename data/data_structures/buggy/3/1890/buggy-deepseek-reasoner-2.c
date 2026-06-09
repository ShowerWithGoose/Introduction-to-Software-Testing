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
        for (int i = 2; num[i] == '0'; i++) { // @@ This loop only counts leading zeros after the decimal point; if there are no leading zeros (e.g., "0.123"), the loop does not run and temp remains 0, which is incorrect.
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ When there are no leading zeros, temp is 0, so this loop starts at i=1, which is the decimal point ('.'), not a digit, causing erroneous output.
            if (i == temp + 1 && i != n - 1) { // @@ The condition assumes temp+1 is the first non-zero digit, but when temp=0, it incorrectly treats the decimal point as the first digit.
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