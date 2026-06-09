#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Incorrect condition: 'b >= 'z'' should be 'b <= 'z'', causing logic error for lowercase letters]
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
    gets_s(s); // @@ [gets_s is not standard in all C environments and may cause compilation error; original reference uses gets which is also unsafe but compiles]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable 'i' is redeclared as char inside loop, shadowing the outer loop variable 'i' of type int, causing undefined behavior and potential infinite loop]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Using redeclared char 'i' as loop counter leads to incorrect loop behavior and possible overflow or infinite loop]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}