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
    result=mid1-mid2; // @@ [This computes the wrong exponent offset. When the first non-zero digit is after the decimal point, the exponent should be -(number of zeros after decimal + 1), but this logic doesn't correctly account for the position relative to the decimal point.]
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
        printf("e%d",-result-1); // @@ [The exponent calculation is off by one due to incorrect interpretation of positions. For input "0.00000009123...", mid1=9 (index of '9'), mid2=1 ('.' position). So result = 9 - 1 = 8, then -result-1 = -9, but expected exponent is -8. The correct exponent should be -(mid1 - mid2 - 1) = -(9 - 1 - 1) = -7? Wait—actually, the issue is deeper: the exponent should be (position of first non-zero digit relative to where the decimal would be in normalized form). In 0.00000009..., the '9' is at 10^-8 place, so exponent is -8. But current logic gives -9. Hence, the formula is wrong.]
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
        printf("e-%d",result); // @@ [In the case where the number is >= 1 (e.g., "123.45"), mid1 is index of first non-zero (which is '1' at index 0), mid2 is index of '.', so result = 0 - 3 = -3, which goes into the other branch. So this branch may never be taken correctly. Also, the sign of the exponent is inverted: it prints "e-%d" when result is positive, but if result = mid1 - mid2 > 0, that would imply the first non-zero is after the decimal? Actually, this branch logic is flawed because if the number starts with non-zero before '.', mid1 < mid2, so result < 0, so this else branch handles numbers like "0.0...nonzero", but wait—that contradicts. Actually, the entire logic of using mid1 and mid2 and their difference is fundamentally incorrect for determining the exponent.]
    }
    return 0;
}