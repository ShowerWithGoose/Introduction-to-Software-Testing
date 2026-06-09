#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is removed from the standard library, leading to a compilation error.]
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ [Incorrect condition: should also check that s[i+1] >= '0' (i.e., >=48) to ensure both ends are digits. As written, e.g., '-9' with s[i-1]='-' (ASCII 45) could pass if s[i+1] <= '9', which is wrong. Also, missing validation that s[i+1] is a digit.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Incorrect condition: should also check that s[i+1] >= 'A' (i.e., >=65). Without it, a case like 'Z-' followed by a character less than 'Z' but still <= 'Z' (e.g., '0') might incorrectly trigger expansion.]
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Incorrect condition: should also check that s[i+1] >= 'a' (i.e., >=97). Otherwise, non-lowercase characters after '-' could be misinterpreted as valid.]
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