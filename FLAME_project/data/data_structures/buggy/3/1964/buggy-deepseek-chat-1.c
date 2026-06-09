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
        printf("e%d",-result-1); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", mid1=9, mid2=1, result=8, -result-1=-9, but the expected exponent is -8. The exponent should be -(number of zeros after decimal point before first non-zero digit) - 1, which is -(mid2 - mid1 - 1) = -(1 - 9 - 1) = 9? Actually, the correct exponent is -8, so the formula should be -(mid1 - mid2 - 1) = -(9 - 1 - 1) = -7? Let's recalculate: For 0.00000009123456789012, the first non-zero digit '9' is at position 9 (0-indexed), decimal point at position 1. The number of zeros after decimal is 7 (positions 2-8). The exponent should be -8 (since 9.123456789012e-8). The correct formula is -(mid1 - mid2 - 1) = -(9 - 1 - 1) = -7, which is wrong. Actually, the exponent is -(number of zeros after decimal before first non-zero digit) - 1 = -7 - 1 = -8. So the correct expression should be -(mid1 - mid2 - 1) - 1 = -(mid1 - mid2) = -result. But the code uses -result-1, which gives -9. The error is that the exponent should be -result, not -result-1.
    }
    else
    {
        printf("%c",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result); // @@ For the case where result >= 0 (number >= 1), the exponent should be positive (e.g., for 123.45, result=2, expected e2), but the code prints e-2. The exponent sign is wrong; it should be e%d without the minus sign.
    }
    return 0;
}