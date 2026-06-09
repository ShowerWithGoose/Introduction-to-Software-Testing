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
        printf("e%d",i-1); @@ [The exponent should be negative when the input is less than 1 (like "0.9"). The current code prints "e1" instead of "e-1" because it uses i-1 as a positive exponent. The correct exponent is -(i - 1), since the first non-zero digit is at position i, and the decimal point was originally at index 1, so the shift is (1 - i) = -(i - 1).]
    }
    return 0;
}