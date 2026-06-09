#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Incorrect condition: 'b >= 'z'' should be 'b <= 'z'', causing lowercase check to fail]
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
    gets_s(s); // @@ [gets_s is not standard in all environments and may cause compilation error; original reference uses gets which is also unsafe but compiles in many cases]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable 'i' is redeclared as char inside loop, shadowing the loop counter 'i' of type int, causing logic and type errors]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Using redeclared char 'i' as loop variable leads to incorrect loop behavior and potential infinite loop or wrong output]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}