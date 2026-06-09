#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern compilers; use fgets() instead.
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1]; // @@ Semantic error: accessing s[i-1] when i=0 leads to out-of-bounds memory access (undefined behavior).
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ Logical error: incomplete range validation; fails to check s[i-1]<='9' and s[i+1]>='0', allowing mixed types to pass.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Logical error: incomplete range validation; fails to check s[i-1]<='Z' and s[i+1]>='A', allowing mixed types to pass.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Logical error: incomplete range validation; fails to check s[i-1]<='z' and s[i+1]>='a', allowing mixed types to pass.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
        }
        else
        printf("%c",s[i]);
    }
    return 0;
}