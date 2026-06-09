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
        printf("e%d",i-1); // @@ The exponent calculation is incorrect for numbers less than 1. For input "0.9", i becomes 2 (index of '9'). The exponent should be -(number of zeros after decimal + 1) or effectively index_of_first_sig_digit - 1 relative to decimal point, but negative. Specifically, if the first significant digit is at index k (where str[0]=='0' and str[1]=='.'), the exponent is -(k-1). Here i is the index of the first non-zero digit. The exponent should be 1-i. For "0.9", i=2, exponent should be 1-2 = -1. The code prints 2-1=1.
    }
    return 0;
}