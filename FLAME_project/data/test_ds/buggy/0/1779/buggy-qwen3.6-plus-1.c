#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition incorrectly relies on ASCII difference (<26) instead of verifying that both characters are of the same type (digits, lowercase, or uppercase). This causes invalid expansions like '0-A'. It should also strictly check s[i+1] > s[i-1].
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