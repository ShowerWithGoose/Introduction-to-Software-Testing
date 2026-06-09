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
        printf("."); // @@ [When the number has only one non-zero digit before the decimal (e.g., "5.0"), the output should be "5e0", not "5.e0". The program always prints a decimal point even when there are no digits after it, violating the requirement that trailing zeros are not present and that if the base is an integer, it should have no decimal point.]
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
        printf("."); // @@ [For inputs like "0.9", the expected output is "9e-1", but this code outputs "9.e-1". According to the problem, if the base is an integer (only one significant digit), it should not have a decimal point. The code unconditionally prints a decimal point even when there are no following digits or when it's unnecessary.]
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}