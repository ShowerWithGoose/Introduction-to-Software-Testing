#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Incorrect condition: 'b >= 'z'' should be 'b <= 'z'', causing logic error for lowercase check]
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
    gets_s(s); // @@ [Portability/compilation error: gets_s is not standard in all C environments (e.g., GCC without specific flags), and original reference used gets which is also unsafe but more widely recognized in older standards]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable name conflict: redeclaring 'i' as char inside loop where 'i' is already an int loop counter, causing compilation error due to type clash and scope confusion]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Invalid use of redeclared 'i': now treated as char, but used in loop increment and comparison incorrectly; also modifies loop control variable leading to undefined behavior]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}