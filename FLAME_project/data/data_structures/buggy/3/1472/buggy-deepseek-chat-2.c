#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a);
    n=strlen(a);
    for(i=1;i<=n;i++)
    {
        int flag=0;
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.')
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1)
                printf("%c",a[i]);
                else
                printf("%c.",a[i]); // @@ The base should be an integer (no decimal point) when there is only one significant digit after the decimal point, but this code always adds a decimal point when there are more digits, which is incorrect for cases like "0.9" where the output should be "9e-1" not "9.e-1".
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ The exponent calculation is incorrect; for input "0.9", flag is 1 (since a[1] is '.'), so flag-1 = 0, but the expected exponent is -1. The exponent should be -(i-1) or similar, not based on flag.
                break;
            }
        }
        else
        {
            if(a[i]=='.')
            {
                printf("%c.",a[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",a[j]);
                    
                } 
                for(j=i+1;j<n;j++)
                {
                    printf("%c",a[j]);
                    
                }
                printf("e%d",i-1);
                break;
                
            }
        }
    }
    return 0;        
}