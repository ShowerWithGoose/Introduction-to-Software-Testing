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
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ Incorrect range validation: only checks lower bound for left char and upper bound for right char. Should verify both characters are within '0'-'9'.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Incorrect range validation for uppercase: missing full range check for both characters. Should verify both are within 'A'-'Z'.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Incorrect range validation for lowercase: missing full range check for both characters. Should verify both are within 'a'-'z'.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
        }
        else // @@ Logical error: when s[i] is '-' and expansion conditions fail, the '-' is not printed. The else branch only handles non-'-' characters, causing '-' to be omitted in invalid cases.
        printf("%c",s[i]);
    }
    return 0;
}