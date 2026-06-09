#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  

typedef struct DuoxiangshiJiedian
{
    int xishu;
    int zhishu;
    struct DuoxiangshiJiedian* next;
} DuoxiangshiJiedian, * Duoxiangshi;

Duoxiangshi DuoxiangshiXiangchen(Duoxiangshi p1, Duoxiangshi p2);
Duoxiangshi ReadPoly();
void PrintPoly(Duoxiangshi poly);
Duoxiangshi PolyCreateNode(int xishu, int zhishu);
void PolyInsert(Duoxiangshi* poly, int xishu, int zhishu);
void PolyAttach(int xishu, int zhishu, Duoxiangshi* pRear, Duoxiangshi* poly);

int main()
{
    Duoxiangshi poly1, poly2, polyProd;

    poly1 = ReadPoly();

    poly2 = ReadPoly();

    polyProd = DuoxiangshiXiangchen(poly1, poly2);

    PrintPoly(polyProd);

    return 0;
}

Duoxiangshi DuoxiangshiXiangchen(Duoxiangshi p1, Duoxiangshi p2)
{
    Duoxiangshi p, q, temp, temp1, prod = NULL, prodRear = NULL, pp, pq;
    int sum;

    p = p1;

    while (p)
    {
        q = p2;
        while (q)
        {
            sum = p->xishu * q->xishu;
            PolyInsert(&prod, sum, p->zhishu + q->zhishu);
            q = q->next;
        }
        p = p->next;
    }

    pp = prod;
    while (pp && pp->next)
    {
        pq = pp;

        while (pq->next)

        {
            if (pp->zhishu == pq->next->zhishu)
            {
                pp->xishu += pq->next->xishu;
                temp = pq->next;
                pq->next = pq->next->next;

                free(temp);

            }
            else pq = pq->next;

        }
        pp = pp->next;
    }

    pp = prod;

    while (pp && pp->next)
    {
        if (pp->next->xishu == 0)
        {
            temp = pp->next;
            pp->next = pp->next->next;
            free(temp);

        }
        else pp = pp->next;

    }

    if (prod && prod->xishu == 0)
    {
        temp = prod;
        prod = prod->next;
        free(temp);

    }

    return prod;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct FreeBlock {
    int start;
    int length;
    struct FreeBlock *next;
} FreeBlock;

// º¯ÊýÉùÃ÷
FreeBlock* createFreeBlockList(int n);
void printFreeBlockList(FreeBlock *current);
FreeBlock* findAndAllocate(FreeBlock *current, int size);
void freeFreeBlockList(FreeBlock *head);

int main() {
    int n, i;
    scanf("%d", &n);

    FreeBlock *head = createFreeBlockList(n);
    FreeBlock *current = head;

    int request;
    while (scanf("%d", &request) && request != -1) {
        current = findAndAllocate(current, request);
    }

    printFreeBlockList(current);

    freeFreeBlockList(head);

    return 0;
}

FreeBlock* createFreeBlockList(int n) {
    FreeBlock *head = NULL, *tail = NULL, *newBlock;
    for (int i = 0; i < n; i++) {
        newBlock = (FreeBlock*)malloc(sizeof(FreeBlock));
        scanf("%d %d", &newBlock->start, &newBlock->length);
        newBlock->next = NULL;

        if (!head) {
            head = tail = newBlock;
        } else {
            tail->next = newBlock;
            tail = newBlock;
        }
    }
    tail->next = head; // Make it circular
    return head;
}

void printFreeBlockList(FreeBlock *current) {
    FreeBlock *temp = current;
    do {
        printf("%d %d\n", temp->start, temp->length);
        temp = temp->next;
    } while (temp != current);
}

FreeBlock* findAndAllocate(FreeBlock *current, int size) {
    FreeBlock *prev = current;
    do {
        if (current->length >= size) {
            if (current->length == size) {
                // Remove the block from the list
                prev->next = current->next;
                if (current == prev) { // If there's only one block in the list
                    prev = current->next;
                }
                free(current);
                return prev->next; // Return next block as current
            } else {
                // Split the block
                FreeBlock *newBlock = (FreeBlock*)malloc(sizeof(FreeBlock));
                newBlock->start = current->start + size;
                newBlock->length = current->length - size;
                newBlock->next = current->next;

                current->length = size;
                current->next = newBlock;

                return current;
            }
        }
        prev = current;
    } while ((current = current->next) != prev);

    return current; // If no suitable block is found, return the original current
}

void freeFreeBlockList(FreeBlock *head) {
    FreeBlock *current = head;
    do {
        FreeBlock *temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}
*/

void PolyInsert(Duoxiangshi* poly, int xishu, int zhishu)
{
    Duoxiangshi p, q, temp;

    p = *poly;
    q = NULL;

    while (p && p->zhishu > zhishu)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL) {
        int flag = 0;
        temp = PolyCreateNode(xishu, zhishu);
        temp->next = *poly;
        *poly = temp;

    }
    else if (p == NULL || p->zhishu < zhishu)
    {
        temp = PolyCreateNode(xishu, zhishu);
        temp->next = q->next;
        q->next = temp;
    }
    else p->xishu += xishu;

}

Duoxiangshi PolyCreateNode(int xishu, int zhishu)
{
    Duoxiangshi node = (Duoxiangshi)malloc(sizeof(DuoxiangshiJiedian));
    node->xishu = xishu;
    node->zhishu = zhishu;
    node->next = NULL;
    return node;
}

Duoxiangshi ReadPoly()
{
    Duoxiangshi poly = NULL, pRear = NULL;
    int xishu, zhishu;
    int ch = 0;

    while (scanf("%d %d", &xishu, &zhishu))
    {
        PolyAttach(xishu, zhishu, &pRear, &poly);
        if ((ch = getchar()) == "\n") { // @@ [Error: Comparing a char with a string literal. Should be '\n'. This condition is always false, causing an infinite loop and Time Limit Exceeded.]
            break;
        }
    }

    return poly;
}

void PolyAttach(int xishu, int zhishu, Duoxiangshi* pRear, Duoxiangshi* poly)
{
    Duoxiangshi temp;

    if (!*poly)
    {

        *poly = PolyCreateNode(xishu, zhishu);
        *pRear = *poly;
    }
    else
    {

        temp = PolyCreateNode(xishu, zhishu);
        (*pRear)->next = temp;
        *pRear = temp;
    }
}

void PrintPoly(Duoxiangshi poly)
{
    Duoxiangshi p = poly;
    int flag = 0;

    if (!p)
    {
        printf("0 0 ");
        return;
    }

    while (p)
    {
        if (p->xishu != 0)
        {
            if (flag) printf("%d %d ", p->xishu, p->zhishu);

            else
            {
                printf("%d %d ", p->xishu, p->zhishu);
                flag = 1;
            }
        }
        p = p->next;
    }
    printf("\n");
}