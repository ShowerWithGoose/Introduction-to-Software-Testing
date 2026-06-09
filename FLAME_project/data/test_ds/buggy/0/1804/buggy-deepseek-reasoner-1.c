#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ condition 'b >= 'z'' should be 'b <= 'z'', also redundant with next line
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0; // @@ missing handling for uppercase letters [A-Z]
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ 'gets_s' is not a standard C function; use scanf("%s", s) instead (implicit declaration and linker error)
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ no boundary check for i==0 or i==n-1; may access invalid indices
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ variable 'i' shadows outer loop variable; causes incorrect indexing in next line
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ uses shadowed 'i' as index incorrectly; loop condition is flawed
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}