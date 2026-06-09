#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char a;
    struct Node *l;
    struct Node *r;
};

typedef struct Node list;

int DaXiao(char m)
{
    if (m >= 'A' && m <= 'Z')
        return 1;
    else if (m >= 'a' && m <= 'z')
        return 2;
    else if (m >= '0' && m <= '9')
        return 3;
    return 0;
}

int main()
{
    char s, temp;
    list *p1, *p2, *head;
    p1 = p2 = (list *)malloc(sizeof(list));

    head = p1;
    while (scanf("%c", &s) != EOF)
    {
        p1->a = s;
        p2 = p1;
        p1 = (list *)malloc(sizeof(list));
        p2->r = p1;
        p1->l = p2;
    }
    p1->r = NULL;

    for (p2 = head; p2->r != NULL; p2 = p2->r)
    {
        if (p2->a == '-' && DaXiao(p2->r->a) == DaXiao(p2->l->a) && DaXiao(p2->l->a) != 0 && p2->r->a > p2->l->a)
        {
            for (temp = p2->l->a + 1; temp < p2->r->a; temp++)
            {
                printf("%c", temp);
            }
        }
        else
            printf("%c", p2->a);
    }
    return 0;
}

