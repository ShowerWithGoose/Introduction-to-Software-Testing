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
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more importantly, the logic fails to handle cases where '-' appears at the start or end of string, leading to out-of-bound access like s[i-1] or s[i+1].]
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ [This accesses s[i-1] and s[i+1] without checking if i>0 and s[i+1]!='\0', which leads to undefined behavior for '-' at the beginning or end. Also, it doesn't ensure that the characters are in increasing order (e.g., 'e'-'B' would pass type check but shouldn't expand).]
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
                printf("%c",s[i]); // @@ [Missing else clause to print '-' when expansion conditions are not met. The current code only prints expanded chars or original non-'-' chars, but skips printing '-' when pd() returns 0.]
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}