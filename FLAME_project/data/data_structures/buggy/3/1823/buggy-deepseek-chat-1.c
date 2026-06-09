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
        printf("%c.%se-%d",s[y],p,x+1); // @@ Error: For input "0.9", this branch is taken. s[0]=='0', then y=2, s[2]='9' (not '0'), so loop doesn't execute. x=0, p = s+3 which is '\0'. Output becomes "9.e-1" but expected "9e-1". The issue is that when the first non-zero digit is immediately after the decimal point (no leading zeros after decimal), the output should not include a decimal point in the base because the base is an integer (only one significant digit). The code incorrectly adds a '.' and also prints the trailing null character as part of p.
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]); // @@ Error: For numbers like "1.23", this always adds a decimal point after the first digit, but if the number has only one significant digit before the decimal and no digits after (e.g., "1.0" but input has no trailing zeros), the base should be an integer without a decimal point. However, the problem states input has digits before and after decimal, so this branch may be correct for typical cases, but the logic for exponent calculation and handling of trailing digits after decimal point may be flawed. Specifically, the exponent calculation x counts digits before decimal, but the exponent should be the number of places the decimal point moved, which for numbers like "1.23" should be 0, but here x=1 (since one digit '2' before decimal), so output would be "1.23e1" which is wrong.
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ Error: This prints all digits after decimal point, but the base should have only one digit after decimal point (if base is decimal). Also, exponent x is the count of digits before decimal, which is incorrect; exponent should be the number of places the decimal point moved from its original position to after the first non-zero digit.
    }
    return 0;
}