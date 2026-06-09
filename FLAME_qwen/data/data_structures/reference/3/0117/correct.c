#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[105];
int main()
{
    fgets(s, 104, stdin);
    int c=0,n=0,l=strlen(s);
    for (int i=0;i<l-1;i++)
    {
        if (s[i]=='0')
            continue;
        if (s[i]!='0'&&s[i]!='.')
        {
            if (n!=0)
                continue;
            n=i+1;
            if (s[0]=='0')
                n=i-1;
        }
        if (s[i]=='.')
            c=i-1;
    }
    if (s[0]=='0')
    {
        if (n+2>=l-1)
            printf("%c", s[n+1]);
        else
            printf("%c.", s[n+1]);
        for (int i=n+2;i<l-1;i++)
        {
            printf("%c", s[i]);
        }
        printf("e-%d",abs(n-c));
    }
    if (s[0]!='0')
    {
        printf("%c.",s[n-1]);
        for (int i=n;i<l-1; i++)
        {
            if (s[i]=='.')
                continue;
            printf("%c",s[i]);
        }
        printf("e%d",abs(n-c-1));
    }
    return 0;
}



