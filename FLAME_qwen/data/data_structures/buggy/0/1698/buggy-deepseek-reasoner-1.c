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
            j=s[i+1]-s[i-1]; // @@ Potential out-of-bounds access if i=0 or i=len-1, and j may be undefined if characters are not in the same range.
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ Incomplete range checks: should also ensure s[i-1]<=57 and s[i+1]>=48. Also may access invalid indices.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Incomplete range checks: should also ensure s[i-1]<=90 and s[i+1]>=65.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Incomplete range checks: should also ensure s[i-1]<=122 and s[i+1]>=97.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
        }
        else
        printf("%c",s[i]); // @@ When s[i] is '-' and none of the expansion conditions hold, the dash is not printed, which leads to missing characters.
    }
    return 0;
}