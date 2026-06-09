#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, 'wc' and 'wd' are used uninitialized if no '.' is found.]
    int l,wc,wd; // @@ ['wc' and 'wd' are not initialized, leading to undefined behavior if the input has no decimal point or if conditions don't assign them.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Loop starts at i=1, so if '.' is at position 0 (impossible per problem but still), it's missed. More critically, if there's no '.', 'wc' remains uninitialized.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ ['wd' may remain uninitialized if all digits after "0." are zero, but problem states no trailing zeros, yet logic assumes at least one non-zero. However, if input is "0.0", which violates problem constraints, this fails. But more importantly, if the loop doesn't run (e.g., l=2 => "0."), then wd is uninitialized.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [If 'wd' was never set (e.g., input like "0." with no following digits), this uses uninitialized 'wd', causing undefined behavior.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}