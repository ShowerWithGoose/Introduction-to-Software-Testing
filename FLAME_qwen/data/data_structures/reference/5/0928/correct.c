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

void multi(struct Node *list1, struct Node *list2, struct Node *list3)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    
    newNode->xishu = list1->xishu * list2->xishu;
    newNode->zhishu = list1->zhishu + list2->zhishu;
    newNode->next = NULL;

    struct Node *curr = list3->next, *prev = list3;

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
    struct Node *list1 = createList(), *list2 = createList(), *list3 = createList(), *ptr1, *ptr2;


    do
    {
        scanf("%d%d", &xishu, &zhishu);
        addList(list1, xishu, zhishu);
    } while (getchar() != '\n');

    do
    {
        scanf("%d%d", &xishu, &zhishu);
        addList(list2, xishu, zhishu);
    } while (getchar() != '\n');

    ptr1 = list1->next;

    while(ptr1 != NULL)
    {
        ptr2 = list2->next;

        while(ptr2 != NULL)
        {
            multi(ptr1, ptr2, list3);

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;

    }

    printList(list3);

    return 0;
}
