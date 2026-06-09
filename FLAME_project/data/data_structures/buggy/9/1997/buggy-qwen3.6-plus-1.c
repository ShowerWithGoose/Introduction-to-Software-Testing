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
    ss* newnode = (ss*)malloc(sizeof(ss)); // @@ [Unnecessary memory allocation causing memory leak, though not directly causing crash here, it's logically wrong]
    ss* bPrev = *pphead;
    while (bPrev->next != b && bPrev != NULL) // @@ [Logic error: if b is the head node, bPrev starts at head, loop condition fails immediately if bPrev==b, but if b is not head, it searches. However, if b is the head, this function fails to update *pphead. More critically, if b is not found or is head, logic is flawed. The main crash comes from accessing b->next after Erase if b was freed, but here b is not freed. The real issue is that `Erase` does not handle the case where `b` is the first node correctly, and it doesn't free the memory. But the specific Runtime Error in the test case `2\n12 12 13 13\n13 13 50 76` likely stems from `jie` logic. When `f` merges with `b`, `b` is removed. If `b` was `f->next`, `f->next` becomes `b->next`. The loop sets `b = f->next`. This part seems okay. However, look at `Erase`. It allocates `newnode` which is unused. It finds `bPrev`. If `b` is the head, `bPrev` is head. `bPrev->next != b` is false. Loop doesn't run. Then `b = bPrev->next` (which is b). `bPrev->next = b->next`. If `b` was head, `*pphead` is NOT updated. So the list still points to the "deleted" node `b`. Later access to `b` or traversal will use invalid data or cause infinite loops/crashes if `b` was freed (it's not freed here, but logically it should be). Wait, the code comments out `free(b)`. So it's a dangling pointer in the list structure if `b` was head? No, if `b` is head, `*pphead` remains pointing to `b`. `bPrev->next` (which is `(*pphead)->next`) is set to `b->next`. So `*pphead` still points to `b`, but `b->next` is effectively unlinked from the perspective of the previous node? No, `b` IS the head. The previous node doesn't exist. The head pointer `*pphead` must be updated to `b->next`. The current code fails to update `*pphead` when `b` is the first element. This leads to the list containing a node `b` that has been logically removed (its predecessor/successor links are messed up or it's isolated but still pointed to by head). In `jie`, if `b` is removed, we assume it's gone. If `b` was `f->next`, and `b` is head? `f` cannot be before head. So `b` is never head in the context of `f->next` unless `f` is NULL which is handled. Wait, `Erase` is called with `b` which is `f->next` or later. So `b` is not the head of the entire list necessarily, but it is the node after `f`. If `b` is the head of the list, then `f` must be NULL? No, `f` is iterating. If `b` is the global head, `f` must be before it? Impossible. So `b` is not the global head? Actually, if `f` is the first node, `b` is the second. `Erase` removes `b`. `bPrev` will be `f` (since `f->next == b`). `f->next` becomes `b->next`. This is correct. The bug in `Erase` is specifically when `b` IS the head of the list (`*pphead`). Can `b` be `*pphead` in `jie`? `b` starts as `f->next`. If `f` is NULL, loop ends. If `f` is `*pphead`, `b` is second node. So `b` is never `*pphead` in this specific call pattern? Wait. What if `f` merges with a node `b` that is NOT `f->next`? The code scans `b` through the list. If `b` matches, `Erase` is called. If `b` happens to be the head node (`*pphead`), and `f` is some other node? The problem states segments form a continuous line. `f` is the current segment being extended. It can extend backwards too (`else if`). If `f` extends backwards, it absorbs `b` where `b->x2 == f->x1`. Here `b` could be any node. If `b` is the head node, `Erase` fails to update `*pphead`. Then `*pphead` still points to `b`. But `b`'s `next` pointer might have been changed or `b` is logically removed. If `b` is not freed, it stays in memory. But `bPrev->next = b->next` unlinks `b` from `bPrev`. If `b` was head, there is no `bPrev` linking to it in the standard way, but `*pphead` points to it. The code `bPrev = *pphead`... `while (bPrev->next != b ...)` finds the node BEFORE `b`. If `b` is head, `bPrev` is head. `bPrev->next != b` is false (assuming head->next is not head). Loop doesn't execute. Then `b = bPrev->next` (b is head->next?? No, `b` is the argument). `bPrev->next = b->next`. This sets `head->next` to `b->next`. But `*pphead` still points to `b`. So `b` is still considered the head of the list in subsequent iterations or final output. But `b` has been merged into `f`. `f` is another node. So now we have two nodes representing parts of the same line, or corrupted state. Specifically, if `b` was the head, and we didn't update `*pphead`, the list traversal in `main` or `jie` might encounter `b` again or miss updates. The crash is likely due to `Erase` not handling the head deletion, leading to inconsistent list state, potentially accessing freed memory if `free` was enabled, or just logical corruption. In this specific code, `free` is commented out. However, there is another subtle bug: `b = b->next` in `jie` after `Erase`. If `Erase` removes `b`, `b` is invalid? No, memory is not freed. But `b` is unlinked. `f->next` might have changed if `b` was `f->next`. The code sets `b = f->next` inside the if/else blocks. This is correct. The `Erase` function itself has a critical flaw: it does not update `*pphead` if the node to be erased is the first node. Although in `jie`, `b` is usually `f->next` or later, if `f` merges with a predecessor `b` that happens to be the head of the list, `*pphead` is not updated. This leaves a dangling reference in `*pphead` to a node that has been logically merged and unlinked from its successor (if any) but not from the head pointer. This can cause infinite loops or incorrect results. For the specific test case `2\n12 12 13 13\n13 13 50 76`: `f` is first node (12,12)-(13,13). `b` is second node (13,13)-(50,76). `b->x1 == f->x2` matches. `f` becomes (12,12)-(50,76). `Erase` is called on `b`. `b` is NOT the head. `bPrev` becomes `f`. `f->next` becomes `b->next` (NULL). Correct. Why Runtime Error? Maybe `Erase` accesses `bPrev->next` when `bPrev` is NULL? The loop `while (bPrev->next != b && bPrev != NULL)` checks `bPrev != NULL` second. If `bPrev` becomes NULL, `bPrev->next` crashes. This happens if `b` is not found in the list starting from head. But `b` came from the list. Is it possible `b` was already removed? No. Is it possible `b` is `*pphead` and `*pphead` is NULL? No. Let's look closer at `Erase`. `ss* bPrev = *pphead;`. If `*pphead` is NULL, crash. But `jie` only calls `Erase` if `b` exists. If list has 1 element, `jie` loop `b=f->next` is NULL, inner loop doesn't run. So `Erase` not called. If list has 2 elements, `b` is valid. `bPrev` starts at head. If `b` is head, loop condition `bPrev->next != b` checks `head->next != head`. If list is A->B. Erase B. `bPrev`=A. `A->next != B`? False if A->next is B. Loop doesn't run. `b = A->next` (B). `A->next = B->next`. Correct. Erase A. `bPrev`=A. `A->next != A`? True (assuming A->next is B). `bPrev` becomes B. `B->next != A`? True (B->next is NULL). `bPrev` becomes NULL. Loop terminates because `bPrev != NULL` is false? No, condition is `bPrev->next != b && bPrev != NULL`. If `bPrev` is NULL, `bPrev->next` crashes BEFORE checking `bPrev != NULL` because of short-circuit evaluation order? In C, `&&` evaluates left to right. `bPrev->next` is accessed first. If `bPrev` is NULL, CRASH. This happens if `b` is the head node and the list has more than 1 node? No, if `b` is head, `bPrev` starts as head. `bPrev->next != b` is `head->next != head`. If `head->next` is not `head` (it isn't), it enters loop? No, if `b` IS `bPrev`, then `bPrev->next != b` is comparing `head->next` with `head`. They are different. So it enters loop. `bPrev` becomes `bPrev->next`. Eventually `bPrev` might become NULL if `b` is not found? But `b` is in the list. The logic `while (bPrev->next != b && bPrev != NULL)` is flawed. It should be `while (bPrev != NULL && bPrev->next != b)`. If `b` is the first node, `bPrev` starts at `b`. `bPrev->next != b` is true (usually). `bPrev` advances. It will never find `b` as `bPrev->next` because `b` is the head. The loop will run until `bPrev` becomes NULL. Then `bPrev->next` crashes. So, `Erase` crashes if `b` is the head of the list. In `jie`, can `b` be the head? Yes, if `f` is a later node and it merges backwards with the head node `b`. Example: List A->B. `f`=B. `b`=A. `B` merges with `A` (backwards). `Erase(A)`. `A` is head. Crash.]
    ss* bPrev = *pphead;
    while (bPrev->next != b && bPrev != NULL) // @@ [Incorrect order of conditions in while loop leads to dereferencing NULL pointer if 'b' is the head node or not found properly, causing Runtime Error. Should be 'bPrev != NULL && bPrev->next != b'. Also fails to update *pphead if b is the first node.]
    {
        bPrev = bPrev->next;
    }
    b = bPrev->next;
    bPrev->next = b->next;
    //free(b);
}