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
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Also, the program fails to handle cases where '-' appears at the start or end of string, leading to out-of-bounds access (e.g., s[i-1] when i=0).]
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ [Accessing s[i-1] when i=0 or s[i+1] when s[i] is the last character leads to undefined behavior (reading before start or past end of string).]
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
                printf("%c",s[i]); // @@ [Missing else branch to print '-' when expansion condition fails; current code skips printing '-' entirely in such cases.]
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}