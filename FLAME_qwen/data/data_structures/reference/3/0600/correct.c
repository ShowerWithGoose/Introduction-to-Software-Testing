#include<stdio.h>
#include<string.h>
int main()
{
    char s[105],c[110];
    int i,j,digit;
    scanf("%s",s);
    if(s[1]=='.' && s[0]=='0')
    {
        for(j=2;s[j]=='0';j++);
        digit=j-1;
        if(s[j+1]==0) printf("%c",s[j]);
        else
        {
            printf("%c.",s[j]);
            for(j++;s[j]!=0;j++)
                printf("%c",s[j]);
        }
            printf("e-%d",digit);
    }
    else
    {
        printf("%c.",s[0]);
        for(j=1;s[j]!='.';j++)
            printf("%c",s[j]);
        digit=j-1;
        for(i=j+1;s[i]!=0;i++)
            printf("%c",s[i]);
        printf("e%d",digit);
    }
}

