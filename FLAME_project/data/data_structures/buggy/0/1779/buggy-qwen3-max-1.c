#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') @@ // The condition incorrectly assumes that valid expansions must have a difference less than 26, which is only relevant for letters, not digits. Also, it doesn't check if both surrounding characters are of the same type (e.g., both lowercase, both uppercase, or both digits). This leads to incorrect expansion across different character types like 'g' to '0' or '0' to 'A'.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) @@ // The loop condition and logic assume that any '-' with non-negative difference should be expanded, even across incompatible types (e.g., digit to uppercase letter), which violates the problem requirements.
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}