#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a);
    n=strlen(a);
    for(i=1;i<=n;i++) // @@ Loop condition should be i<n; accessing a[n] (null terminator) is unnecessary and may cause logic errors.
    {
        int flag=0; // @@ Variable flag should be declared outside the loop to accumulate the count of leading zeros after the decimal point; reinitializing each iteration destroys the cumulative count.
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ Counting the decimal point as a zero leads to an incorrect exponent calculation; only zeros after the decimal should be counted.
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ The condition flag==n-1 is flawed because flag is reset each iteration and does not represent the correct count; also it incorrectly decides whether to print a decimal point.
                printf("%c",a[i]);
                else
                printf("%c.",a[i]); // @@ Always printing a decimal point after the first non-zero digit even when no further digits exist (e.g., input "0.5") results in an extraneous decimal point; the decimal point should be omitted when the base is an integer.
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ Exponent calculation is incorrect; for input "0.00123", flag (if correctly accumulated) should be 3 and exponent should be -3, but flag-1 = 2 gives -2; also due to flag reset the exponent may become negative (e.g., "e--1").
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