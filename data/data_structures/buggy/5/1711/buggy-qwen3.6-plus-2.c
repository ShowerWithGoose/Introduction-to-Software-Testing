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
        for (MULI *q = head; q != NULL; q = q->next) // @@ Declaring loop variable inside 'for' initialization is a C99 feature and causes a compilation error in C89/C90 mode.
        {
            last = ahead;
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
                for (MULI *r = ahead; r != NULL; r = r->next) // @@ Declaring loop variable inside 'for' initialization is a C99 feature and causes a compilation error in C89/C90 mode.
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
                        last->next = next; // @@ Logical error: when inserting before the head node, 'last' points to 'ahead', which incorrectly links 'ahead' to the new node and creates a circular reference. Head insertion requires updating 'ahead' directly.
                        next = NULL;
                        break;
                    }
                    if (r->next == NULL)
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
    for (MULI *q = ahead; q != NULL; q = q->next) // @@ Declaring loop variable inside 'for' initialization is a C99 feature and causes a compilation error in C89/C90 mode.
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