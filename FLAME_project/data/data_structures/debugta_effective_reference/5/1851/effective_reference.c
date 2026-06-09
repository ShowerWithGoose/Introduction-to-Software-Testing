#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long

struct Node
{
    int xishu;
    int zhishu;
    struct Node *next;
};

struct Node *createList()
{
    struct Node *list = (struct Node *)malloc(sizeof(struct Node));
    list->next = NULL;
    return list;
}

void addList(struct Node *list, int xishu, int zhishu)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->xishu = xishu;
    newNode->zhishu = zhishu;
    newNode->next = NULL;
    struct Node *tail = list;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
}

void multi(struct Node *poly1, struct Node *poly2, struct Node *result)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    
    newNode->xishu = poly1->xishu * poly2->xishu;
    newNode->zhishu = poly1->zhishu + poly2->zhishu;
    newNode->next = NULL;

    struct Node *curr = result->next, *prev = result;

    while(curr != NULL)
    {
        
        if(curr->zhishu == newNode->zhishu)
        {
            curr->xishu += newNode->xishu;
            free(newNode);
            return;
        }

        else if(curr->zhishu < newNode->zhishu)
        {
            newNode->next = curr;
            prev->next = newNode;
            return;
        }

        prev = prev->next;
        curr = curr->next;

    }

    prev->next = newNode;

    return;
}

void printList(struct Node* list)
{
    list = list->next;

    while(list != NULL)
    {
        printf("%d %d ", list->xishu, list->zhishu);
        list = list->next;
    }
}

int main()
{
    int xishu, zhishu;
    struct Node *poly1 = createList(), *poly2 = createList(), *result = createList(), *ptr1, *ptr2;


    do
    {
        scanf("%d%d", &xishu, &zhishu);
        addList(poly1, xishu, zhishu);
    } while (getchar() != '\n');

    do
    {
        scanf("%d%d", &xishu, &zhishu);
        addList(poly2, xishu, zhishu);
    } while (getchar() != '\n');

    ptr1 = poly1->next;

    while(ptr1 != NULL)
    {
        ptr2 = poly2->next;

        while(ptr2 != NULL)
        {
            multi(ptr1, ptr2, result);

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;

    }

    printList(result);

    return 0;
}
