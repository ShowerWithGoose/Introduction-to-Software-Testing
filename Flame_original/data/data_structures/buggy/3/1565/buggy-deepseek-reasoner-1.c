#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s);
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++) // @@ Error: Loop continues beyond the first non‑zero digit, causing the exponent to be decremented for every character (including digits and the dot) instead of only for leading zeros. Also, the condition and logic are incorrect.
        {
            a--; // @@ Error: Decrements exponent for every index, including non‑zero digits and the decimal point, leading to an incorrect exponent.
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1) // @@ Error: This check is insufficient; it does not handle the case where the first non‑zero digit is the last character (e.g., "0.1"), leaving str without a decimal point. Also, trailing zeros are not removed.
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j]; // @@ Error: The offset calculation j-i+1 may produce incorrect indices and does not guarantee proper placement of digits after the decimal point.
                    str[1]='.';
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ Error: Starts at strlen(s) which is the index of the null terminator, causing out‑of‑range access to s[i] (the null character). Should start at strlen(s)-1.
        {
            if(s[i]!='.')
            {
                str[i]=s[i]; // @@ Error: This overwrites str at index i with s[i] but later the else‑if block will also write to str, resulting in incorrect content. Moreover, the loop copies characters from the end, which is not the intended behaviour.
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ Error: This loop copies digits starting from s[1] into str[2...i], but it does not correctly build the base string (e.g., the first digit before the decimal point should be s[0], not overwritten).
                    a++; // @@ Error: Increments exponent only once, but for numbers like "123.456" the exponent should be 2, not 1. Also, the exponent for numbers like "1.23" should be 0, but this code sets it to 1.
                str[0]=s[0];
                str[1]=s[i];
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ Error: str is not properly null‑terminated, so printing it as a string may produce garbage or undefined behaviour. Additionally, the exponent a is incorrect.
    return 0;
}