#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ The condition has a typo: `b >= 'z'` should be `b <= 'z'`. This causes incorrect range checking for uppercase letters and digits.
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) // @@ This condition is redundant and never reached because the first if already handles the same case (with the typo). It should be removed or corrected.
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ `gets_s` is not a standard C function and is not declared; it causes a compilation error. Should use `scanf("%s", s)` or `fgets(s, 1000, stdin)` instead.
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ When i is 0, `s[i-1]` accesses out-of-bounds memory, causing undefined behavior. Need to check `i > 0` before accessing `s[i-1]`.
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Variable `i` is redeclared as a char, shadowing the loop variable `i`. This causes the loop to behave incorrectly and may lead to infinite loops or incorrect output.
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ The loop uses the shadowed `i` variable, but the condition and increment are based on character values, not the loop index. This will not iterate correctly and may cause out-of-bounds access.
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}