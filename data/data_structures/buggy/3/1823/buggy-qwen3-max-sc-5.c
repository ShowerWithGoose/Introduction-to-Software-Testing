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
        char *p=s+y+1; // @@ [If the input is like "0.001", then y becomes 3 (index of '1'), and p points to s[4], which is beyond the string if the input ends there, leading to undefined behavior or printing garbage. Also, if the number has only one non-zero digit after zeros (e.g., "0.001"), this prints "1.e-3" instead of "1e-3" or "1.0e-3" as per problem requirements.]
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