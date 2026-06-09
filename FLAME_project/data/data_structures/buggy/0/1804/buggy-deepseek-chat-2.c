#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Error: Condition uses b >= 'z' instead of b <= 'z', causing incorrect range check for uppercase letters and digits]
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) // @@ [Error: This condition is redundant and identical to the first if, but the first if has a bug; also, the function does not handle uppercase letters or digits correctly]
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ [Error: gets_s is not a standard C function and is not declared; it causes a compilation error. Should use fgets or scanf instead.]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ [Error: When i is 0, s[i-1] accesses out-of-bounds memory, causing undefined behavior.]
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Error: Variable 'i' is redeclared as char, shadowing the loop variable 'i', causing the loop to malfunction and potential infinite loop or incorrect behavior.]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Error: The loop uses the shadowed char 'i', which is compared with characters, leading to incorrect iteration and potential infinite loop.]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}