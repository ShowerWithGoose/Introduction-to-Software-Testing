#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i; // @@ The index i is not incremented when a decimal point is found, causing the next character to overwrite the decimal point in the array.
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++); // @@ The loop should start from t+1 to correctly skip leading zeros after the decimal point.
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ The exponent calculation is incorrect; it should be l-t to represent the correct power of 10.
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ The exponent should be k-t, not k, to correctly calculate the negative exponent.
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++) // @@ This loop prints all characters including the decimal point, resulting in a duplicate decimal point in the output. It should skip the '.' character.
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}