#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [This condition checks only the upper bound of s[i+1] for digits but does not verify that s[i+1] >= '0'; similarly, it doesn't ensure s[i-1] <= '9'. Thus, it may incorrectly process cases like '-0' or '9-:' as valid digit ranges.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [This condition checks only the upper bound of s[i+1] for uppercase letters but does not verify that s[i+1] >= 'A'; similarly, it doesn't ensure s[i-1] <= 'Z'. Thus, it may incorrectly process mixed-type cases like 'Z-a' if a happens to be <= 'Z' in ASCII (which it isn't), but more critically, it fails to validate both ends are uppercase.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [This condition checks only the upper bound of s[i+1] for lowercase letters but does not verify that s[i+1] >= 'a'; similarly, it doesn't ensure s[i-1] <= 'z'. Thus, it may incorrectly process invalid ranges involving non-lowercase characters.]
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