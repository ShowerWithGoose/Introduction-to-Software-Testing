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
        printf("%c.",s[0]); // @@ [Always prints a decimal point even when there may be no fractional part in the normalized form. According to the problem, if the base is an integer with one significant digit, it should not have a decimal point. For example, input "5.0" (though not in test case) would incorrectly output "5.e0". However, more critically, this branch assumes there are digits after the decimal point and prints them unconditionally, which may violate the requirement that trailing zeros are not present—but the main issue for the given test case lies in the first branch.]
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