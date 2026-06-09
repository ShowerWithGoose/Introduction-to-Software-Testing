#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char expr[1000];
    fgets(expr, 1000, stdin);

    int i = 0, num = 0, res = 0;
    int curr_val = 0;
    char curr_op = '+';

    while (expr[i] != '=')
    {
        if (isdigit(expr[i]))
        {
            num = 0;
            while (isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            if (curr_op == '*')
            {
                curr_val *= num;
            }
            else if (curr_op == '/')
            {
                curr_val /= num;
            }
            else if (curr_op == '+')
            {
                curr_val = num;
            }
            else if (curr_op == '-')
            {
                curr_val = -num;
            }
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (expr[i] == '+' || expr[i] == '-')
            {
                res += curr_val;
            }
            curr_op = expr[i];
            i++;
        }
        else
        {
            i++;
        }
    }
    res += curr_val;

    printf("%d\n", res);
    return 0;
}

