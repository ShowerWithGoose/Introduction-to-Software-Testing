#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; more importantly, it may cause issues with input handling, but the core logic error is elsewhere.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Incorrect condition: checks only lower bound for digits (s[i-1] >= '0') and upper bound for s[i+1] <= '9', but does not ensure both are digits. For example, if s[i-1] is 'A' (65) and s[i+1] is '5' (53), this condition could incorrectly pass part of the check. More critically, it allows mixed-type cases like 'B-e' to potentially fall through if numeric bounds coincidentally match, but the real issue is lack of same-type validation.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Same issue: only checks s[i-1] >= 'A' and s[i+1] <= 'Z', but doesn't ensure s[i+1] >= 'A' or s[i-1] <= 'Z'. So if s[i-1] is '0' (48) and s[i+1] is 'Z' (90), it might incorrectly trigger. Also fails to verify both characters are uppercase letters.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Same problem: only checks s[i-1] >= 'a' and s[i+1] <= 'z', but doesn't ensure s[i+1] >= 'a' or s[i-1] <= 'z'. Thus, mixed cases like 'B-e' (where 'B'=66, 'e'=101) may not be caught because 66 >= 65 (true), 101 <= 122 (true), and 66 < 101 (true), so it would incorrectly expand.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
            else
            printf("%c",s[i]); // @@ [This line is missing! The original code does not print '-' when none of the conditions match. In the given test case 'B-e', none of the correct type-matching conditions should pass, so '-' should be printed, but the code skips printing anything for the '-' character in the else case. This causes the '-' to be omitted, leading to output "Be" instead of "B-e".]
        }
        else
        printf("%c",s[i]);
    }
    return 0;
}