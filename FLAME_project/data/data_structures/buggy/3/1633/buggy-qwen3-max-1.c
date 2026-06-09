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
        printf("."); // @@ [Always prints a decimal point even when there are no digits after it, violating the requirement that trailing zeros are not allowed and that if the base is an integer (only one significant digit), it should not have a decimal point. For example, input "5.0" (though not in test case) or effectively "9" as base should output "9e..." not "9.e...". In test case "0.9", this branch isn't taken, but the else branch has similar issue.]
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
        printf("."); // @@ [Always prints a decimal point even when there are no digits after the significant digit. According to the problem, if the base has only one significant digit and no fractional part needed, it should be printed as an integer without a decimal point. In test case "0.9", after skipping '0' and '.', i becomes 2 (pointing to '9'), then it prints "9." followed by nothing (since j starts at i+1=3 which is beyond string length), resulting in "9.e-1" instead of "9e-1".]
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}