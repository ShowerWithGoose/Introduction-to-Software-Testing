#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Additionally, 'wc' and 'wd' are used uninitialized if conditions aren't met, leading to undefined behavior.]
    int l,wc,wd; // @@ ['wc' and 'wd' are not initialized, which leads to undefined behavior when they are used in comparisons or computations without being assigned a value first.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [If there's no '.' in the input string, 'wc' remains uninitialized, causing undefined behavior in subsequent condition checks.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [If all digits after the decimal point are zero (which shouldn't happen per problem constraints but still), 'wd' remains uninitialized, leading to undefined behavior. Also, loop condition should likely be i < l instead of i <= l-1 for clarity and correctness.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [Accessing 'wd' without ensuring it was set leads to undefined behavior. Also, if the non-zero digit is at the last position, this prints only one digit without a decimal point, which may violate output format requiring either one digit (integer) or one before and after decimal. However, per problem, trailing zeros don't exist, so this case might be valid, but 'wd' must be guaranteed to be set.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}