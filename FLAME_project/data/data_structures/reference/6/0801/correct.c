#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK  (100)
#define OP_PUSH_STACK  (1)
#define OP_POP_STACK  (0)
#define OP_END_STACK  (-1)
const char *CHAR_ERROR = "error";

typedef struct stackItem
{
    int content;
    struct stackItem *pNext;
} stackItem;

typedef struct
{
    int numOfItems;
    stackItem *pStackTop;
} stack;

stack *newStackPt();
stackItem *newStackItemPt();
int pushStack(stack *pStack, stackItem *pStackItem);
int popStack(stack *pStack);
int freeStack(stack *pStack);

int main()
{
    int temp;
    stack *pStack = newStackPt();
    FILE *fileIn = stdin;
    FILE *fileOut = stdout;
    while (fscanf(fileIn, "%d", &temp), temp != OP_END_STACK)
    {
        switch (temp)
        {
        case OP_PUSH_STACK:
            fscanf(fileIn, "%d", &temp);
            stackItem *new = newStackItemPt();
            new->content = temp;
            temp = pushStack(pStack, new);
            if (temp == -1)
            {
                fprintf(fileOut, "error ");
            }
            break;
        case OP_POP_STACK:
            temp = popStack(pStack);
            if (temp == -1)
            {
                fprintf(fileOut, "error ");
            }
            else
            {
                fprintf(fileOut, "%d ", temp);
            }
            break;
        case OP_END_STACK:
            break;
        }
    }

    freeStack(pStack);
    return 0;
}

stack *newStackPt()
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->numOfItems = 0;
    p->pStackTop = NULL;
    return p;
}

stackItem *newStackItemPt()
{
    stackItem *p = (stackItem *)malloc(sizeof(stackItem));
    p->content = 0;
    p->pNext = NULL;
    return p;
}

int pushStack(stack *pStack, stackItem *pStackItem)
{
    if (pStack->numOfItems >= MAX_STACK)
    {
        return -1;
    }

    pStackItem->pNext = pStack->pStackTop;
    pStack->pStackTop = pStackItem;
    pStack->numOfItems++;
    return 0;
}

int popStack(stack *pStack)
{
    if (pStack->pStackTop == NULL)
    {
        return -1;
    }
    
    int topContent = pStack->pStackTop->content;

    stackItem *toDel = pStack->pStackTop;
    pStack->pStackTop = pStack->pStackTop->pNext;
    pStack->numOfItems--;
    free(toDel);

    return topContent;
}

int freeStack(stack *pStack)
{
    if (pStack->numOfItems > 0)
    {
        while (pStack->pStackTop != NULL)
        {
            stackItem *toDel = pStack->pStackTop;
            pStack->pStackTop = pStack->pStackTop->pNext;
            pStack->numOfItems--;
            free(toDel);
        }
        free(pStack);
        return 1;
    }
    free(pStack);
    return 0;
}
