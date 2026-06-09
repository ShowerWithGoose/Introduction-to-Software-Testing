#include <stdio.h>
#include <string.h>
#include<math.h>
int main ()
{
    char a[1024];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is removed entirely, leading to a compilation error.]
    int i=0;
    int k=strlen(a);
    
    if(a[0]!='0')
    {
        while(a[i]!='.')
        {
            i=i+1;
        }
        printf("%c",a[0]);
        printf(".");
        for(int j=1;j<i;j++)
        {
            printf("%c",a[j]);
        }
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e%d",i-1);
    }
    else if(a[0]=='0')
    {
        while(a[i]=='0'||a[i]=='.')
        {
            i=i+1;
        }
        printf("%c",a[i]);
        printf(".");
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1); // @@ [Incorrect exponent calculation: when input is "0.00123", i becomes 3 (index of '1'), so exponent should be -(i-1) = -2, but actual correct exponent is -3. Also, if the number has no fractional digits after the first non-zero (e.g., "0.1"), this prints "1.e-0" which violates the requirement that exponent's integer part must have non-zero first digit for negative exponents (though -0 is mathematically odd). However, the primary compilation error stems from 'gets'.]
    }
    
    return 0;
}