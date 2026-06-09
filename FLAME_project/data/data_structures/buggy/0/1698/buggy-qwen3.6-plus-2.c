#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s);
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ The condition checks if the start is a digit and the end is <= '9', but fails to verify that the end character is also a digit or that they are of the same type. More importantly, for mixed types like 'B' (66) and 'e' (101), this condition is false, so it falls through. However, the logic for determining whether to expand or print '-' is flawed because it doesn't explicitly handle the "else" case where expansion is invalid. If none of the if/else-if blocks execute, nothing is printed for the '-', effectively swallowing it. It should print '-' if expansion conditions are not met.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Similar issue: checks start >= 'A' and end <= 'Z'. If this fails, it goes to the next check.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Similar issue. If all three conditions fail (as in B-e, where B is uppercase but e is lowercase, so the second condition fails because e > 90, and the third fails because B < 97), the code does nothing for the '-' character. It needs an else clause to print '-' when expansion is not performed.
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