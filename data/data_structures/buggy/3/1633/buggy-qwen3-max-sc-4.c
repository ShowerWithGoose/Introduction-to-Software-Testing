#include <stdio.h>
#include <string.h>
#include<math.h>
int main ()
{
    char a[1024];
    gets(a); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
        printf("e-%d",i-1); // @@ [Incorrect exponent calculation: should be -(i-1) but printed as negative literal; also fails when there are no digits after the first non-zero (e.g., "0.0" or "0.1" with no further digits)]
    }
    
    return 0;
}