#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)
#define __MAX_LENGTH__ 50
#define ElementType int
int stack[101];
int stacknum = 0;
int isEmpty(void)
{
    if (stacknum == 0)
        return 1;
    else
        return 0;
}
int isFull(void)
{
    if (stacknum == 100)
        return 1;
    else
        return 0;
}
int main(int argc, const char *argv[])
{
    int op, num;
    int sign = 0;
    while (~scanf("%d", &op))
    {
        switch (op)
        {
        case 0:
            if (sign)
                printf(" ");
            if (isEmpty())
            {
                printf("error");
                sign = 1;
            }
            else
            {
                printf("%d", stack[--stacknum]);
                sign = 1;
            }
            break;
        case 1:
            scanf("%d", &num);
            if (isFull())
            {
                if (sign)
                    printf(" ");
                printf("error");
                sign = 1;
            }
            else
            {
                stack[stacknum++] = num;
            }
            break;
        case -1:
            goto end;
            break;
        }
    }
end:
    return 0;
}
