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
        while(*d=='.'||*d=='0')  // @@ [This loop may run past the end of the string if all remaining characters are '0' or '.', leading to reading beyond '\0'.]
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')  // @@ [Incorrect condition: should check if *d is the last non-zero digit (i.e., *d != '\0' and *(d+1) == '\0'), but d might already be at '\0'. Also, if d points to '\0', *(d+1) is invalid.]
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