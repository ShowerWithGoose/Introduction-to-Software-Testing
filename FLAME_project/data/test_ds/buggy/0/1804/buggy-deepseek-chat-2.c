#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Error: condition has b >= 'z' instead of b <= 'z', and this condition is redundant with the next one
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
    gets_s(s); // @@ Error: gets_s is not a standard C function; use fgets or scanf instead
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ Error: when i=0, s[i-1] accesses out-of-bounds memory
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Error: variable i is redeclared, shadowing the loop variable i, causing incorrect loop behavior
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Error: uses the new local variable i, but the loop condition and increment are incorrect; also, the loop prints the start and end characters which should not be printed
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}