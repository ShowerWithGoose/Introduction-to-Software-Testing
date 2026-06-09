#include <stdio.h>
#include <stdlib.h>

typedef struct _point
{
    int d_num;
    int u_num;
    struct _point *next;
} Node;

typedef struct _list
{
    Node *head;
} List;

void scan_list(List *num_list);
void insert_list(List *num_list, Node *p);
void print_list(List *pList);

int main()
{
    List num1, num2, out_list;
    num1.head = NULL, num2.head = NULL;
    out_list.head = NULL;
    scan_list(&num1);
    scan_list(&num2);
    Node *q1 = num1.head, *q2 = num2.head;
    for (; q1; q1 = q1->next)
    {
        for (q2 = num2.head; q2; q2 = q2->next)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->next = NULL;
            p->d_num = q1->d_num * q2->d_num;
            p->u_num = q1->u_num + q2->u_num;
            insert_list(&out_list, p);
        }
    }
    print_list(&out_list);
    return 0;
}

void scan_list(List *num_list)
{
    char ch;
    do
    {
        Node *p = (Node *)malloc(sizeof(Node));
        Node *q = num_list->head;
        p->next = NULL;
        scanf("%d %d%c", &p->d_num, &p->u_num, &ch);
        if (!num_list->head)
        {
            num_list->head = p;
        }
        else
        {
            for (; q->next; q = q->next)
                ;
            q->next = p;
        }
    } while (ch != '\n');
}

void insert_list(List *num_list, Node *p)
{
    Node *q = num_list->head;
    if (!num_list->head)
        num_list->head = p;
    else
    {
        for (; q; q = q->next)
        {
            if (p->u_num == q->u_num)
            {
                q->d_num += p->d_num;
                return;
            }
            else if (q->next && p->u_num > q->next->u_num && p->u_num < q->u_num)
            {
                p->next = q->next;
                q->next = p;
                return;
            }
            else if (!q->next)
            {
                q->next = p;
                return;
            }
        }
    }
}

void print_list(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d %d ", p->d_num, p->u_num);
    }
    printf("\n");
}
