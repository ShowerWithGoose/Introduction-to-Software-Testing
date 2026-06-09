#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [gets() is unsafe and can cause buffer overflow; also, it's removed from C11 standard, but the main issue is the logic errors below]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i]; // @@ [This modifies the string incorrectly; it overwrites the character before the first non-zero digit, which may be '0' or '.', leading to incorrect output]
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [This logic is flawed; it places a '.' at position i, but the original '.' may be elsewhere, and the condition for setting '\0' is incorrect]
                for (int j=i-1;j<strlen(str);j++)
                {
                    printf("%c",str[j]);
                }
                printf("e-%d",i-1); // @@ [The exponent calculation i-1 is incorrect; it should be based on the position of the decimal point relative to the first significant digit]
                break;        
            }
        }
        if (str[0]!='0')
        {
            if (str[i]=='.')
            {
                
                printf("e%d",i-1); // @@ [This prints the exponent but does not output the base part of the scientific notation; also, the exponent calculation i-1 may be wrong if there are leading zeros or other digits]
            }
        }
    }
}