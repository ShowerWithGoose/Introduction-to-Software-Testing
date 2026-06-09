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
        int flag=0; // @@ [The variable 'flag' is reinitialized to 0 in every iteration, so it cannot correctly count leading zeros before the first non-zero digit. It should be declared outside the loop and accumulate the count of leading zeros.]
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ [This condition incorrectly increments 'flag' for '.' or '0', but 'flag' is reset each loop iteration, making this logic ineffective. Also, accessing a[i] when i == n leads to out-of-bounds read (since valid indices are 0 to n-1).]
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ ['flag' is always 0 or 1 due to being reset each iteration, so this condition will never reflect the actual number of leading zeros. This causes wrong exponent calculation and formatting.]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]); // @@ [This prints a decimal point even when there are no following digits, which may lead to trailing '.' as seen in output "9." instead of "9".]
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [Because 'flag' is not counting correctly, the exponent becomes wrong. For input "0.9", it prints "e--1" because 'flag' is 0 here, so 0-1 = -1, but formatted as "e-%d" gives "e--1" due to another issue: the code prints "e-" followed by a negative number, resulting in double minus. Actually, the real issue is that the exponent logic is flawed and the format should just be "e%d" with a properly computed signed exponent.]
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