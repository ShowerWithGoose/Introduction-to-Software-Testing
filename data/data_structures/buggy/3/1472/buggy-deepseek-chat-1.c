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
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ The exponent calculation is incorrect. For numbers like 0.001, flag counts zeros and the decimal point, but the exponent should be -(number of zeros after decimal point before first non-zero digit), not flag-1. Also, flag is reset to 0 each iteration, so it doesn't accumulate correctly.
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
                printf("e%d",i-1); // @@ The exponent should be the number of digits before the decimal point minus 1, but this assumes the first digit is non-zero. However, if the number has multiple digits before the decimal (e.g., 123.45), the exponent should be 2, not i-1 (which would be 2 in this case, but the logic is fragile). More critically, the loop starts at i=1, so for numbers like 0.5, this branch is never entered because a[0]=='0', but for numbers like 1.23, it works. However, the exponent calculation is correct for the non-zero first digit case, but the loop condition and flag handling for the zero case are flawed.
                break;
                
            }
        }
    }
    return 0;        
}