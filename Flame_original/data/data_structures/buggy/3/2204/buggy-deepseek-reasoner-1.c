#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s); // @@ [Error: gets() is unsafe and removed in C11; causes compilation error in strict C11 mode.]
    int l,wc,wd;
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i; // @@ [Error: C89 does not allow declaration inside for loop; causes compilation error in C89 mode.]
    if(wc>1) 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]); // @@ [Error: Same as above - declaration inside for loop not allowed in C89.]
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]!='0') 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]); // @@ [Error: Same as above - declaration inside for loop not allowed in C89.]
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]=='0') 
    {
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [Error: Same as above - declaration inside for loop not allowed in C89.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1);
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ [Error: Same as above - declaration inside for loop not allowed in C89.]

    }




return 0;
}