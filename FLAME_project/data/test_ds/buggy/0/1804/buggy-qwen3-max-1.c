#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Logical error: condition "b >= 'z'" should be "b <= 'z'"; this typo causes incorrect range check for lowercase letters]
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
    gets_s(s); // @@ [Compilation error: 'gets_s' is not a standard C function in all environments (e.g., GCC without specific flags); it's typically '_gets_s' or not available, causing undefined reference]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Semantic error: redeclaration of loop variable 'i' as 'char' inside the loop shadows the outer 'int i', breaking loop control and causing undefined behavior]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Error due to shadowed 'i': now 'i' is char, and loop modifies it incorrectly; also, original character before '-' is printed again, which duplicates it]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}