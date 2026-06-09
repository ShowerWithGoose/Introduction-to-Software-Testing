#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ Deprecated function; may cause compilation error in strict C11 mode. Also, unsafe buffer overflow.
    int l,wc,wd; // @@ Variables wc and wd are not initialized. If input has no decimal point, wc is undefined, leading to undefined behavior.
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i;
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ Logic error: This sets wd to the index of the last non‑zero digit, not the first one. It should break after finding the first non‑zero.
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ Wrong output: should print the first non‑zero digit followed by a decimal point and the remaining digits. Also exponent is miscalculated.
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ Same issue: uses last non‑zero digit as the start.

    }




return 0;
}