#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using gets() is unsafe and deprecated; more importantly, it may cause issues with input handling, but the main logic error is elsewhere.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Condition checks only lower bound for digits and upper bound for digits independently, but doesn't ensure both are digits. For example, '0' (48) and 'z' (122): 48>=48 and 122<=57 is false, so it's safe here, but the real issue is in mixed-type cases like 'B' (66) and 'e' (101). The condition s[i-1]>=65 && s[i+1]<=90 will be true for B-e because 'B'=66>=65 and 'e'=101<=90 is false, so it skips uppercase block. But then lowercase: s[i-1]='B'=66>=97? No. So none of the conditions match, which is correct. However, the problem is that the program does not output the '-' when expansion conditions aren't met. It simply skips printing anything for the '-' case if none of the if blocks match, thus omitting the '-'.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Same issue: this condition requires s[i-1] to be uppercase AND s[i+1] to be <= 'Z', but in "B-e", s[i+1] is 'e' (101), which is > 90, so condition fails. Similarly, next condition fails because s[i-1] is 'B' (66) < 97. So none of the expansion blocks execute, and the '-' is never printed. The program should print '-' in such cases, but it doesn't.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
        }
        else
        printf("%c",s[i]);
    }
    return 0;
}