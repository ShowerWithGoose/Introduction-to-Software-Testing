#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Logical error: 'b >= 'z'' is a typo, should be 'b <= 'z''. Also redundant with the next condition.
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) // @@ Logical error: missing condition for uppercase letters '[A-Z]'. This branch is redundant.
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ Compilation error: 'gets_s' is non-standard in many environments (e.g., GCC/Linux), causing implicit declaration and undefined reference linker errors. Use 'fgets' or 'scanf'.
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Semantic error: redeclaring 'char i' shadows the outer loop variable 'i', causing scope conflict and logical errors.
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Logical error: prints the starting character again, causing duplication since it was already output in the previous iteration.
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}