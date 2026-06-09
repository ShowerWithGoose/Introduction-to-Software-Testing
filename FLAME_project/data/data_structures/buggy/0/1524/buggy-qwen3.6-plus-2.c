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
            if(pd(s[i-1],s[i+1])==1) // @@ The logic fails to check if the character after '-' is strictly greater than the character before it. For input "B-e", 'B' and 'e' are different cases, so pd returns 0, which is correct. However, the problem states that expansion only happens if they are the same type AND the latter is greater. The current pd function only checks types. Wait, looking at the test case B-e: 'B' is upper, 'e' is lower. pd('B', 'e') checks: 1. 'a'<='B'... false. 2. 'A'<='B'... true AND 'A'<='e'... true. So pd returns 1. This is incorrect because 'B' and 'e' are not the same type (one upper, one lower). The condition 'A'<='e' is true because 'e' (101) > 'A' (65). The check for uppercase should be 'A'<=b && b<='Z'. 'e' is not <= 'Z'. So pd('B', 'e') should return 0. Let's re-read pd. if('A'<=a&&a<='Z'&&'A'<=b&&b<='Z'). For b='e', 'e'<='Z' is false. So pd returns 0. So why is the output wrong?
            
            Let's trace "B-e".
            i=0: 'B'. Not '-'. Print 'B'.
            i=1: '-'. Is '-'. Check pd('B', 'e').
               'a'<='B'... false.
               'A'<='B' (true) && 'B'<='Z' (true) && 'A'<='e' (true) && 'e'<='Z' (false). So this block is skipped.
               '0'<='B'... false.
               Returns 0.
            So pd returns 0. The if(pd(...)==1) is false.
            So we go to else? No, the structure is:
            if(s[i]=='-') {
               if(pd...) { ... }
            } else {
               printf("%c", s[i]);
            }
            
            If s[i] is '-', and pd is false, nothing is printed inside the if(s[i]=='-') block. The else block is attached to if(s[i]=='-'), so it is NOT executed for '-'.
            Thus, the '-' character itself is never printed when expansion does not occur.
            
            The error is that when expansion conditions are not met, the '-' character is skipped entirely instead of being printed.
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
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}