#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition does not check that both characters are of the same type (lowercase, uppercase, or digit). For example, '0' and 'A' have a difference less than 26, but they should not be expanded. Also, it does not check that the character after '-' is greater than the one before it (the difference >=0 is insufficient because it allows equal characters). Additionally, it does not verify that s[i-1] and s[i+1] are within valid ranges [a-z], [A-Z], [0-9].
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ The loop condition uses < instead of <=, so it misses the last character in the expansion (e.g., for a-c, it prints only 'b' instead of 'b' and 'c'). Also, the loop variable q is an int, but it should be a char to correctly print characters.
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}