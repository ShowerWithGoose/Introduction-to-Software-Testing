#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c);
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ Compilation error: variable declaration inside for loop requires C99 or later; compiler may be set to C89 standard.
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0')
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++) // @@ Same compilation error: C99-style loop variable declaration.
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++) // @@ Compilation error: C99-style loop variable declaration.
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]);
        for(int i=1;c[i]!='\0';i++) // @@ Compilation error: C99-style loop variable declaration.
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}