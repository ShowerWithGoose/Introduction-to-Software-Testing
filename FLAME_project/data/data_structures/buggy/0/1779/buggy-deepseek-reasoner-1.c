#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ The condition does not check that characters on both sides of '-' are of the same type (digit, lowercase, uppercase) or that they are within the valid ranges [a-z], [A-Z], [0-9]. This causes incorrect expansion, e.g., expanding between '0' and 'A'.
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