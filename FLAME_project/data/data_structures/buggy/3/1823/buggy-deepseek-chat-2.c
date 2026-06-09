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
        printf("%c.%se-%d",s[y],p,x+1); // @@ Error: For input "0.9", this branch is taken. s[0]=='0' is true. x=0, y=2, s[2]='9' is not '0', so loop doesn't execute. p = s+3 which is '\0'. Output becomes "9.e-1" but expected "9e-1". The issue is that when the first non-zero digit is immediately after the decimal point (no zeros after decimal), the base should be just the digit without a decimal point, and the exponent should be -1. The code incorrectly adds a decimal point and uses p which is empty.
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]); // @@ Error: For numbers like "1.23", this prints a decimal point after the first digit, but the problem requires that if the base is a decimal, it must have one digit before and after the decimal point. However, for numbers with more than one digit before the decimal point (e.g., "12.3"), this logic is incorrect because it only takes the first digit as the base, but the exponent calculation also needs adjustment. Additionally, for numbers like "1.0" (though not in test cases), trailing zeros are not allowed per spec.
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ Error: This prints all digits after the decimal point, but the base should only have one digit after the decimal point. Also, the exponent calculation x is the number of digits between the first digit and the decimal point, which is correct for exponent, but the base format is wrong.
    }
    return 0;
}