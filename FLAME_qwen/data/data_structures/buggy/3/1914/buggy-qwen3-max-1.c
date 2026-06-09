#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[150];
char res[150];
int main ()
{
    int i=0,j=0,k=0,l=2,m=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, 'gets' is not available, which may lead to compilation errors or linker failures.]
    
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
                 res[1]=='.';
                 l=2;
                 for(k=k+1;k<strlen(s);k++)
            {
           
                res[l++]=s[k];
            
            }
            }
            fputs(res,stdout); // @@ [If the input is like "0.001", then after extracting '1', res[1] was assigned using '==' (comparison) instead of '=' (assignment), so res[1] remains uninitialized. Also, if k == strlen(s)-1 (i.e., only one non-zero digit at end), then res[1] is never set and fputs prints garbage beyond res[0].]
            printf("e-");
            printf("%d",m);
        }
    }

    return 0;
}