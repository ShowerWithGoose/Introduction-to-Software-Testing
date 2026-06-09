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
            i=n+1; // @@ This line resets i incorrectly, leading to a redundant check that always goes to the wrong branch.
            if(c[i++]=='0') // @@ This condition is unnecessary and causes the program to enter the wrong branch for numbers like 0.000...; should be removed.
            {
                printf("%ce0",c[n]); // @@ Incorrect output for scientific notation; prints a dot and 'e0' instead of the actual mantissa and exponent.
            }
            else
            {
                printf("%c.",c[m]); // @@ Prints the first non-zero digit and a dot, but the following loop adds extra dots.
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Each remaining digit is printed with an extra dot, corrupting the mantissa.
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}