#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Typo: 'b >= 'z'' should be 'b <= 'z'', and this condition likely intended for uppercase letters
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) // @@ Redundant condition, duplicates lowercase check; should check for uppercase 'A'-'Z'
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ Compilation error: 'gets_s' is not a standard C function in GCC/Linux environments; use 'scanf("%s", s)' or 'fgets(s, sizeof(s), stdin)' instead
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ Out-of-bounds access when i=0; should verify i>0 && i<n-1 before accessing s[i-1] and s[i+1]
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Variable shadowing: redeclares 'i' which shadows the loop counter, causing undefined behavior in the outer loop
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Uses shadowed 'i'; also causes duplicate printing of boundary characters since outer loop prints them separately
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}