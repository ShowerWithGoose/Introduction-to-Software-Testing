#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [gets() is unsafe and may cause buffer overflow; also, it reads until newline but does not handle input ending with newline correctly in all environments]
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
        printf("%c.%se-%d",s[y],p,x+1); // @@ [When the number is exactly "0.0" or similar with only zeros after decimal, s[y] may be the null terminator, causing undefined behavior; also, the exponent calculation x+1 may be incorrect for cases like "0.001" where the first non-zero digit is at position 3, giving exponent -3 but should be -2]
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ [When there are no digits after the decimal point (e.g., input "1"), s+y+1 points to the null terminator, printing nothing; also, the exponent x is the number of digits before the decimal point minus one, but for numbers like "10.0" (though trailing zeros not allowed per spec), this logic fails; more critically, for numbers with no decimal point (e.g., integer input), the while loop will run past the string end, causing undefined behavior]
    }
    return 0;
}