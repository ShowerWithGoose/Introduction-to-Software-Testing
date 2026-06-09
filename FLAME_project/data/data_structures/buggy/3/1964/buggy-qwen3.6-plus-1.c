#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num);
    len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]=='.')
        mid2=i;
        else if(num[i]!='0'&&flag==0)
        {
            mid1=i;
            flag=1;
        }
    }  
    result=mid1-mid2;
    if(result<0)
    {
        printf("%c.",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e%d",-result-1); // @@ The exponent calculation is incorrect. For a number like 0.000...d, if the first non-zero digit is at index mid1 and the decimal point is at mid2, the exponent should be -(mid2 - mid1). Since result = mid1 - mid2 is negative, the exponent is result. For example, 0.01 (mid1=3, mid2=1, result=2? No. 0.01: mid2=1, mid1=3. result = 3-1=2. This logic is flawed for < 1. Let's re-evaluate. 0.00000009123456789012. mid2=1. First non-zero '9' is at index 9. mid1=9. result = 9-1=8. result > 0. So it goes to else branch.
    }
    else
    {
        printf("%c",num[mid1]); // @@ Missing decimal point after the first significant digit for numbers >= 1 or when the first non-zero digit is before the decimal point. However, the problem states input has digits before and after decimal point. If input is 0.xxx, mid1 > mid2. result > 0. The output format requires a decimal point after the first digit. e.g., 9.123...
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result); // @@ The exponent sign is wrong. If result > 0 (meaning mid1 > mid2, so the number is 0.00...something), the exponent should be negative. But the format string uses "e-%d", which prints a minus sign. If result is 8, it prints e-8. This part is actually correct for the sign. However, the base is missing the decimal point.
    }
    return 0;
}