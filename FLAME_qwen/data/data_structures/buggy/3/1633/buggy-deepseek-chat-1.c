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
        printf(".");
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1); // @@ The exponent calculation is incorrect. For numbers like 0.001, the exponent should be -(number of zeros after decimal point + 1), but i-1 gives the wrong value. The correct exponent should be -(i-2) when starting from index 0, or more precisely, the exponent should be -(position of first non-zero digit after decimal point). Also, the while loop condition may skip the decimal point incorrectly, leading to an off-by-one error in i.
    }
    
    return 0;
}