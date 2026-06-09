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
        for (int i = 2; num[i] == '0'; i++) { // @@ [The loop condition does not check bounds; if all digits after "0." are zeros or input is just "0.", it may access beyond string length. Also, 'temp' remains uninitialized if loop never runs (e.g., input "0.9"), leading to undefined behavior.]
            xiao++;
            temp = i;
        }
        for (int i = temp + 1; i < n; i++) { // @@ [If the previous loop didn't execute (like in "0.9"), 'temp' is still 0, so this starts at i=1, which is '.', causing '.' to be printed as part of mantissa, resulting in output like "..9".]
            if (i == temp + 1 && i != n - 1) {
                printf("%c.", num[i]);
            }
            else {
                printf("%c", num[i]);
            }
        }
        printf("e%d", -xiao); // @@ [In case like "0.9", xiao remains 1, so exponent becomes -1, which is correct, but mantissa printing is broken due to earlier errors.]
    }
    printf("\n");

    return 0;
}