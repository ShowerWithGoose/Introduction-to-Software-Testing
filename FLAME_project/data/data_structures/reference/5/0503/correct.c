#include<stdio.h>
#include<stdlib.h>

struct info
{
    int coe;
    int ind;
};

struct Node
{
    struct info data;
    struct Node* next;
};

struct Node* CreateList()
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

struct Node* CreateNode(struct info data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* EndofList(struct Node* headNode)
{
    while(headNode->next)
    {
        headNode = headNode->next;
    }
    return headNode;
}

void InsertNodeByTail(struct Node* headNode, struct info data)
{
    struct Node* lastNode = EndofList(headNode);
    struct Node* newNode = CreateNode(data);
    lastNode->next = newNode;
}

void InsertorMergeNodeBySort(struct Node* headNode, struct info data)
{
    struct Node* newNode = CreateNode(data);
    struct Node* pMove = headNode;
    while(pMove->next)
    {
        if (pMove->next->data.ind == data.ind)
        {
            pMove->next->data.coe += data.coe;
            free(newNode);
            return;
        }
        else if (pMove->next->data.ind < data.ind)
        {
            newNode->next = pMove->next;
            pMove->next = newNode;
            return;
        }
        pMove = pMove->next;
    }
    pMove->next = newNode;
}

int main()
{
    struct Node *multi1 = CreateList(), *multi2 = CreateList(), *pMove;
    struct info record1, record2;
    int i;

    while(1)
    {
        scanf("%d %d", &record1.coe, &record1.ind);
        InsertNodeByTail(multi1, record1);
        if (getchar() == '\n')
            break;
    }

    while(1)
    {
        scanf("%d %d", &record1.coe, &record1.ind);
        pMove = multi1->next;
        while (pMove)
        {
            record2.coe = record1.coe * pMove->data.coe;
            record2.ind = record1.ind + pMove->data.ind;
            InsertorMergeNodeBySort(multi2, record2);
            pMove = pMove->next;
        }
        if (getchar() == '\n')
            break;
    }

    for (pMove = multi2->next;pMove;pMove = pMove->next)
    {
        if (pMove->data.coe != 0)
        {
            printf("%d %d ",pMove->data.coe, pMove->data.ind);
        }
    }


    return 0;
}

