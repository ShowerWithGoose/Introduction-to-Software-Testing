#include<stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    char*c=s;
    int nq=0;
    while(*c!='.')
    {
        c++;
        nq++;
    }
    if(s[0]=='0')
    {
        int x=0;
        char*d=c;
        while(*d=='.'||*d=='0')
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')
        {
            printf("%ce-%d",*d,x); // @@ [When the input is like "0.0005", after skipping '.', x counts the zeros, but when *(d+1)=='\0', it means only one non-zero digit remains (e.g., "0.5"), but the exponent should be -(x-1) not -x because 'x' includes the '.' as one step. Also, if input is "0.0", this leads to undefined behavior as *d may be '\0'.]
        }
        else
        {
            printf("%c.",*d);
            d++;
            while(*d!='\0')
            {
                printf("%c",*d);
            }
            printf("e-%d",x); // @@ [The exponent calculation is incorrect. 'x' includes the '.' character in its count, so the actual number of leading zeros after the decimal is x-1. Thus, exponent should be -(x-1), not -x.]
        }
    }
    else
    {
        printf("%c.",s[0]);
        char*o=s+1;
        while(*o!='\0')
        {
            if(*o=='.')
            {
                o++;
                continue;
            }
            printf("%c",*o);
            o++;
        }
        printf("e%d",nq-1); // @@ [This is correct for numbers >= 1.0, e.g., "123.45" -> nq=3, exponent=2. So no error here.]
    }
    return 0;
}