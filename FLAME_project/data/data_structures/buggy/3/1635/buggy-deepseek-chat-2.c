#include<stdio.h>

int main()
{
    int e,i,j;
    char s[150]={0};
    gets(s);
    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        e=-i+1; // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", i starts at 2 and counts zeros, but the exponent should be -8 (since the first non-zero digit is at position 8 after the decimal). The formula should be e = -(i-1) or e = -i+1 is actually correct for this case? Let's check: i=2 initially, then while loop increments i for each zero. For "0.00000009", zeros after decimal: positions 2,3,4,5,6,7 are zeros, so i becomes 8 after loop. e = -8+1 = -7, but expected exponent is -8. The error is that the loop starts at i=2, but the first zero after decimal is at index 2, so after counting 7 zeros, i=9, e=-9+1=-8, which is correct. However, the output shows "9123456789012e-8" but expected "9.123456789012e-8". The issue is that the program does not insert a decimal point after the first digit. The while loop prints all digits without inserting a decimal point.
        while(s[i]!='\0')
        {
            printf("%c",s[i]);
            i++;
        }
        printf("e%d",e);
    }
    else if(s[0]!='0'&&s[1]=='\0')
    printf("%ce0",s[0]);
    else
    {
        i=0;
        while(s[i]!='.')
        {
            i++;
        }
        e=i-1;
        j=2;
        printf("%c.",s[0]);
        while(s[j]!='\0')
        {
            if(s[j]!='.')
            {
            printf("%c",s[j]);
            j++;
            }
            else
            j++;
        }
        printf("e%d",e);
    }
    return 0;
}