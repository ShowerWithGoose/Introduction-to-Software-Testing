#include<stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    char*c=s;
    int nq=0;
    while(*c!='.')  // @@ [If the input has no decimal point, this loop runs past the end of the string, causing undefined behavior.]
    {
        c++;
        nq++;
    }
    if(s[0]=='0')
    {
        int x=0;
        char*d=c;
        while(*d=='.'||*d=='0')  // @@ [This condition skips the decimal point and zeros, but if the number is like "0.0", it may run past the null terminator. Also, after skipping '.', it immediately checks for '0', but doesn't ensure *d is not '\0'.]
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')  // @@ [This checks if the next character after d is null, but if d itself is already at '\0', then *(d+1) is invalid memory access. Should check *d == '\0' instead.]
        {
            printf("%ce-%d",*d,x);
        }
        else
        {
            printf("%c.",*d);
            d++;
            while(*d!='\0')
            {
                printf("%c",*d);
            }
            printf("e-%d",x);
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
        printf("e%d",nq-1);
    }
    return 0;
}