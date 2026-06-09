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
        int flag=0; // @@ [Variable flag is declared inside the loop, causing it to reset to 0 on every iteration. It should be declared outside the loop to correctly accumulate the count of leading zeros and the decimal point.]
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.')
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ [The condition flag==n-1 is incorrect for detecting if the first non-zero digit is the last character. Since flag equals i-1, it should be i==n-1 or flag==n-2.]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [The exponent calculation is off by one. For numbers less than 1, the exponent should be -flag, not -(flag-1). It should be printf("e-%d",flag);]
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