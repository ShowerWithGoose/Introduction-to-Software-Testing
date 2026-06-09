#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more importantly, it's not the cause of the logical error here, but the real issue is in expansion condition checks]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Incorrect range check: should ensure both characters are digits (i.e., s[i-1] <= '9' AND s[i+1] >= '0'), not just s[i-1] >= '0' and s[i+1] <= '9'. This allows mixed-type cases like '0-b' to pass if b <= '9', which it isn't, but more critically, it doesn't verify that both ends are of the same type. For example, 'B-e' has s[i-1]='B' (66) and s[i+1]='e' (101). This condition fails for digits, but the next two conditions also have similar flaws.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Incorrect range check: requires only that left char >= 'A' and right char <= 'Z', but does not ensure left char <= 'Z' or right char >= 'A'. So if left is uppercase and right is lowercase (like 'B' and 'e'), since 'e' (101) > 'Z' (90), this condition fails — which is good — but the logic is still flawed because it doesn't confirm both are uppercase. However, the bigger issue is in the third condition.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Same flawed logic: only checks left >= 'a' and right <= 'z', but doesn't ensure right >= 'a' or left <= 'z'. However, the critical error is that none of these conditions verify that BOTH characters belong to the same category. For input "B-e", s[i-1] = 'B' (66), s[i+1] = 'e' (101). None of the three conditions are satisfied, so the '-' is not printed at all — but in the buggy output, we see "Be", meaning the '-' was skipped and not printed. The program never prints the '-' in the else case!]
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