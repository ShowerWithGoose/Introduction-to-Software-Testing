#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Use 'fgets' instead.]
    int l,wc,wd;
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Variable 'wc' is used uninitialized if no '.' is found in the string, leading to undefined behavior. Also, loop condition should start from i=0 to handle numbers like "0.123" correctly.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [Variable 'wd' is used uninitialized if all digits after '.' are zero, which violates problem constraints but still leads to undefined behavior. Also, loop should break after finding first non-zero digit.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1);
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}