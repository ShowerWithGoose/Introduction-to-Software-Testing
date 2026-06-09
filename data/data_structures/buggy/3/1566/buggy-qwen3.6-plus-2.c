#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='.')
        n=i;
         
    }
    if(strlen(c)==1)
    {
        printf("%ce0",c[0]);
    }
    else if(strlen(c)==3&&c[0]=='0')
    {
        printf("%ce-1",c[2]);
    }
    else
    {
        if(c[0]!='0')
        {
            e=n-1;
            for(i=n;i>1;i--)
            {
                c[i]=c[i-1];
            
            }
        
            c[1]='.';
            for(i=0;i<strlen(c);i++)
            {
                printf("%c",c[i]);
                
            }
            printf("e%d",e);
        }
        else
        {
            for(i=n+1;i<strlen(c);i++)
            {
                if(c[i]!='0')
                {
                    m=i;
                    e=m-n;
                    break;
                }
        
            }
            i=n+1;
            if(c[i++]=='0') // @@ Logic error: Incorrectly checks the first digit after the decimal point. For inputs with leading zeros after the decimal (e.g., "0.005"), this condition evaluates to true and executes the wrong branch.
            {
                printf("%ce0",c[n]); // @@ Logic error: c[n] is the decimal point '.', so this prints ".e0" instead of the correct significant digit and exponent.
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Format error: Incorrectly appends a dot after every subsequent digit, resulting in malformed output like "1.2.3." instead of "1.23".
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}