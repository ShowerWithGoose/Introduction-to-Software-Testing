#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF)
    {
        while (s[i] == '\0' || s[i] == ' ')
        {
            scanf("%c", &s[i]);
        }
        i++;
    }
printf("%c",s[1]);
    int h = i; // @@ In C89/C90 standard, variables must be declared at the beginning of a block before any executable statements. Declaring 'h' after 'printf' causes a compilation error in strict C environments.
    for (i = 1; i < h; i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*')
                a[i] *= a[i + 1];
            else
                a[i] /= a[i + 1];
            for (int j = i+1; j < h; j++) // @@ Declaring the loop variable 'j' inside the 'for' statement is a C99 feature. It will cause a compilation error if the compiler is set to C89/C90 standard.
            {
                a[j] = a[j + 1];
                s[j - 1] = s[j];
            }
            i--;
        }
    }
    int sum=a[1]; // @@ Similar to 'h', declaring 'sum' after executable statements violates C89/C90 rules, leading to a compilation error in strict mode.
    for(i=1; s[i-1]!='='; i++)
    {
        if(s[i]=='+')
        {
            sum+=a[i+1];
        }
        if(s[i]=='-')
        {
            sum-=a[i+1];
        }
    }
    //printf("%d\n",sum);
    return 0;



}