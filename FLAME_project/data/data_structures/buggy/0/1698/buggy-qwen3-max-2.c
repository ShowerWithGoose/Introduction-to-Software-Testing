#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more importantly, it's deprecated. However, the main logical error is elsewhere.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Incorrect range check: should ensure both characters are digits (i.e., s[i-1] <= '9' and s[i+1] >= '0'), not just s[i-1] >= '0' and s[i+1] <= '9'. This allows mixed-type cases like '0-b' to pass if b <= '9', which is wrong. Also, doesn't verify that both ends are of the same type.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Same issue: only checks lower bound of left char and upper bound of right char. Should ensure both are uppercase letters, e.g., s[i-1] <= 'Z' and s[i+1] >= 'A'. Without this, a case like 'A-z' could incorrectly trigger expansion if z <= 'Z' (which it isn't), but more critically, 'B-e' (as in test case) has s[i-1]='B' (>=65) and s[i+1]='e' (<=90 is false, so skips), but wait—'e' is 101, so condition fails. However, the real problem is that the condition does NOT check that BOTH characters belong to the same category. For 'B-e', 'B' is uppercase, 'e' is lowercase—they are different types, so should NOT expand. But current logic only checks s[i-1]>=65 (true) and s[i+1]<=90 (false, since 'e'=101>90), so it skips uppercase block. Then checks lowercase: s[i-1]>=97? 'B'=66>=97? false. So none of the conditions match, so it falls through without printing '-', which is wrong. The else clause is missing!]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Same flawed range checking. Also, if none of the three conditions are met, the program does nothing for the '-' character—it doesn't print it. That's why input "B-e" outputs "Be": the '-' is skipped entirely instead of being printed as-is.]
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