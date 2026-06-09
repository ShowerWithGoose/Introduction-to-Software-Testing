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
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Use fgets() instead.]
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
            }
            else
            {
                printf("%c",s[i]); // @@ [When the '-' is not part of a valid expansion, it should be printed, but this else block is missing in the original logic causing '-' to be omitted in invalid cases.]
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}