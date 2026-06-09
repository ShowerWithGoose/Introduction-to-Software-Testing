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
        printf("%ce-1",c[2]); // @@ Error: This condition is too specific and does not handle all cases where the number is less than 1 (e.g., "0.001" has length 5, not 3). Also, the output format is incorrect; it should include a decimal point for the base when there are digits after the decimal.
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
            if(c[i++]=='0') // @@ Error: This condition incorrectly checks the next character after the decimal point using post-increment, which modifies i and may skip characters. It also does not correctly handle cases where all digits after the decimal are zero (e.g., "0.0").
            {
                printf("%ce0",c[n]); // @@ Error: This output is incorrect for numbers like "0.0"; it should output "0e0" but the base should be a single digit without decimal point.
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Error: This prints a '.' after every digit, which is incorrect. It should only have one decimal point after the first digit.
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}