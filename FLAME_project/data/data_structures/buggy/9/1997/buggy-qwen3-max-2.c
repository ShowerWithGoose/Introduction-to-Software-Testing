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
    ss* b = f->next;
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
            b = b->next; 
        }
        f = f->next;
    }
}

void Erase(ss** pphead, ss* b)
{
    ss* newnode = (ss*)malloc(sizeof(ss)); // @@ [Unnecessary allocation: 'newnode' is never used and causes memory leak]
    ss* bPrev = *pphead;
    while (bPrev->next != b && bPrev != NULL) // @@ [Incorrect loop condition order: should check 'bPrev != NULL' before accessing 'bPrev->next' to avoid dereferencing NULL]
    {
        bPrev = bPrev->next;
    }
    b = bPrev->next; // @@ [Redundant assignment: 'b' is already the node to erase; this overwrites it unnecessarily]
    bPrev->next = b->next;
    //free(b); // @@ [Memory leak: allocated node 'b' is not freed after removal from list]
}