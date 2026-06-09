#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ [Incorrect condition: 'b >= 'z'' should be 'b <= 'z'', causing invalid range check for lowercase letters]
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
    gets_s(s); // @@ [gets_s is not standard in all C environments and may cause compilation error; also requires additional argument for buffer size in some implementations]
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ [Variable 'i' is redeclared with type char inside the loop, shadowing the outer loop variable 'i' of type int, leading to undefined behavior and potential infinite loop]
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ [Using redeclared char 'i' as loop counter causes incorrect increment and comparison; also modifies original string index unexpectedly]
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}