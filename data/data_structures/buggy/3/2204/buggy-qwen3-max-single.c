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
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Loop starts at i=1, so it will miss a decimal point at index 0 (though per problem description, input always has digits before and after '.', so '.' won't be at start). However, more critically, if there's no '.' in the input (which shouldn't happen per problem constraints), 'wc' remains uninitialized, leading to undefined behavior in subsequent conditionals.]
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [Variable 'wd' is only assigned inside the loop if a non-zero digit is found. If all digits after '.' are zero (which shouldn't happen per problem statement: "no trailing zeros after the decimal point"), 'wd' remains uninitialized, leading to undefined behavior. Also, loop condition uses <= l-1, which is correct for 0-based indexing, but logic assumes at least one non-zero exists.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [If the last character is the first non-zero after decimal, this prints without a decimal point, which is correct per spec only if it's a single digit. But if input ends right after that digit, it's okay. However, 'wd' might be uninitialized if no non-zero digit exists, causing undefined behavior.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);}

    }




return 0;
}