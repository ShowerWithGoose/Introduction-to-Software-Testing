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
        if(*(d+1)=='\0')  // @@ [Incorrect condition: should check *d == '\0' to see if only one significant digit remains, not *(d+1). Also, d might already be past the string end.]
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
        printf("e%d",nq-1);  // @@ [Correct for numbers like "123.45" (nq=3 → e2), but fails if input has no decimal point because nq becomes strlen(s) and loop never breaks.]
    }
    return 0;
}