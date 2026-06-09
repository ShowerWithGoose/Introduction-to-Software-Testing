#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, c;
char x, y, z;

int main()
{
    x = '+';
    while (1)
    {
        scanf("%d %c", &b, &y);
        while (y == '*' || y == '/')
        {
            scanf("%d %c", &c, &z);
            switch (y)
            {
                case '*':
                    b = b * c;
                    break;
                case '/':
                    b = b / c;
                    break;
            }
            y = z;
        }
        switch (x)
        {
            case '+':
                a = a + b;
                break;
            case '-':
                a = a - b;
        }
        x = y;
        if (x == '=')
        {
            printf("%d", a);
            break;
        }
    }
    return 0;
}
