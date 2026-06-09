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
                printf("%c.",a[i]); // @@ The base should be printed without a decimal point when there is only one significant digit after removing leading zeros. For input "0.9", the output becomes "9." instead of "9".
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ The exponent calculation is incorrect. For input "0.9", flag is 1 (since i=1, a[1]='.', flag increments to 1), so exponent becomes "e-0", but expected is "e-1". The exponent should be -(i-1) or similar, not flag-1.
                break;
            }
        }
        else
        {
            if(a[i]=='.')
            {
                printf("%c.",a[0]); // @@ The base should not have a decimal point if there is only one digit after the decimal point in the original number. For example, if input is "1.0", this would incorrectly print "1." instead of "1". However, the problem states no trailing zeros, so this may be acceptable for some cases, but the logic is flawed for numbers like "0.9" which are handled in the other branch.
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