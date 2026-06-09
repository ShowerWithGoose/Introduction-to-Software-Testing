#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10000],b[10000],c[10000];
    scanf("%s",a);
    int h=strlen(a);
    if(h!=1)
    {
            if(a[0]=='0')
    {
        int u;
        int v=2;
        for(int i=2;i<h;i++) // @@ The loop starts from index 2, but the decimal point is at index 1, so it skips checking index 1 which could be a non-zero digit after the decimal point. For input like "0.5", it will miss the '5' at index 1.
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        }
        c[0]=a[u];
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++)
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1); // @@ The exponent calculation is incorrect. For input "0.5", u would be 2 (if the loop started correctly), but the exponent should be -1 (since 0.5 = 5e-1), not u-1 = 1. The exponent should be -(u-2) or similar to account for the decimal point position.
    }
    else{
        int m;
        int n=2;
        b[0]=a[0];
        b[1]='.';
        for(int i=1;i<h;i++)
        {
            if(a[i]=='.') m=i;
            else {
                b[n]=a[i];
                n++;
            }
        }
        for(int i=0;i<n;i++)
        printf("%c",b[i]);
        printf("e");
        printf("%d",m-1); // @@ The exponent calculation is incorrect. For input "12.34", m would be 2 (index of '.'), so m-1 = 1, but the correct exponent should be 1 (since 12.34 = 1.234e1). However, for input "1.234", m=1, m-1=0, which is correct. But for input "123.4", m=3, m-1=2, which is correct. The issue is that the exponent should be the number of digits before the decimal point minus 1, which is m-1 only if the first digit is non-zero and there are no leading zeros. This is actually correct for valid inputs where the first digit is non-zero.
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}