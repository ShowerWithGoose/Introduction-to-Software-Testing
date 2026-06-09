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
            last = ahead; // @@ [This assignment is incorrect because 'ahead' may be NULL, and 'last' should track the previous node during traversal, but it's reset to 'ahead' (which is the head) for every term from the second polynomial. This breaks insertion logic when inserting in sorted order.]
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
                    if (x2 > r->x && r->next != NULL) // @@ [This condition fails to handle insertion at the head of the list. If x2 > r->x and r is the first node (i.e., ahead), we should insert before r, but 'last' is not correctly maintained to allow that. Also, 'last' was incorrectly initialized above.]
                    {
                        next = (MULI *)malloc(sizeof(MULI));
                        next->a = a2;
                        next->x = x2;
                        next->next = r;
                        last->next = next; // @@ ['last' may be NULL here if r == ahead, leading to segmentation fault or undefined behavior.]
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