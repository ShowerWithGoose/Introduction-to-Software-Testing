#include <stdio.h>
#include <string.h>
char s[150];
char ss[150];
int main()
{
    int cnt;

    scanf("%s",s);
    if(s[0]=='0')
    {
        if(s[1]=='\0')
        printf("0e0\n");
        if(s[1]=='.')
        for(int i=1;i<=100;i++)
        {
            if(s[i+1]!='0')
            {
                ss[0]=s[i+1];
                if(s[i+2]=='\0')
                {
                    printf("%ce-%d",ss[0],i);
                    break;
                }
                else
                {
                    printf("%c.",ss[0]);
                    for(int k=i+2;s[k]!='\0';k++)
                    printf("%c",s[k]);
                    printf("e-%d",i);
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<=100;i++)
        {
            if(s[i+1]=='.')
            {
                printf("%c",s[0]);
                printf(".");
                for(int k=1;s[k]!='\0';k++)
                {
                    if(s[k]=='.')
                    continue;
                    printf("%c",s[k]);
                }
                printf("e%d",i);
                break;
            }
        }
    }
    return 0;
}
