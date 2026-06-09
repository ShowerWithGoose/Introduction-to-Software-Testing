#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Incorrect condition: 'b >= 'z'' should be 'b <= 'z'', causing logic error for lowercase range check]
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
    gets_s(s); // @@ [gets_s is not standard in all C environments; may cause compilation error if compiler doesn't support it (e.g., GCC without defining __STDC_WANT_LIB_EXT1__)]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable 'i' is redeclared inside the loop, shadowing the outer loop variable and causing undefined behavior in the for-loop below]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Using redeclared 'i' as char causes incorrect loop behavior and modifies loop control variable of outer scope indirectly]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}