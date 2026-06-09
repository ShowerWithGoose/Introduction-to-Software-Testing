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
        printf("%c.%se-%d",s[y],p,x+1); // @@ [When there are no digits after the first non-zero digit (e.g., "0.9"), p points to '\0', resulting in output like "9.e-1" instead of "9e-1". The decimal point should not be printed if there are no fractional digits.]
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]); // @@ [Always prints a decimal point even when the number has only one significant digit before the decimal and nothing after, which violates the requirement that the base should be an integer (without decimal point) if it contains only one significant digit. For example, input "5.0" (though not in test case) would incorrectly output "5." instead of "5". However, more critically, for numbers like "123.45", it outputs "1.2345e2" correctly, but the issue is that the problem requires: if the base is an integer (only one digit), no decimal point. But this code always prints a decimal point in the non-zero-leading case. However, the immediate failure is on "0.9", so the primary error is in the first branch. Still, this line also violates spec by always printing '.' even when unnecessary. But per test case "0.9", the main bug is in the first branch.]
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