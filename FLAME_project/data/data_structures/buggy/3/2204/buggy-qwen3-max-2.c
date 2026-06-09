#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, wc and wd are used uninitialized if '.' is not found or conditions aren't met]
    int l,wc,wd;
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [wc is not initialized before use; if no '.' is found, wc remains uninitialized, leading to undefined behavior]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [wd is not initialized; if all digits after decimal are zero, wd remains uninitialized, but problem states no trailing zeros, so this may not trigger—but logic fails to break after first non-zero digit, overwriting wd repeatedly]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [Incorrect condition: should check if there are no digits after the first non-zero, but loop sets wd to last non-zero, not first. Also, exponent should be -(wd - 1), but wd is index in string including '0.', so for "0.000...9", first non-zero at position i, exponent is -(i-1). However, code uses wd-1 which is correct only if wd is first non-zero, but loop doesn't stop at first non-zero—it keeps going, so wd ends up as last non-zero digit index, not first.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ [Same issue: wd is last non-zero digit, not first. Should break after finding first non-zero digit.]

    }




return 0;
}