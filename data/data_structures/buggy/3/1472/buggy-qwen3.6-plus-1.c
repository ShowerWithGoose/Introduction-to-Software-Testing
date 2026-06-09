#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a); // @@ [Compilation Error] 'gets' is unsafe and removed in the C11 standard, which often causes compilation failures in modern environments. It should be replaced with 'fgets(a, sizeof(a), stdin);'.
    n=strlen(a);
    for(i=1;i<=n;i++)
    {
        int flag=0; // @@ [Logical Error] Declaring and initializing 'flag' inside the loop resets it to 0 on every iteration, preventing it from correctly counting the leading zeros and decimal point. It must be declared outside the loop.
        
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
                printf("e-%d",flag-1); // @@ [Logical Error] The exponent calculation is off-by-one. 'flag' (or 'i-1') already represents the correct magnitude for the negative exponent, so subtracting 1 results in an incorrect exponent value.
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