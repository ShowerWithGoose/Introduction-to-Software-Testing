#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition checks ASCII difference < 26, which incorrectly allows expansion across different character types (e.g., '0' to 'A' has diff 17, 'a' to 'A' has diff -32 but handled by >=0 check logic flaws). It fails to verify that both characters are of the same type (both digits, both lowercase, or both uppercase). For input "0-A", 'A'-'0' is 17, which is < 26 and >= 0, so it expands, which is wrong.
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