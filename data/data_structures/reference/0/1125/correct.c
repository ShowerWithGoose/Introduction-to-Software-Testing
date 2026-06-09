#include<stdio.h>
char s[1000];
int jj(int x)
{
    if(s[x+1]<=s[x-1])
    {
        return 1;
    }
    if(s[x+1]>='0'&&s[x+1]<='9')
    {
        if(s[x-1]>='0'&&s[x-1]<='9')
        {
            return 0;
        }
        return 1;
    }
    if(s[x+1]>='a'&&s[x+1]<='z')
    {
        if(s[x-1]>='a'&&s[x-1]<='z')
        {
            return 0;
        }
        return 1;
    }
    if(s[x+1]>='A'&&s[x+1]<='Z')
    {
        if(s[x-1]>='A'&&s[x-1]<='Z')
        {
            return 0;
        }
        return 1;
    }
}
int main()
{
    char ch;
    gets(s+1);
    int i;
    for(i=1;s[i]!='\0';i++)
    {
        if(s[i+1]!='-'&&s[i]!='-'&&s[i-1]!='-')
        {
            printf("%c",s[i]);
        }
        else if(s[i]=='-')
        {
            if(i==1||s[i+1]=='\0')
            {
                if(i==1)
                printf("%c%c",s[i],s[i+1]);
                else
                {
                    printf("%c%c",s[i-1],s[i]);
                }
            }
            else if(jj(i))
            {
                printf("%c%c%c",s[i-1],s[i],s[i+1]);
            }
            else
            {
                if(s[i-2]!='-'||(s[i-2]=='-'&&jj(i-2)==1))
                for(ch=s[i-1];ch<=s[i+1];ch++)
                {
                    printf("%c",ch);
                }
                else
                {
                    for(ch=s[i-1]+1;ch<=s[i+1];ch++)
                    {
                        printf("%c",ch);
                    }
                }
            }
        }
    }
    return 0;
}
