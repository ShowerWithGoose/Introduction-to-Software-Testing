#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[150];
char res[150];
int main ()
{
    int i=0,j=0,k=0,l=2,m=0;
    gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, some compilers may not support it, leading to compilation errors.]

    while(s[i]!='.')
    {
        i++;
    }
    j=strlen(s)-i-1;

    if(i>1)
    {
        res[0]=s[0];
        res[1]='.';
        
        for(k=1;k<strlen(s);k++)
        {
            if(s[k]!='.')
            {
                res[l++]=s[k];
            }
        }
        fputs(res,stdout);
        printf("e");
        printf("%d",i-1);
    }
    else if(i==1)
    {
        if(s[0]!='0')
        {
            fputs(s,stdout);
            printf("e");
            printf("0");
        }
        else if(s[0]=='0')
        {
            k=2;
            while (s[k]=='0')
            {
                k++;
            }
            m=k-1;
            res[0]=s[k];
            if(k!=strlen(s)-1)
            {
                 res[1]=='.',; // @@ [Syntax error: using '==' instead of '=' for assignment. Also, stray comma after the statement.]
                 l=2;
                 for(k=k+1;k<strlen(s);k++)
            {
           
                res[l++]=s[k];
            
            }
            }
            fputs(res,stdout);
            printf("e-");
            printf("%d",m);
        }
    }

    return 0;
}