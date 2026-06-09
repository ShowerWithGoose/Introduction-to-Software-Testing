#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ The exponent should be -(l) but the output format for a single digit base should not include a decimal point. For input "0.9", l=1, i=1, so i==(l+1) is true, but the expected output is "9e-1" without a decimal point. The condition should check if there is only one significant digit after the leading zeros, and output without a decimal point.
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ The exponent should be -(k) but the output format for multiple digits should include a decimal point. However, for input "0.9", this branch is not taken because i==(l+1) is true. The issue is that the condition i==(l+1) incorrectly handles the case where there is exactly one digit after the decimal point and no trailing zeros, but the base should be an integer without a decimal point.
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}