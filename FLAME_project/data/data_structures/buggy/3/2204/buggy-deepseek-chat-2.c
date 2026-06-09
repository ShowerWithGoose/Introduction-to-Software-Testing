#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s);
    int l,wc,wd;
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
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ This line incorrectly updates wd for every non-zero digit, overwriting previous values, so wd ends up as the last non-zero digit index instead of the first. For input "0.00000009123456789012", wd becomes 18 (the last digit '2') instead of 9 (the first non-zero '9').
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ This line incorrectly checks if wd is the last index, but due to the bug above, wd is the last non-zero digit, so it prints only that digit without a decimal point, producing "2e-20" instead of "9.123456789012e-8".
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ This branch is not executed for the given input because wd equals l-1, but even if it were, it would start from the wrong index due to the first bug.

    }




return 0;
}