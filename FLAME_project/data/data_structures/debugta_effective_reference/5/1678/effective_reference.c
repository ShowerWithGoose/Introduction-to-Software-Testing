#include <stdio.h>
#include <stdlib.h>

typedef struct _point
{
    int coifficient;
    int index;
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
    List list1, list2, li;
    list1.head = NULL, list2.head = NULL;
    li.head = NULL;
    scan_list(&list1);
    scan_list(&list2);
    Node *start = list1.head, *Ncoifficient = list2.head;
    for (; start; start = start->next)
    {
        for (Ncoifficient = list2.head; Ncoifficient; Ncoifficient = Ncoifficient->next)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->next = NULL;
            p->coifficient = start->coifficient * Ncoifficient->coifficient;
            p->index = start->index + Ncoifficient->index;
            insert_list(&li, p);
        }
    }
    print_list(&li);
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
        scanf("%d %d%c", &p->coifficient, &p->index, &ch);
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
            if (p->index == q->index)
            {
                q->coifficient += p->coifficient;
                return;
            }
            else if (q->next && p->index > q->next->index && p->index < q->index)
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
        printf("%d %d ", p->coifficient, p->index);
    }
    printf("\n");
}
