#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MULI
{
    int a;
    int x;
    struct MULI *next;
} MULI;
int main()
{
    MULI *p, *head = NULL, *next;
    p = (MULI *)malloc(sizeof(MULI));
    char c;
    int a1, x1;
    scanf("%d%d%c", &a1, &x1, &c);
    p->a = a1;
    p->x = x1;
    p->next = NULL;
    head = p;
    if (c != '\n')
    {
        while (1)
        {
            next = (MULI *)malloc(sizeof(MULI));
            scanf("%d%d%c", &a1, &x1, &c);
            next->x = x1;
            next->a = a1;
            p->next = next;
            next->next = NULL;
            p = next;
            if (c == '\n')
            {
                break;
            }
        }
    }
    int a2 = 0, x2 = 0;
    MULI *ahead = NULL, *last = NULL;
    while (1)
    {
        scanf("%d%d%c", &a1, &x1, &c);
        for (MULI *q = head; q != NULL; q = q->next)
        {
            last = ahead; // @@ Logical error: 'last' should be initialized to NULL to correctly track the predecessor of the head node. Initializing it to 'ahead' causes incorrect pointer manipulation when inserting at the beginning of the list.
            a2 = a1 * q->a;
            x2 = x1 + q->x;
            if (ahead == NULL)
            {
                next = (MULI *)malloc(sizeof(MULI));
                next->a = a2;
                next->x = x2;
                next->next = NULL;
                ahead = next;
            }
            else
            {
                for (MULI *r = ahead; r != NULL; r = r->next)
                {
                    if (x2 == r->x)
                    {
                        r->a += a2;
                        break;
                    }
                    if (x2 > r->x && r->next != NULL)
                    {
                        next = (MULI *)malloc(sizeof(MULI));
                        next->a = a2;
                        next->x = x2;
                        next->next = r;
                        last->next = next; // @@ Logical error: When 'r' is the head node, 'last' points to 'ahead', causing a cycle and failing to update the 'ahead' pointer to the new node. Head insertion requires updating 'ahead' directly.
                        next = NULL;
                        break;
                    }
                    if (r->next == NULL) // @@ Logical error: This block appends the new node to the end regardless of its exponent. If 'x2 > r->x', the node should be inserted before 'r' to maintain descending order, but this code incorrectly appends it.
                    {
                        next = (MULI *)malloc(sizeof(MULI));
                        next->a = a2;
                        next->x = x2;
                        next->next = NULL;
                        r->next = next;
                        next = NULL;
                        break;
                    }
                    last = r;
                }
            }
        }
        if (c == '\n')
            break;
    }
    for (MULI *q = ahead; q != NULL; q = q->next)
    {
        printf("%d %d ", q->a, q->x);
    }
    MULI *del = NULL, *q;
    for (del = head; del != NULL; del = q)
    {
        q = del->next;
        free(del);
    }
    for (del = ahead; del != NULL; del = q)
    {
        q = del->next;
        free(del);
    }
    return 0;
}