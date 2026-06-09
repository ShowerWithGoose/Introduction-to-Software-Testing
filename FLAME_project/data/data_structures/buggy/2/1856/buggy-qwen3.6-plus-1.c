#include <stdio.h>
int bj(char, char);
int js(int, int, char);
int main()
{
    char s[200];
    fgets(s, 200, stdin);
    int j = 0;
    for (int i = 0; s[i] != '\n'; i++) // @@ The loop condition assumes the input always ends with '\n'. If the input does not contain a newline (e.g., end of file or specific test environment behavior), this loop may run out of bounds or fail to process the '=' correctly if it's not followed by newline. However, the primary logical error is below.
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
            d[t1] = m; // @@ When s[i] is '=', m is 0 (reset from previous number) or uninitialized if it's the first char (unlikely). But crucially, when s[i] is '=', we push the last number.
            t1 += 1;
            m = 0;
            if (t2 >= 2) // @@ This logic attempts to handle precedence but is flawed. It checks t2 >= 2, meaning there are at least 2 operators.
            {
                if (bj(f[t2 - 2], f[t2 - 1]) == 0) // @@ bj returns 0 if previous op is lower precedence than current? No, bj(a,b) compares a and b. If a is +/- and b is */, returns 0. This means if stack has [+,*] and new is *, bj(+,*)==0.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ Calculates top two numbers with top operator.
                }
                else
                {
                    t1 -= 1;
                    d[t1 - 2] = js(d[t1 - 2], d[t1 - 1], f[t2 - 2]); // @@ Calculates bottom two numbers with bottom operator.
                    d[t1 - 1] = d[t1];
                }
                t2 -= 1;
                if (bj(f[t2], s[i]) == 2) // @@ s[i] is the current operator (e.g., '=' or '+'). If s[i] is '=', bj(f[t2], '=') is called. bj doesn't handle '='.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ Index error potential: f[t2-1] when t2 might be 0.
                    t2 -= 1;
                }
            }
            f[t2] = s[i]; // @@ Pushes '=' onto the operator stack.
            t2++;
        }
    }
    if (t1 == 1)
    {
        printf("%d", d[0]);
    }
    else
    {
        printf("%d", js(d[0], d[1], f[0])); // @@ Only performs one operation. If there are remaining operators in f (which there likely are because '=' was pushed and logic is flawed), they are ignored. The algorithm fails to reduce the stack completely.
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
} // @@ Missing return statement for default case. If x is '=' or any other character, the behavior is undefined, often leading to Runtime Error or garbage output. This is a critical source of Runtime Error.