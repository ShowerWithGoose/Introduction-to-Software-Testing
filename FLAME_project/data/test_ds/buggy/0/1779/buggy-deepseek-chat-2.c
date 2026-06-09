#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition does not check that characters around '-' are of the same type (lowercase, uppercase, or digit). It also does not ensure s[i-1] and s[i+1] are valid indices (e.g., at start or end of string). Additionally, it incorrectly allows expansion when the difference is less than 26 regardless of character type, leading to expansion of mixed types like '0' to 'A'.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ The loop condition uses < instead of <=, so it misses the last character in the expansion (e.g., for a-c, it prints only 'b' instead of 'b' and 'c').
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}