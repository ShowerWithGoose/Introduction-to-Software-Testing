#include<stdio.h>
#include<string.h>
char s[105];
int main()
{
    int i,cnt,l;
    scanf("%s",s);
    l=strlen(s);
    if(s[0]=='0')
    {
        for(i=0;i<l;i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                cnt=i-1;
                printf("%c",s[i]);
                break;
            }
        }
        if(i==l-1)
            printf("e-%d",cnt);
        else
        {
            printf(".");
            for(i=i+1;i<l;i++)
                printf("%c",s[i]);
            printf("e-%d",cnt);
        }
    }
    else
    {
        for(i=0;i<l;i++)
        {
            if(s[i]=='.')
            {
                cnt=i-1;
                break;
            }
        }
        printf("%c.",s[0]);
        for(i=1;i<l;i++)
        {
            if(s[i]!='.')
                printf("%c",s[i]);
        }
        printf("e%d",cnt);
    }
    return 0;
}

