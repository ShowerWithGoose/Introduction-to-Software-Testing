#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str);
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]);
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ The exponent calculation is incorrect. For input like "0.00123", i starts at 2 and counts zeros after the decimal point, but the exponent should be -(i-2) or similar, not i-1. Also, the loop for printing digits may skip the first non-zero digit incorrectly.
    }
    else if(str[strlen(str)-1]=='0')
    {
        for(k=0;str[k]!='0';k++)
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]);
        }
        for(l=k;str[l]!='\0';l++);
        
        printf("e%d",l-1); // @@ The exponent calculation is incorrect. For numbers like "12300", the exponent should be the number of digits after the first digit minus the number of trailing zeros, but this code sets exponent to l-1 where l is the length, which is wrong. Also, the loop condition str[k]!='0' stops at the first '0', which may not be a trailing zero.
    }
    else
    {
        if(str[1]=='.')
        {
            printf("%s",str);
            printf("e0");
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]);
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ The exponent formula 2*m-n+1 is incorrect. For input "87899.9999999999000999", m is the index of the decimal point (5), n ends at the string length (20), so 2*5-20+1 = -9, but the correct exponent is 4. The exponent should be m-1 (number of digits before the decimal point minus one).
            }
    }
    return 0;
}