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
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ Condition does not ensure s[i+1] is also a digit (e.g., allows s[i+1] <=57 but s[i-1] could be 'A'); however, this is not the direct cause of the test case failure.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Condition does not enforce that s[i+1] is uppercase (only checks it is <=90, missing lower bound >=65). For "B-e" it correctly fails because 'e' >90, so not causing the failure here.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Similar issue: does not require s[i+1] >=97.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
        } // @@ Missing else clause for the nested if-else if chain. When none of the conditions are true (as in "B-e"), no dash is printed, causing the program to skip the '-' and output "Be" instead of "B-e".
        else
        printf("%c",s[i]);
    }
    return 0;
}