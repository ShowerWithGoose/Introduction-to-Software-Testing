#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ condition error: should be b <= 'z' instead of b >= 'z'
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b) // @@ missing uppercase letter condition (A-Z)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ non-standard function, may cause compilation error on many compilers
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ variable shadowing: declares a new char i that hides the loop variable i
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ incorrect use of char i as array index, leads to out-of-bounds access
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}