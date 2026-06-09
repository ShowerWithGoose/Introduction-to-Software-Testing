#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ logical error: b >= 'z' should be b <= 'z'
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
    gets_s(s); // @@ compilation error: gets_s is not a standard C function; use scanf or fgets instead
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ logical error: variable i shadows the outer loop index; causes incorrect array subscript usage later
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ logical error: s[i+1] uses inner char i as array index, not the integer loop variable
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}