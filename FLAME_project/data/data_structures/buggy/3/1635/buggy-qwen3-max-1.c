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
        e=-i+1; // @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", i becomes 9 (index of '9'), so e = -9 + 1 = -8, which is correct, but the output lacks a decimal point after the first digit.]
        while(s[i]!='\0')
        {
            printf("%c",s[i]);
            i++;
        } // @@ [This prints all remaining digits without inserting a decimal point after the first digit, violating the scientific notation format which requires one digit before and one after the decimal point if more than one digit exists.]
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