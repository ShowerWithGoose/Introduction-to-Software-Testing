#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks.]
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
            if(c[i++]=='0') // @@ [This condition checks only the first digit after the decimal point, but 'm' may not be initialized if all digits after '.' are zero, leading to undefined behavior. Also, logic flaw: should handle case where all fractional digits are zero.]
            {
                printf("%ce0",c[n]); // @@ [c[n] is '.', so this prints ".e0", which is invalid scientific notation.]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [Incorrectly prints a '.' after every digit in the mantissa, e.g., "1.2.3.e-2" instead of "1.23e-2".]
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}