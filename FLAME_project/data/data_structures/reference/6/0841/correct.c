#pragma warning(disable : 4996) 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int a;
    struct Node* pNext;
    struct Node* pPre;
};

struct Node* Stack() {
    struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pTemp)
        return NULL;
    pTemp->a = -1;
    pTemp->pNext = pTemp;
    pTemp->pPre = pTemp;
    return pTemp;
}

bool IsEmpty(struct Node* pStack) {
    if (NULL == pStack || pStack->pNext == pStack)
        return true;
    return false;
}

void Push(struct Node* pStack, int a) {
    if (NULL == pStack)
        return;
    struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
    if (pTemp == NULL)
        return;
    pTemp->pNext = NULL;
    pTemp->pPre = NULL;
    pTemp->a = a;
    pTemp->pNext = pStack;
    pTemp->pPre = pStack->pPre;
    pStack->pPre->pNext = pTemp;
    pStack->pPre = pTemp;
}

void FreeStack(struct Node** pStack) {
    if (NULL == *pStack)
        return;
    struct Node* pTemp = *pStack;
    do {
        struct Node* pT = pTemp;
        pTemp = pTemp->pNext;
        free(pT);
    } while (pTemp != *pStack);
    *pStack = NULL;
}

struct Node* Top(struct Node* pStack) {
    if (IsEmpty(pStack))
        return NULL;
    return pStack->pPre;
}

void Pop(struct Node* pStack) {
    if (IsEmpty(pStack))
        return;
    struct Node* pT = pStack->pPre;
    pT->pPre->pNext = pStack;
    pStack->pPre = pT->pPre;
    free(pT);
}

int num = 0;

int main(void) {

    struct Node* pStack = Stack();
    int n = 0;
    int sign = 0;
    while (1) {
    scanf("%d", &sign);
        if (sign == 1) {
            scanf("%d", &n);
            if (num == 100)
                printf("error ");
            else {
                Push(pStack, n);
                num++;
            }   
        }
        else if (sign == 0) {
            struct Node* p = Top(pStack);
            if (num == 0) 
                printf("error ");
            else {
                printf("%d ", p->a);
                Pop(pStack);
                num--;
            }
        }
        else
            break;
    }
    FreeStack(&pStack);
    return 0;
}

