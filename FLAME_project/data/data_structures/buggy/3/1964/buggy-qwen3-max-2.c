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
    result=mid1-mid2; // @@ [This computes the wrong exponent offset. For numbers < 1 (like 0.000...), mid1 > mid2, so result > 0, but it should be negative. The logic for exponent sign and magnitude is inverted.]
    if(result<0) // @@ [Because of the incorrect 'result' calculation, this condition is backwards. For input "0.00000009...", mid1=8, mid2=1, so result=7 (>0), so it goes to the else branch, which is wrong.]
    {
        printf("%c.",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e%d",-result-1); // @@ [Even if the condition were correct, the exponent formula is off by one in some cases. But the main issue is the sign/logic inversion above.]
    }
    else
    {
        printf("%c",num[mid1]); // @@ [For small numbers like 0.00000009..., this prints only the first significant digit without a decimal point, but scientific notation requires one digit before and after the decimal (e.g., "9.123...").]
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result); // @@ [The exponent sign is forced negative here, but 'result' is positive for small numbers, leading to wrong sign and magnitude (e.g., e-7 instead of e-8). Also, missing decimal point in mantissa.]
    }
    return 0;
}