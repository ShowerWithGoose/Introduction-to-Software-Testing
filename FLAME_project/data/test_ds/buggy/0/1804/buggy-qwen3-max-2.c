#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [logical error: condition "b >= 'z'" should be "b <= 'z'"; also redundant with next condition]
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ [compilation error: gets_s is not a standard C function in all environments and is undeclared; should use fgets or scanf instead]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [semantic error: redeclaration of loop variable 'i' as char shadows the outer int 'i', breaking loop logic]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [semantic error: using shadowed char 'i' as loop counter causes undefined behavior and infinite loop risk]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}