#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack
{
    int sta[100];
    int pt;
} STACK;

int main()
{
    int op;
    int num;
    STACK stk;
    stk.pt = -1;
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            scanf("%d", &num);
            stk.pt++;
            if (stk.pt >= MAX)
            {
                printf("error ");
                stk.pt--;
            }
            else
                stk.sta[stk.pt] = num;
        }
        else if (op == 0)
        {
            if (stk.pt < 0)
                printf("error ");
            else
            {
                printf("%d ", stk.sta[stk.pt]);
                stk.pt--;
            }
        }
        else if (op == -1)
            break;
    }
    return 0;
}
