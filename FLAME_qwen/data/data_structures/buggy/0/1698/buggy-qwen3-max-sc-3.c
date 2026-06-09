#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Condition checks only upper bound for s[i+1] and lower bound for s[i-1]; should also ensure s[i-1] <= '9' and s[i+1] >= '0' to confirm both are digits.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Condition checks only upper bound for s[i+1] and lower bound for s[i-1]; should also ensure s[i-1] <= 'Z' and s[i+1] >= 'A' to confirm both are uppercase letters.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Condition checks only upper bound for s[i+1] and lower bound for s[i-1]; should also ensure s[i-1] <= 'z' and s[i+1] >= 'a' to confirm both are lowercase letters.]
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