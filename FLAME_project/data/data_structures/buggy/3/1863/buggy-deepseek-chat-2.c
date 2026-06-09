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
        printf("e%d",i-1); // @@ The exponent calculation is incorrect. For input "0.9", i becomes 2 after skipping leading zeros, so i-1 = 1, but the correct exponent should be -1 (since the decimal point is at position 1, and the first non-zero digit is at position 2, the exponent is 1 - 2 = -1). The formula should be (p - str - 1) where p points to the decimal point, but here the logic does not account for the decimal point position correctly.
    }
    return 0;
}