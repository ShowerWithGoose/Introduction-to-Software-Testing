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
    i--; @@ [The loop increments i only when the character is not '.', so the index i does not correctly represent the last valid character index after reading the newline. This causes incorrect string length handling.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1)) @@ [This condition checks if there's only one significant digit after leading zeros, but due to incorrect i (from above), it may misjudge cases like "0.9".]
        printf("%ce-%d",c[l],l);
        else
        {
            int k=l;
            printf("%c.",c[l]); @@ [For a single significant digit like "0.9", this prints "9." instead of "9", violating the requirement that integers in scientific notation should not have a decimal point.]
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]); @@ [This always prints a decimal point even when there's only one significant digit before the decimal and no fractional part needed, which violates the output format.]
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}