#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ `gets` is removed in the C11 standard and causes a compilation error in modern compilers; use `fgets` or `scanf` instead.
    if(str[0]!='0')
    {
        while(str[i]!='.')
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++) // @@ Declaring a variable inside the `for` loop initialization is not supported in C89/C90, which may cause a compilation error; declare `j` before the loop.
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0')
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++) // @@ Declaring a variable inside the `for` loop initialization is not supported in C89/C90, which may cause a compilation error; declare `q` before the loop.
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); // @@ Logical error: for numbers less than 1 (starting with '0'), the exponent should be negative, so it should print `e-%d` or handle the sign correctly.
    }
    return 0;
}