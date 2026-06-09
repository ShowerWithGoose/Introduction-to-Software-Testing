#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ Unsafe, may lead to buffer overflow, but main logical errors are elsewhere.
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ Lacks boundary check for i-1 and i+1 (especially when i==0 or i==len-1) and does not ensure both characters are of the same type (lowercase/uppercase/digit), causing incorrect expansion across types (e.g., '0'-'A').
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