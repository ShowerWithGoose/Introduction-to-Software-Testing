#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Logical error: condition 'b >= 'z'' should be 'b <= 'z''; also redundant with next condition]
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
    gets_s(s); // @@ [Compilation error: 'gets_s' is not a standard C function in all environments and is undeclared; should use 'scanf' or 'fgets']
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable shadowing and type misuse: redeclaring loop variable 'i' as char causes confusion and incorrect loop behavior]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Loop uses shadowed 'i' of type char, which breaks the outer loop and causes undefined behavior]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}