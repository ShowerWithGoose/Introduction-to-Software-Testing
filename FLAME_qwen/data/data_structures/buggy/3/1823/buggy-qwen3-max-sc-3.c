#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1; // @@ [If the input is like "0.0", then 'y' may go beyond the string length, leading to undefined behavior. Also, if there's only one non-zero digit after zeros (e.g., "0.005"), 'p' will point to an empty or null part, but the code assumes there are digits after s[y].]
        printf("%c.%se-%d",s[y],p,x+1);
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.') // @@ [If the input has no decimal point (which shouldn't happen per problem description, but the code doesn't validate), this loop may run past the end of the string, causing undefined behavior.]
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x);
    }
    return 0;
}