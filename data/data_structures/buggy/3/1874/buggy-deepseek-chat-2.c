#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ gets() is unsafe and may cause buffer overflow; also, it's not standard C and may not be available in all compilers. Use fgets() instead.
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ This loop does not handle the case where the number is "0.0" or has no non-zero digits after the decimal point. Also, it assumes the format is "0.xxx", but the problem allows numbers like "0.5" where the first digit after decimal is non-zero.
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]); // @@ This logic incorrectly places the decimal point. It should output the first non-zero digit, then a decimal point, then the remaining digits. The ternary operator condition is wrong.
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ The exponent calculation is incorrect. For input like "0.001", i would be 4 (after skipping two zeros), but the exponent should be -3, not i-1=3.
    }
    else if(str[strlen(str)-1]=='0') // @@ This condition incorrectly assumes trailing zeros exist, but the problem states there are no trailing zeros after the decimal point. This branch may never be executed correctly.
    {
        for(k=0;str[k]!='0';k++) // @@ This loop will stop at the first '0' character, which may be part of a number like "10.5", causing incorrect output.
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ Same issue with decimal point placement as above.
        }
        for(l=k;str[l]!='\0';l++); // @@ This loop just counts to the end of string, but l is not used correctly for exponent calculation.
        
        printf("e%d",l-1); // @@ Exponent calculation is incorrect and does not follow the problem specification.
    }
    else
    {
        if(str[1]=='.')
        {
            printf("%s",str); // @@ This prints the original number, but the problem requires scientific notation with one digit before the decimal point. For numbers like "1.23", this would output "1.23e0", which is correct, but for numbers like "12.34", it would incorrectly output "12.34e0" instead of "1.234e1".
            printf("e0");
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]); // @@ This incorrectly places a decimal point after the second digit, but the base should have only one digit before the decimal point.
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ The exponent calculation is incorrect and does not follow the problem specification.
            }
    }
    return 0;
}