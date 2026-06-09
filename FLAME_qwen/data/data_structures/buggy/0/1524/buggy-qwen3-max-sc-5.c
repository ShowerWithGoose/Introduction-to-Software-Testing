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
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers as it was removed from the C standard library in C11; also, no check for boundary conditions like '-' at start/end of string]
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ [Accessing s[i-1] when i=0 or s[i+1] when i is last index leads to undefined behavior (out-of-bounds access)]
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
                printf("%c",s[i]); // @@ [Missing else branch to print '-' when expansion condition fails; current code skips printing '-' entirely in such cases]
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}