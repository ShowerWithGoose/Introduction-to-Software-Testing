#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ gets() is deprecated/removed in modern C standards and may cause compilation errors; use fgets() instead.
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
        for(int i=strlen(s);i>=1;i--)
        {
            if(s[i]!='.')
            {
                str[i]=s[i]; // @@ Incorrectly copies characters to the same index in str, which will be overwritten later and does not construct the mantissa correctly.
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ Incorrectly shifts digits and overwrites str. Fails to skip the original decimal point, resulting in duplicate dots or misplaced digits.
                    a++; // @@ Exponent should be calculated as the position of the decimal point minus 1, not simply incremented.
                str[0]=s[0];
                str[1]=s[i]; // @@ Sets str[1] to '.', but the mantissa construction is already broken. Also, str is never null-terminated.
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ str is not null-terminated, causing undefined behavior and potential garbage output.
    return 0;
}