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
        printf("."); // @@ This always prints a decimal point, but when the input is "0.9", the expected output is "9e-1" without a decimal point because the base should be an integer (one significant digit, no decimal point). The program should check if there are no additional digits after the first non-zero digit before printing the decimal point.
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
        printf("."); // @@ This always prints a decimal point, but when the input is "0.9", the expected output is "9e-1" without a decimal point because the base should be an integer (one significant digit, no decimal point). The program should check if there are no additional digits after the first non-zero digit before printing the decimal point.
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}