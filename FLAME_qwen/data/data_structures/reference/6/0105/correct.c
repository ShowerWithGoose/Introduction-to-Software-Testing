#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count = 0;
typedef struct node
{
    int number;
    struct node *link;
} * Nodeptr, Node;
Nodeptr Top = NULL, p = NULL;
int isEmpty()
{
    return Top == NULL;
}
int isFull()
{
    return count == MAX;
}
void push(int item)
{
    if (isFull())
    {
        fputs("error ", stdout);
    }
    else
    {
        p = (Nodeptr)malloc((sizeof(Node)));
        p->number = item;
        if (isEmpty())
        {
            p->link = NULL;
            Top = p;
        }
        else
        {
            p->link = Top;
            Top = p;
        }
        count++;
    }
}
void pop()
{
    if (isEmpty())
    {
        fputs("error ", stdout);
    }
    else
    {
        printf("%d ", Top->number);
        count--;
        p = Top;
        Top = Top->link;
        free(p);
    }
}
int main()
{
    int order,item;
    scanf("%d",&order);
    while(order!=-1){
        switch (order)
        {
        case 1:
            scanf("%d",&item);
            push(item);
            break;
        case 0:
            pop();
            break;
        }
        scanf("%d",&order);
    }
    return 0;
}
