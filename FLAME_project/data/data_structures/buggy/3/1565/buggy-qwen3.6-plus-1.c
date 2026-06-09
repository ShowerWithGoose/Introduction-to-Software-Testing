#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s);
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++)
        {
            a--;
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1)
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j];
                    str[1]='.';
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ The loop condition and logic for finding the decimal point and constructing the mantissa are flawed. It iterates backwards but doesn't correctly handle the position of the decimal point relative to the first digit to calculate the exponent or construct the normalized string properly. Specifically, it fails to count the number of digits before the decimal point to determine the exponent.
        {
            if(s[i]!='.')
            {
                str[i]=s[i]; // @@ This copies characters to incorrect indices in 'str', leading to garbage values or incorrect ordering in the output string.
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++) // @@ This loop attempts to shift digits but uses incorrect indices and doesn't account for the correct normalization (moving decimal after first digit).
                    str[j]=s[j-1];
                    a++; // @@ The exponent calculation is incorrect. For a number like 87899.9..., the exponent should be the number of digits before the decimal minus 1 (4 in this case). Here 'a' is just incremented once, resulting in 1.
                str[0]=s[0];
                str[1]=s[i]; // @@ This places the decimal point at index 1, which is correct for the format "d.d...", but the surrounding logic for filling the rest of the string and calculating the exponent is wrong.
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ The output relies on the incorrectly constructed 'str' and incorrect exponent 'a'.
    return 0;
}