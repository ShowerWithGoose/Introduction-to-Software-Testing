#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int coe;
    int idx;
    struct _node *next;
}
Node;

int main()
{
    Node *mul1 = (Node*)malloc(sizeof(Node));
    Node *mul2 = (Node*)malloc(sizeof(Node));
    mul1->next = NULL;
    mul2->next = NULL;
    Node *mulptr, *mulptr1, *mulptr2, *temp;
    int coe, idx;
    char endsym;

    mulptr = mul1;
    while (~scanf("%d%d", &coe, &idx))
    {
        mulptr->next = (Node*)malloc(sizeof(Node));
        mulptr->next->coe = coe;
        mulptr->next->idx = idx;
        mulptr = mulptr->next;
        mulptr->next = NULL;
        //printf("I1 %d %d\n", coe, idx);
        if (scanf("%c", &endsym), endsym == '\n')
        {
            break;
        }
    }
    mulptr = mul2;
    while (~scanf("%d%d", &coe, &idx))
    {
        mulptr->next = (Node*)malloc(sizeof(Node));
        mulptr->next->coe = coe;
        mulptr->next->idx = idx;
        mulptr = mulptr->next;
        mulptr->next = NULL;
        //printf("I2 %d %d\n", coe, idx);
        if (scanf("%c", &endsym), endsym == '\n')
        {
            break;
        }
    }
    
    Node *mulout = (Node*)malloc(sizeof(Node));
    mulout->next = NULL;
    int doAppend;

    for (mulptr1=mul1; mulptr1->next; mulptr1=mulptr1->next)
    {
        for (mulptr2=mul2; mulptr2->next; mulptr2=mulptr2->next)
        {
            coe = mulptr1->next->coe * mulptr2->next->coe;
            idx = mulptr1->next->idx + mulptr2->next->idx;
            //printf("O %d %d\n", coe, idx);
            doAppend = 1;
            for (mulptr=mulout; mulptr->next; mulptr=mulptr->next)
            {
                if (mulptr->next->idx == idx)
                {
                    mulptr->next->coe += coe;
                    doAppend = 0;
                    break;
                }
                else if (mulptr->next->idx < idx)
                {
                    temp = (Node*)malloc(sizeof(Node));
                    temp->coe = coe;
                    temp->idx = idx;
                    temp->next = mulptr->next;
                    mulptr->next = temp;
                    doAppend = 0;
                    break;
                }
            }
            if (mulptr->next == NULL)
            {
                mulptr->next = (Node*)malloc(sizeof(Node));
                mulptr->next->coe = coe;
                mulptr->next->idx = idx;
                mulptr->next->next = NULL;
            }
        }
    }

    for (mulptr=mulout; mulptr->next; mulptr=mulptr->next)
    {
        if (mulptr->next->coe != 0)
        {
            printf("%d %d ", mulptr->next->coe, mulptr->next->idx);
        }
    }

    return 0;
}

