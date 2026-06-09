#include<stdio.h>
#include<ctype.h>
char s[10000]; 
int pd(char a,char b)
{
    if('a'<=a&&a<='z'&&'a'<=b&&b<='z')
    return 1;
    if('A'<=a&&a<='Z'&&'A'<=b&&b<='Z')
    return 1;
    if('0'<=a&&a<='9'&&'0'<=b&&b<='9')
    return 1;
    return 0;
}
int main()
{    
    int cha=0;
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1)
            {
                cha=0;
                cha=s[i+1]-s[i-1]-1;
                if(cha>0)
                {
                    for(int k=1;k<=cha;k++)
                    {
                        printf("%c",s[i-1]+k);
                    }
                }
                else // @@ When cha <= 0 (i.e., s[i-1] >= s[i+1]), the program does not output the '-' character, but it should output it unchanged.
                {
                    printf("%c",s[i]);
                }
            }
            else // @@ When pd returns 0 (different types), the program does not output the '-' character, but it should output it unchanged.
            {
                printf("%c",s[i]);
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}