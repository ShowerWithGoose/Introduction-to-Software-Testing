
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n, s, t;
char c, r = '+';
int main()
{
    scanf("%d ", &t);
    n = t;
    do
    {
        scanf("%c", &c);
        if(c=='='){
            if (r == '+')
                s = s + n;
            else
                s = s - n;
            break;
        }
        scanf("%d ", &t);
        switch (c)
        {
        case '+':
        case '-':
            if (r == '+')
                s = s + n;
            else
                s = s - n;
            r = c, n = t;
            break;
        case '*':
            n *= t;
            break;
        case '/':
            n /= t;
            break;
        default:
            break;
        }
    } while (1);
    printf("%d", s);
    return 0;
}


