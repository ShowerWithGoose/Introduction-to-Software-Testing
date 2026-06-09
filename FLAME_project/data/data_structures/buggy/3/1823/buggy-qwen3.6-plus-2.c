#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s);
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1;
        printf("%c.%se-%d",s[y],p,x+1); // @@ The output format includes a decimal point and potentially trailing characters incorrectly. For input "0.9", y points to '9', p points to empty string. Output becomes "9.e-1". Expected is "9e-1". The logic for printing the mantissa as an integer when it has only one significant digit is missing, and the decimal point is always printed.
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]); // @@ Always prints a decimal point after the first digit. If the number is an integer like "123", scientific notation should be "1.23e2" which is fine, but if the resulting mantissa has no fractional part (e.g. input "1.0" though problem says no trailing zeros, so maybe not applicable). However, the main issue is in the '0' case. Let's look closer. If input is "12.3", s[0]='1'. Prints "1.". Then loop prints "2". x becomes 1. Loop stops at '.'. Then prints "3e1". Result "1.23e1". This looks correct for non-zero start.
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x);
    }
    return 0;
}