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
    ss* newnode = (ss*)malloc(sizeof(ss)); // @@ Unnecessary memory allocation causing memory leak, though not directly causing runtime error here, it's logically wrong.
    ss* bPrev = *pphead;
    while (bPrev->next != b && bPrev != NULL) // @@ Logic error: The condition checks bPrev->next before checking if bPrev is NULL. If b is the head node, bPrev starts at head, bPrev->next might be valid but bPrev != b. However, if the list has only one node or b is head, this loop logic is flawed. More critically, if b is the head node, bPrev will never equal b in the loop condition properly if we assume standard deletion. But the real crash comes from below.
    {
        bPrev = bPrev->next;
    }
    // If b is the head node, the loop above terminates with bPrev == *pphead.
    // If b is NOT found and bPrev becomes NULL (if b was not in list or logic failed), accessing bPrev->next crashes.
    // Specifically, if b is the first element (*pphead), bPrev is *pphead. The loop condition `bPrev->next != b` is false if b is head? No, bPrev->next is the second node. b is the first node. So bPrev->next != b is true. It enters loop.
    // Actually, the standard way to delete node b requires finding the node BEFORE b.
    // If b is the head, there is no node before it. This function does not handle deleting the head node correctly.
    // In `jie`, if we merge into f, we delete b. b is always after f in the current traversal logic? Not necessarily.
    // But the main Runtime Error source is usually null pointer dereference.
    // Let's look at `b = bPrev->next;`. If the loop finished because `bPrev` became `NULL` (which can happen if b is not found or list structure is messed up), then `bPrev->next` crashes.
    // Also, if b is the head, `bPrev` ends up being head. `bPrev->next` is the second node. We set `bPrev->next = b->next`. This effectively removes b from the chain IF b was the second node. But if b was head, we didn't update *pphead.
    // The critical error leading to Runtime Error in many cases with this specific `Erase` implementation is when `b` is the head node or when the loop exits with `bPrev` being `NULL`.
    // However, looking closely at the loop: `while (bPrev->next != b && bPrev != NULL)`.
    // If `bPrev` is `NULL`, `bPrev->next` causes Segmentation Fault immediately in the condition check.
    b = bPrev->next; // @@ Potential Runtime Error: If the loop exited because bPrev became NULL (due to incorrect order of checks in while loop condition), this line dereferences NULL. The condition should be `bPrev != NULL && bPrev->next != b`.
    bPrev->next = b->next;
    //free(b);
}