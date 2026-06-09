#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    if(str[0]!='0')
    {
        while(str[i]!='.')
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++)
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
        for(int q=i+1; q<=strlen(str)-1; q++)
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1); @@ [The exponent should be negative when the original number is less than 1 (like 0.00...), but this prints a positive exponent (e.g., for "0.00123", it prints "e2" instead of "e-3"). The sign and magnitude are incorrect.]
    }
    return 0;
}