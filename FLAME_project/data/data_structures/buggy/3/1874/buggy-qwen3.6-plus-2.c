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
        printf("e-%d",i-1);
    }
    else if(str[strlen(str)-1]=='0') // @@ The condition checks if the last digit is '0', but the problem states there are no trailing zeros. More importantly, this branch incorrectly handles numbers like 87899.99... which do not end in 0, causing it to fall into the else block where the exponent calculation is wrong. Even if it entered here, the logic for finding the first non-zero digit and constructing the mantissa is flawed for general cases. However, the primary issue for the specific test case 87899.9999999999000999 is that it does NOT end in '0' (it ends in '9'), so it goes to the else block.
    {
        for(k=0;str[k]!='0';k++)
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]);
        }
        for(l=k;str[l]!='\0';l++);
        
        printf("e%d",l-1);    
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
        printf("e%d",2*m-n+1); // @@ The exponent calculation is incorrect. For input 87899.9..., m (index of '.') is 5. The number of digits before the decimal point is m. The exponent should be m-1 (which is 4). The formula 2*m-n+1 depends on n (total length), which is incorrect. The exponent in scientific notation for a number with D digits before the decimal point is D-1. Here D=m. So exponent should be m-1.
            }
    }
    return 0;
}