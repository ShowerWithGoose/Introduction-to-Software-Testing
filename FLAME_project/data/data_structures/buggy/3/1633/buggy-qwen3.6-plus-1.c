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
        // @@ The problem states that if the base is an integer (only one significant digit), it should not have a decimal point. Here, for inputs like "9.0" or potentially single digit integers before decimal logic, we need to check if there are any non-zero digits after the decimal point or if the number is effectively an integer in scientific notation base. However, looking at the specific failure case 0.9, this branch is for non-zero starting digits. Let's look at the else branch.
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
        // @@ For the input "0.9", i becomes 2 (skipping '0' and '.'). a[2] is '9'. The code prints "9". Then it unconditionally prints ".". The problem states: "If it’s an integer, it contains only one significant digit without a decimal point." In scientific notation for 0.9, the base is 9 (integer) because there are no digits after the 9 in the original mantissa that are significant/non-zero? Wait, the input is 0.9. The scientific notation is 9e-1. The base is 9. It is an integer. So no decimal point should be printed if there are no remaining digits.
        printf(".");
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}