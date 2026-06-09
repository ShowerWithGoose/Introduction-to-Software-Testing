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
        for(int i=strlen(s);i>=1;i--) // @@ The loop starts from strlen(s) which is the index of the null terminator '\0'. It should start from strlen(s)-1 to process the last digit. Also, the logic for constructing the scientific notation string 'str' is flawed. It attempts to shift characters but fails to correctly form the "digit.digits" format and calculate the exponent.
        {
            if(s[i]!='.')
            {
                str[i]=s[i]; // @@ This copies digits to their original indices in 'str', leaving str[0] and other positions uninitialized or incorrect for the desired output format.
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++) // @@ This loop shifts digits before the decimal point, but the indexing and logic are incorrect for forming the mantissa.
                    str[j]=s[j-1];
                    a++; // @@ The exponent calculation is incorrect. For a number like 87899.9..., the exponent should be the number of digits before the decimal point minus 1 (e.g., 5-1=4). Here 'a' is just incremented once.
                str[0]=s[0]; // @@ This sets the first digit, but the rest of the string 'str' is not correctly formed as "d.ddd...".
                str[1]=s[i]; // @@ This places the decimal point at index 1, but the subsequent digits are not correctly placed.
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ The output relies on 'str' being a correctly null-terminated string representing the mantissa and 'a' being the correct exponent. Both are incorrect due to the logic errors above.
    return 0;
}