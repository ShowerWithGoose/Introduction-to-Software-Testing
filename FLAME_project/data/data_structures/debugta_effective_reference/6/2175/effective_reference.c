#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int stack[105], top = -1;
int main()
{
    int op, a;
    while (~scanf("%d", &op))
    {
        switch (op)
        {
        case 1:
            scanf("%d", &a);
            if (top >= 100)
                printf("error ");
            else
                stack[++top] = a;
            break;
        case 0:
            if (top < 0)
                printf("error ");
            else
                printf("%d ", stack[top--]);
            break;
        case -1:
            return 0;
        }
    }
    return 0;
}
