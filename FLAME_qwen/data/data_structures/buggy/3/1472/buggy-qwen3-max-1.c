#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to security concerns]
    n=strlen(a);
    for(i=1;i<=n;i++) // @@ [Loop starts at i=1 but accesses a[i] which may go out of bounds when i == n (since valid indices are 0 to n-1)]
    {
        int flag=0;
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ [When i == n, a[i] is '\0', leading to undefined behavior or incorrect logic]
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ ['flag' is always 0 or 1 here because it's set inside the loop per iteration, so this condition likely never holds as intended]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [If flag is 0 (which it usually is), exponent becomes -1, which is incorrect for cases like "0.001" needing e-3]
                break;
            }
        }
        else
        {
            if(a[i]=='.') // @@ [Again, a[i] when i == n is '\0', not '.', so this may miss the decimal point if it's at position n-1 or cause out-of-bound access]
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
                printf("e%d",i-1); // @@ [If decimal is at index d, exponent should be d-1, but loop starts at i=1 and increments before checking, so i may not equal actual decimal position]
                break;
                
            }
        }
    }
    return 0;        
}