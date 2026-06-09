#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Error: Condition uses b >= 'z' instead of b <= 'z', which will never be true for valid lowercase letters]
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
    gets_s(s); // @@ [Error: gets_s is not a standard C function and is not available in this environment; use fgets or scanf instead]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0) // @@ [Error: When i is 0, s[i-1] accesses out-of-bounds memory; also, when i is the last index, s[i+1] may be out-of-bounds]
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Error: Variable 'i' is redeclared as char, shadowing the loop variable 'i', causing incorrect loop behavior]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Error: The loop uses the shadowed 'i' and references s[i-1] and s[i+1] incorrectly; also, the expansion should exclude the endpoints]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}