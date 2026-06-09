#include<stdio.h>
#include<string.h>
void f(char a, char b);

int main()
{
    char str[1024] = {0};
    int i = 0;
    fgets(str,1024,stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] <= 'z' && str[i - 1] >= 'a' && str[i + 1] <= 'z' && str[i + 1] >= 'a' && str[i - 1] < str[i + 1]) // @@ Missing check that i > 0 to avoid out-of-bounds access.
            {
                f(str[i - 1], str[i + 1]);
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1]) // @@ Missing check i > 0.
            {
                f(str[i - 1], str[i + 1]);
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1]) // @@ Duplicate condition; should be for digits [0-9] and also missing i>0 check.
            {
                f(str[i - 1], str[i + 1]);
            }
            else
            {
                printf("%c", str[i]);
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}

void f(char a, char b)
{
    char n;
    for (n = a + 1; n < b; n++)
    {
        printf("%c", n);
    }
}