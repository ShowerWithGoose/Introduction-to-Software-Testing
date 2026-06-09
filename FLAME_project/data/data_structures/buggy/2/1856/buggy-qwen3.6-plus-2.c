#include <stdio.h>
int bj(char, char);
int js(int, int, char);
int main()
{
    char s[200];
    fgets(s, 200, stdin);
    int j = 0;
    for (int i = 0; s[i] != '\n'; i++) // @@ The loop condition assumes the input always ends with '\n'. If the input does not contain a newline (e.g., end of file or specific test environment behavior), this loop may run out of bounds or fail to process the '=' correctly, leading to undefined behavior or Runtime Error. It should check for '\0' as well.
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
            if (t2 >= 2) // @@ Logic error: The condition `t2 >= 2` checks if there are at least 2 operators in the stack. However, the logic inside attempts to access `f[t2-2]` and `f[t2-1]`. When an operator is encountered, it hasn't been pushed to `f` yet for the current character. The logic seems to try to handle precedence but is flawed. Specifically, accessing `f[t2-1]` when `t2` is the count of operators currently in stack (before pushing current) is risky if `t2` is small. More critically, the logic `if (bj(f[t2 - 2], f[t2 - 1]) == 0)` compares the previous two operators. This complex inline reduction is prone to index errors.
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
                if (bj(f[t2], s[i]) == 2) // @@ Accessing `f[t2]` after decrementing `t2`. If `t2` becomes 0, `f[0]` is accessed. If `t2` was 1, it becomes 0. The logic here is extremely fragile and likely causes out-of-bounds access or incorrect calculation leading to RE or WA.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ If t2 is 0, f[t2-1] is f[-1], which is an out-of-bounds access causing Runtime Error.
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
} // @@ Missing return statement for default case. Although problem says valid expression, compiler might warn, but logically if x is '=' or other, it returns garbage. However, the main RE cause is the array index out of bounds in the main loop.