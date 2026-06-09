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
                else // @@ [When cha <= 0 (e.g., s[i-1] >= s[i+1]), the '-' should be printed as-is, but the code does not output it, causing characters to be lost. For input "B-e", s[i-1]='B', s[i+1]='e', pd returns 0, so this branch is not entered, but the logic here is incomplete for cases where pd returns 1 but cha <= 0.]
                {
                    printf("-");
                }
            }
            else // @@ [When pd returns 0 (e.g., different types like 'B' and 'e'), the '-' should be printed as-is, but the code does not output it, causing the '-' to be omitted. For input "B-e", pd returns 0, so this else branch is taken, but it does nothing, so the '-' is not printed.]
            {
                // Missing output of '-'
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}