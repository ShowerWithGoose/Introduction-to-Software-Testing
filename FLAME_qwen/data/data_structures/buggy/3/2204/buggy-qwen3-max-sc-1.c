#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    int l,wc,wd; // @@ [Variables 'wc' and 'wd' are used uninitialized. If no '.' is found, 'wc' remains uninitialized, leading to undefined behavior.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Loop starts at i=1, so if the decimal point is at index 0 (e.g., ".5"), it will be missed. Also, 'wc' may remain uninitialized if no '.' exists.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ ['wd' may remain uninitialized if all digits after "0." are zero, but problem states no trailing zeros, yet logic assumes at least one non-zero. Still, if input ends right after "0." (e.g., "0."), this loop doesn't run and 'wd' stays uninitialized.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [If 'wd' is uninitialized, this leads to undefined behavior. Also, condition 'wd==l-1' assumes last character is non-zero digit, but indexing may be off.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}