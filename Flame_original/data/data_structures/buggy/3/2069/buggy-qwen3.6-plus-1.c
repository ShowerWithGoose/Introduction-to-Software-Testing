#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c); // @@ `gets` is deprecated and removed in C11 standard, which often causes compilation errors in modern environments; use `scanf("%s", c)` or `fgets` instead.
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++)
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0')
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++)
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++)
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ Logical error: incorrectly prints the character at index n-1 (the decimal point or the last digit before it) instead of the first significant digit c[0].
        for(int i=1;c[i]!='\0';i++) // @@ Logical error: prints all characters from index 1 including the decimal point, instead of skipping the decimal point and printing only the remaining significant digits.
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}