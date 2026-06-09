#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, wc is uninitialized if no '.' is found, leading to undefined behavior]
    int l,wc,wd;
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [wc is not initialized before this loop; if the input has no decimal point, wc remains uninitialized, causing unpredictable behavior in subsequent conditions]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [wd is not initialized before this loop; if all digits after '0.' are zero (which shouldn't happen per problem statement but still), wd remains uninitialized. Also, the loop overwrites wd on every non-zero digit, so it ends up pointing to the last non-zero digit instead of the first]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [This condition assumes that if the first non-zero digit is at the last position, output without decimal, but the logic for wd is flawed—it captures the last non-zero digit, not the first]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ [The exponent should be -(wd - 1), but since wd is the index of the first non-zero digit after "0.", the correct exponent is -(wd - 1). However, due to the loop assigning wd to the last non-zero digit instead of the first, the exponent is wrong. Also, the loop condition uses <= l-1 which includes the null terminator if l is miscalculated, but more critically, the logic fails to find the first non-zero digit.]

    }




return 0;
}