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
        printf("e-%d",1-i); // @@ The exponent calculation is incorrect. For input "0.9", the first non-zero digit '9' is at index 2, so the exponent should be -(2 - 1) = -1, but the code prints e%d with i-1 (which is 1), and also misses the minus sign. It should print e-%d with (i - 1) as positive magnitude, or adjust formula accordingly.
    }
    return 0;
}