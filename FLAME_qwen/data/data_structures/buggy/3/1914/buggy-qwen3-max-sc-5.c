#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[150];
char res[150];
int main ()
{
    int i=0,j=0,k=0,l=2,m=0;
    gets(s); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, may not be available in modern compilers leading to compilation error]
    
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
                 res[1]=='.', // @@ [Assignment operator '=' is needed instead of comparison operator '=='; this causes logical error and possibly undefined behavior due to uninitialized res[1]]
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