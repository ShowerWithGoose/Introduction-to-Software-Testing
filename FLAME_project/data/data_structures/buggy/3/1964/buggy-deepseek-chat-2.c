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
        printf("e%d",-result-1); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", mid1=8, mid2=1, result=7, -result-1=-8, but expected exponent is -8. However, the output shows "e-8" which is correct, but the base output is wrong because it doesn't handle trailing zeros correctly and includes all digits after the first non-zero digit without proper formatting.
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
        printf("e-%d",result); // @@ The exponent sign is wrong for positive exponents. For numbers like "123.456", result would be positive, but the expected output should have a positive exponent without a minus sign (e.g., "1.23456e2"), but this code prints "e-2" which is incorrect.
    }
    return 0;
}