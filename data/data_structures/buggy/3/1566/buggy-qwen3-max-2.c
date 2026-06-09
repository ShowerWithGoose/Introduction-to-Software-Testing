#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets` instead.]
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
            if(c[i++]=='0') // @@ [This condition checks only the first digit after the decimal point, but `m` may not be initialized if all digits after decimal are zero, leading to undefined behavior. Also, logic here doesn't handle cases correctly when trailing zeros exist or when number is exactly "0.0".]
            {
                printf("%ce0",c[n]);
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [Incorrectly prints a dot after every digit; should print digits without extra dots.]
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}