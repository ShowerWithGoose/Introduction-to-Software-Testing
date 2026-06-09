#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str);
    if(str[0]!='0')
    {
        while(str[i]!='.')
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++)
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0')
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++)
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ The exponent calculation is incorrect for numbers less than 1. For input "0.9", i becomes 2 (index of '9'). The exponent should be -(number of zeros after decimal + 1) or simply based on the position relative to the decimal point. Here, for 0.9, the exponent should be -1. The current formula `i-1` yields `2-1=1`, which is wrong. It should be `-(i - 1)` because `i` is the index of the first significant digit, and the decimal point is at index 1. The shift is `1 - i`. So `printf("e%d", 1 - i);` would be correct.
    }
    return 0;
}