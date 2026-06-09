#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    int l,wc,wd; // @@ [Variables 'wc' and 'wd' are used without being initialized, which leads to undefined behavior. In particular, if no '.' is found in the string, 'wc' remains uninitialized, causing incorrect logic flow.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Loop starts at i=1, so it will miss a decimal point at index 0 (though per problem description, input always has digits before '.', so maybe acceptable). However, if there's no '.', 'wc' remains uninitialized, leading to unpredictable behavior in subsequent conditionals.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [If all digits after "0." are zero (which shouldn't happen per problem constraints), 'wd' remains uninitialized. Also, loop condition uses <= l-1, but string indices go from 0 to l-1, so this is okay. However, if no non-zero digit is found, 'wd' is uninitialized, leading to undefined behavior below.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [If 'wd' was never set (e.g., input like "0.0" — though disallowed by problem — or due to logic error), this accesses garbage value. Also, even if valid, when wd == l-1, it means last character is non-zero, but printing only one digit without decimal part is correct only if it's the only significant digit. However, the bigger issue is uninitialized 'wd'.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}