#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition does not check that both characters are of the same type (lowercase, uppercase, or digit) and that the character after '-' is greater than the one before. It also incorrectly allows expansion across different character types (e.g., '0' to 'A').
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ The loop condition uses '<' which may miss the last character in the expansion (e.g., for 'a-c', it prints 'b' but not 'c'). Also, it does not handle the case where the difference is 0 or negative.
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}