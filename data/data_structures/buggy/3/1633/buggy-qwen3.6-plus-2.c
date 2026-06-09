#include <stdio.h>
#include <string.h>
#include<math.h>
int main ()
{
    char a[1024];
    gets(a);
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
        printf("."); // @@ This line unconditionally prints a decimal point, but if there are no remaining digits after the first significant digit, the base should be an integer without a decimal point according to the problem description.
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}