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
        int flag=0; // @@ The variable 'flag' is declared inside the loop and reset to 0 in every iteration, so it cannot correctly count the number of leading zeros or track state across iterations. It should be declared outside the loop.
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ This condition increments 'flag' for both '0' and '.', but 'flag' is intended to count leading zeros after the decimal point. Including '.' in the count or logic is incorrect for calculating the exponent. Also, since 'flag' is reset every loop, this logic is fundamentally broken.
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ This condition checks if the significant digit is the last character. However, 'flag' is always 0 or 1 due to being reset inside the loop, making this check unreliable for determining if there are trailing digits.
                printf("%c",a[i]);
                else
                printf("%c.",a[i]); // @@ For input "0.9", the first non-zero digit is '9'. The code prints "9." because flag (0) != n-1 (2). The problem states that if the base is an integer (one significant digit), it should not have a decimal point. Here, "9" is the base, so it should be printed as "9", not "9.".
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ The exponent calculation is wrong. For "0.9", the exponent should be -1. 'flag' is 0 here (incorrectly counted), so it prints e-1. While the value might accidentally match for some cases, the logic for calculating the exponent based on the position of the first non-zero digit is flawed due to the scope of 'flag'. The correct exponent for 0.d... is -(number of zeros after decimal + 1).
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