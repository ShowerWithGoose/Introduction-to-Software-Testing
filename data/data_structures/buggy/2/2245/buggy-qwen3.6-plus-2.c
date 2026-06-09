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
        (*temp) /= next; // @@ Potential division by zero if 'next' is 0, which causes a runtime error. A check for 'next != 0' should be added.
    }
    return c;
}

int main()
{
    char c; // @@ Variable 'c' is uninitialized. Although 'flag' starts at 0, relying on this for initialization can trigger compiler errors/warnings in strict modes and is unsafe.
    int result = 0, plus = 1, temp = 0, flag = 0;
    while (1) // @@ Infinite loop: the loop condition is always true and lacks a 'break' or 'return' after handling '=', causing the program to never terminate.
    {
        if (flag == 0)
            scanf("%c", &c);
        flag = 0;
        if (c == '=') // @@ Missing 'break' or 'return 0;' after printing the result. The program will continue looping indefinitely instead of exiting.
        {
            if (plus)
                result += temp;
            else
                result -= temp;
            printf("%d", result);
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
            temp=temp*10+c-'0';
        }
    }
    return 0;
}