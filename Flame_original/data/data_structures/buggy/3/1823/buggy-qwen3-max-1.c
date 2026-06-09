#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1; // @@ [If the input is like "0.001", then y becomes 3 (index of '1'), and p points to s[4], which is beyond the last digit, resulting in printing garbage or empty string. Also, if the number ends right after the first non-zero digit (e.g., "0.001"), p will point to '\0', which is okay, but logic fails for single non-zero digit case as per problem spec. Additionally, this line assumes there's always at least one digit after the first non-zero digit, which may not be true.]
        printf("%c.%se-%d",s[y],p,x+1);
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
        printf("%se%d",s+y+1,x);
    }
    return 0;
}