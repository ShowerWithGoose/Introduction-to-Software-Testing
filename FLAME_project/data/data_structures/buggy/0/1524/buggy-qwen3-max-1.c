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
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is elsewhere.]
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ [This condition does not check if s[i-1] < s[i+1], which is required by the problem. For input "B-e", 'B' and 'e' are different cases (uppercase vs lowercase), so pd() returns 0, but in other mixed-type cases like "a-R", it might incorrectly allow expansion if types matched but order was wrong. However, the real issue here is that pd() returns 1 only when both are same type, but the problem also requires that the character after '-' is greater than the one before. The missing check s[i-1] < s[i+1] causes incorrect expansion in some cases, but in "B-e", pd() correctly returns 0 because 'B' is uppercase and 'e' is lowercase, so no expansion occurs. So why is output "Be" instead of "B-e"? Because when s[i]=='-' and the condition fails, the '-' is simply skipped and not printed.]
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
            // @@ [Missing else clause to print the '-' when expansion is not performed. As a result, the '-' is omitted from output when the condition fails, leading to "Be" instead of "B-e".]
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}