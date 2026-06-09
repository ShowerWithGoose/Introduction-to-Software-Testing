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

    while (scanf("%d%d", &b[m][0], &b[m][1]) != EOF)
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

    num *new = (num *)malloc(sizeof(num));
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
            for (p = head; p!= NULL||p==head; p = (p->next)) // @@ The loop condition `p!= NULL||p==head` is logically flawed and causes infinite loops or incorrect traversal. It should iterate through the list properly. More importantly, the logic inside fails to handle the case where the coefficient becomes 0 after addition, or fails to insert correctly if the list is not maintained in strict descending order with head handling. However, the primary issue leading to "Wrong Answer" with extra "0 0" is that the initial dummy node (head) with 0 coefficient and 0 exponent is never removed or skipped during output if it remains non-zero or if terms are added incorrectly relative to it. In this specific case, the term $120 x^{2000000000}$ is added. The head node is $0 x^0$. If no other term cancels the head's coefficient or if the head is treated as a valid term, it prints. But wait, the head has coeff 0. The output loop prints all nodes. If the head's coefficient remains 0, it prints "0 0". The problem states "Only terms with non-zero coefficients will appear in the input" and implies output should likely follow similar convention or at least not print zero terms. The reference program's `add` function merges terms. Here, if a term matches an existing exponent, it adds. If the sum is 0, it stays in the list with coeff 0. The output loop prints everything. So, "0 0" appears because the initial dummy node has coeff 0 and exp 0, and it is never removed. Additionally, if any calculation results in 0 coefficient, it also stays. The fix requires skipping zero-coefficient terms in output or removing them from the list. Given the constraint "do not change structure", marking the output line or the initialization is key. But actually, the biggest logical error is that the code does not remove terms with zero coefficients. The expected output does not have "0 0". The head node is initialized to 0,0. It is never updated to have a non-zero coefficient in this specific test case (only term is 2000000000). So it remains 0,0. The output loop prints it.
            {
                if (p->zs > lqc)
                {
                    if ((p->next) == NULL || (p->next)->zs < lqc)
                    {
                        num *new = (num *)malloc(sizeof(num));
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
                    num *new = (num *)malloc(sizeof(num));
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

    for (p = head; p != NULL; p = p->next) // @@ This loop prints terms with zero coefficients (like the initial dummy node), which violates the implicit requirement to only output non-zero terms as seen in the expected output.
    {
        printf("%d %d ", p->xs, p->zs);
    }
}