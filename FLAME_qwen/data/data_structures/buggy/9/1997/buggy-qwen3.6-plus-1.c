#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef struct site
{
    int x1;
    int y1;
    int x2;
    int y2;
    int duanshu;
    struct site* next;
}ss;

void Pushback(ss** pphead, int a1, int b1, int a2, int b2);
void jie(ss** pphead);
void Erase(ss** pphead, ss* b);
int main()
{
    int a1 = 0;
    int b1 = 0;
    int a2 = 0;
    int b2 = 0;
    
    ss *first = NULL;
    int n = 1;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a1);
        scanf("%d", &b1);
        scanf("%d", &a2);
        scanf("%d", &b2);
        Pushback(&first, a1, b1, a2, b2);
    }

    jie(&first);

    int da = 0;
    int daheng = 0;
    int dazong = 0;
    while (first != NULL)
    {
        if (first->duanshu > da)
        {
            da = first->duanshu;
            daheng = first->x1;
            dazong = first->y1;
        }
        first = first->next;
    }

    printf("%d %d %d", da, daheng, dazong);

    return 0;
}

void Pushback(ss** pphead, int a1, int b1, int a2, int b2)
{
    ss* newnode = (ss*) malloc (sizeof(ss));
    newnode->next = NULL;
    newnode->x1 = a1;
    newnode->y1 = b1;
    newnode->x2 = a2;
    newnode->y2 = b2;
    newnode->duanshu = 1;

    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {
        //ÕÒµ½Î²½áµã
        ss* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void jie(ss** pphead)
{
    ss* f = *pphead;
    ss* b = f->next; // @@ Dereferences f without checking if it is NULL, causing a segmentation fault if the input list is empty.
    while (f != NULL)
    {
        b = f->next;
        while (b != NULL)
        {
            if (b->x1 == f->x2 && b->y1 == f->y2)
            {
                f->x2 = b->x2;
                f->y2 = b->y2;
                f->duanshu++;
                Erase(&*pphead, b);
                b = f->next;
            }
            else if (b->x2 == f->x1 && b->y2 == f->y1)
            {
                f->x1 = b->x1;
                f->y1 = b->y1;
                f->duanshu++;
                Erase(&*pphead, b);
                b = f->next;
            }
            b = b->next; // @@ Dereferences b after it may have been erased/invalidated in the previous conditional blocks, leading to undefined behavior or a crash.
        }
        f = f->next;
    }
}

void Erase(ss** pphead, ss* b)
{
    ss* newnode = (ss*)malloc(sizeof(ss)); // @@ Unnecessary memory allocation causing a memory leak; the allocated node is never used or freed.
    ss* bPrev = *pphead;
    while (bPrev->next != b && bPrev != NULL) // @@ Checks bPrev->next before verifying bPrev is not NULL, causing a segmentation fault if b is the head node.
    {
        bPrev = bPrev->next;
    }
    b = bPrev->next; // @@ Redundant local assignment that does not modify the linked list structure.
    bPrev->next = b->next; // @@ Fails to update *pphead when b is the head node, and may dereference NULL if bPrev becomes NULL during the loop.
    //free(b);
}