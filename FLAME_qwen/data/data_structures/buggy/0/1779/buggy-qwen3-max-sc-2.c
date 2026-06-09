#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using gets() is unsafe and deprecated; however, the main logical errors are below. Also, this may cause compilation issues in modern compilers due to removal of gets().]
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is fundamentally flawed: it accesses s[i-1] when i=0, causing out-of-bounds read (undefined behavior). Also, it doesn't check character types (digit, upper, lower) or ensure both sides of '-' are same type. The difference <26 only works for lowercase letters, not digits or uppercase.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [Loop bound is incorrect: should run while s[i-1]+q < s[i+1], but more critically, no validation that s[i+1] is valid (e.g., i+1 may be beyond string end if '-' is last char).]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}