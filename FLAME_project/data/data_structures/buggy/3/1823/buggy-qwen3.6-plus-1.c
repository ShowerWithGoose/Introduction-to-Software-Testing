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
        printf("%c.%se-%d",s[y],p,x+1); // @@ The output format includes a decimal point and potentially trailing characters incorrectly. For input "0.9", y points to '9', p points to empty string. It prints "9.e-1". The expected output is "9e-1" because the base should be an integer if there are no significant digits after the first one in the mantissa part derived from the original fractional part, or more accurately, the problem states: "If it’s a decimal, it must have one significant digit before and after the decimal point... If it’s an integer, it contains only one significant digit without a decimal point." Here, the significant digit is just '9'. Since there are no other significant digits following it in the normalized mantissa (the rest are zeros or non-existent), it should be printed as an integer "9", not "9.". Also, the logic for constructing the mantissa string `p` might include trailing zeros or be empty, but the primary issue here is forcing a decimal point when the resulting mantissa has only one significant digit total.
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]); // @@ Similar to the above case, this always prints a decimal point. If the number is like "500", the scientific notation is "5e2". The base is an integer "5". This code prints "5." then processes the rest. If the rest are zeros, it prints "5.00e2" or similar, which violates the "no trailing zeros" and "integer if only one significant digit" rule.
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