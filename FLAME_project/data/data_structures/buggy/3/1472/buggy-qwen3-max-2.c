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
        int flag=0; // @@ [flag is reinitialized to 0 in every iteration, so it cannot accumulate the count of leading zeros after '0.']
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.')
            flag++; // @@ [This only increments flag once per iteration but doesn't track total leading zeros correctly; also, when a[i]=='.', it shouldn't count as a zero digit]
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ [This condition is incorrect: flag is always 0 or 1 due to reinitialization, and n-1 is not the right comparison for determining if it's the last digit]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [Because flag is not counting the correct number of leading zeros, the exponent is wrong; also, the format prints "e--1" when flag is 0, leading to double minus]
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