#include <stdio.h>
#include <stdlib.h>

typedef struct number
{
    int xs; // 系数0
    int zs; // 指数
    struct number *next;
} num;
int a[10000][4], b[10000][4];

int main()
{
    int n = 0, m = 0; // n个数据
    char ch;
    while (1)
    {
        scanf("%d%d", &a[n][0], &a[n][1]);
        n++;
        ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }

    while (scanf("%d%d", &b[m][0], &b[m][1]) != EOF) @@ Logical error: `scanf` automatically skips whitespace including newlines, so it will not stop at the end of the second polynomial's line. This causes the program to hang waiting for more input or read incorrectly. It should check for a newline character like the first input loop.
    {
        m++;
    }
    /*while (1)
    {
        scanf("%d%d", &b[m][0], &b[m][1]);
        m++;
        ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }*/

    num *new = (num *)malloc(sizeof(num)); @@ Compilation error/Warning: `new` is a reserved keyword in C++ and will cause a compilation error if compiled as C++; it is also shadowed by inner declarations later.
    new->zs = 0;
    new->xs = 0;
    new->next = NULL;
    num *head = new;
    num *p;

    int i, j, lqc; // lqc=计算所得指数
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            lqc = a[i][1] + b[j][1];
            for (p = head; p!= NULL||p==head; p = (p->next)) @@ Logical error: The condition `p!= NULL||p==head` is redundant and logically flawed; it evaluates to true as long as `p` is not NULL, making `||p==head` useless. It should simply be `p != NULL`.
            {
                if (p->zs > lqc)
                {
                    if ((p->next) == NULL || (p->next)->zs < lqc)
                    {
                        num *new = (num *)malloc(sizeof(num)); @@ Compilation error/Warning: Variable shadowing; redeclaring `new` inside this block hides the outer `new` pointer, which can cause compilation warnings/errors and logical confusion.
                        new->zs = lqc;
                        new->xs = a[i][0] * b[j][0];
                        new->next = NULL;

                        new->next = p->next;
                        p->next = new;
                        break;
                    }
                }
                else if (p->zs == lqc)
                {
                    p->xs += a[i][0] * b[j][0];
                    break;
                }
                else
                {
                    num *new = (num *)malloc(sizeof(num)); @@ Compilation error/Warning: Variable shadowing; same issue as above, redeclaring `new` hides the outer variable and may trigger compilation errors depending on compiler flags.
                    new->zs = lqc;
                    new->xs = a[i][0] * b[j][0];
                    new->next = NULL;

                    new->next = p;
                    head = new;
                    break;
                }
            }
        }
    }

    for (p = head; p != NULL; p = p->next)
    {
        printf("%d %d ", p->xs, p->zs);
    }
}