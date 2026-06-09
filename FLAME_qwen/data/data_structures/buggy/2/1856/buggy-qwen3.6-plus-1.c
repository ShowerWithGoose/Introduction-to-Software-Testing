#include <stdio.h>
int bj(char, char);
int js(int, int, char);
int main()
{
    char s[200];
    fgets(s, 200, stdin);
    int j = 0;
    for (int i = 0; s[i] != '\n'; i++) // @@ The loop condition only checks for '\n'. If the input lacks a newline, it reads past the null terminator causing undefined behavior. It should also check for '\0' and stop at '='.
    {
        if (s[i] != ' ')
        {
            s[j] = s[i];
            j += 1;
        }
    }
    s[j] = '\0';
    int m = 0;
    int d[100] = {0};
    char f[100] = {0};
    int t1 = 0, t2 = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            m = m * 10 + (s[i] - '0');
        }
        else
        {
            d[t1] = m;
            t1 += 1;
            m = 0;
            if (t2 >= 2)
            {
                if (bj(f[t2 - 2], f[t2 - 1]) == 0)
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]);
                }
                else
                {
                    t1 -= 1;
                    d[t1 - 2] = js(d[t1 - 2], d[t1 - 1], f[t2 - 2]);
                    d[t1 - 1] = d[t1];
                }
                t2 -= 1;
                if (bj(f[t2], s[i]) == 2)
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]);
                    t2 -= 1;
                }
            }
            f[t2] = s[i];
            t2++;
        }
    }
    if (t1 == 1)
    {
        printf("%d", d[0]);
    }
    else
    {
        printf("%d", js(d[0], d[1], f[0]));
    }
    return 0;
}
int bj(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '+' || b == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (b == '+' || b == '-')
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}
int js(int a, int b, char x)
{
    if (x == '+')
    {
        return a + b;
    }
    else if (x == '-')
    {
        return a - b;
    }
    else if (x == '*')
    {
        return a * b;
    }
    else if (x == '/')
    {
        return a / b;
    }
} // @@ Missing return statement for the default case (e.g., when x is '='). This causes a compilation error in strict environments and undefined behavior at runtime.