#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.]
    int l,wc,wd;
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [wc is uninitialized if no '.' is found; also loop should start from 0 to handle cases like ".5"]
    if(wc>1) 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]!='0') 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]=='0') 
    {
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [wd is uninitialized if all digits after decimal are '0'; also loop should start from 1 to handle input like "0.0"]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1);
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}