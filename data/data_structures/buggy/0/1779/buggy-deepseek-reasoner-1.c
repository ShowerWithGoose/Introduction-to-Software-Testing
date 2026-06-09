#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++) // @@ Error: loop starts at i=0, but accesses s[i-1] (out-of-bounds) and does not handle printing of first character separately.
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ Error: condition does not check that s[i-1] and s[i+1] are in the same character class (lowercase, uppercase, digits) and within valid ranges; may incorrectly expand across different sets.
            {
                for(int q=1;q<s[i+1]-s[i-1];q++)
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]);
    }

    return 0;
}