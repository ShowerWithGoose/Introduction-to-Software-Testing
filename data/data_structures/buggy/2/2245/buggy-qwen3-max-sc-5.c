#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char cal_next(int *temp, char op)
{
    int next = 0;
    char c;
    while (1)
    {
        scanf("%c", &c);
        if (c == ' ')
            continue;
        else if (c >= '0' && c <= '9')
        {
            next = next * 10 + c - '0';
        }
        else
        {
            break;
        }
    }
    if (op == '*')
    {
        (*temp) *= next;
    }
    else
    {
        (*temp) /= next;
    }
    return c;
}

int main()
{
    char c;
    int result = 0, plus = 1, temp = 0, flag = 0;
    while (1)
    {
        if (flag == 0)
            scanf("%c", &c);
        flag = 0;
        if (c == '=')
        {
            if (plus)
                result += temp;
            else
                result -= temp;
            printf("%d", result);
            break; // @@ [Missing break causes infinite loop after printing result]
        }
        else if (c == ' ')
        {
            continue;
        }
        else if (c == '+' || c == '-')
        {
            if (plus)
            {
                result += temp;
            }
            else
            {
                result -= temp;
            }
            temp = 0;
            if (c == '-')
                plus = 0;
            else
                plus = 1;
        }
        else if (c == '*' || c == '/')
        {
            flag = 1;
            c = cal_next(&temp, c);
        }
        else{
            temp=temp*10+c-'0'; // @@ [This branch assumes c is a digit, but if input starts with a digit, it's handled correctly; however, after operators like * or /, the function cal_next consumes the next number and returns the following operator or '=', so this else may process non-digit characters incorrectly. Also, initial digit parsing doesn't reset temp properly in all cases.]
        }
    }
    return 0;
}