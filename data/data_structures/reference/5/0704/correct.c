#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int length1;
int length2;
typedef struct LinkList
{
    int ex; //指数
    int co; //系数
    struct LinkList *pNext;
} node;
int CreateLinklist(node *Head, char *str)
{
    int length = 0;
    Head->pNext = (node *)malloc(sizeof(node));
    node *CurrentNode = Head->pNext;
    for (int i = 0; i < strlen(str); i++)
    {
        CurrentNode->co = 0;
        CurrentNode->ex = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            CurrentNode->co = (CurrentNode->co) * 10 + str[i] - '0';
            i++;
        }
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            CurrentNode->ex = (CurrentNode->ex) * 10 + str[i] - '0';
            i++;
        }
        length++;
        CurrentNode->pNext = (node *)malloc(sizeof(node));
        CurrentNode = CurrentNode->pNext;
    }
    CurrentNode->co = 0; //表示尾结点，系数不为0
    CurrentNode->ex = -1;
    return length;
}
void PrintLink(node *HeadNode)
{
    if (HeadNode->pNext == NULL)
    {
        printf("NULL\n");
        return;
    }
    node *CurrentNode = HeadNode->pNext;
    while (CurrentNode->co != 0)
    {
        printf("%d %d ", CurrentNode->co, CurrentNode->ex);
        CurrentNode = CurrentNode->pNext;
    }
}
void Result(node *Head1, node *Head2, node *re, int l1, int l2)
{
    re->pNext = (node *)malloc(sizeof(node)); // re的头结点
    node *CurrentNode = re->pNext;
    node *CurrentNode1 = Head1;
    node *CurrentNode2 = Head2;
    // CurrentNode->co = CurrentNode1->co * CurrentNode2->co;
    // CurrentNode->ex = CurrentNode1->ex + CurrentNode2->co;
    // CurrentNode = CurrentNode->pNext;
    for (int k = 0; k < l1; k++)
    {
        CurrentNode1 = CurrentNode1->pNext;
        for (int l = 0; l < l2; l++)
        {
            CurrentNode2 = CurrentNode2->pNext;
            CurrentNode->co = CurrentNode1->co * CurrentNode2->co;
            CurrentNode->ex = CurrentNode1->ex + CurrentNode2->ex;
            CurrentNode->pNext = (node *)malloc(sizeof(node));
            CurrentNode = CurrentNode->pNext;
        }
        CurrentNode2 = Head2;
    }
    CurrentNode->co = 0;
}
void BubbleSort(node *head)
{
    node *CurrentNode = head->pNext;
    int Tlength = length1 * length2;
    for (int i = 0; i < Tlength; i++)
    { //链表内冒泡排序
        for (int j = 0; j < Tlength - i - 1; j++)
        {
            if (CurrentNode->ex < (CurrentNode->pNext)->ex)
            {
                int temp;
                temp = CurrentNode->ex;
                CurrentNode->ex = (CurrentNode->pNext)->ex;
                (CurrentNode->pNext)->ex = temp;
                temp = CurrentNode->co;
                CurrentNode->co = (CurrentNode->pNext)->co;
                (CurrentNode->pNext)->co = temp;
            }
            else if (CurrentNode->ex == (CurrentNode->pNext)->ex)
            {
                CurrentNode->co = CurrentNode->co + ((CurrentNode->pNext)->co);
                node* NodeToDelete=CurrentNode->pNext;
                CurrentNode->pNext = NodeToDelete->pNext;
                Tlength--;
                free(NodeToDelete);
            }
            CurrentNode = CurrentNode->pNext;
        }
        CurrentNode = head->pNext;
    }
}
char str1[N];
char str2[N];
int main()
{
    gets(str1);
    gets(str2);
    node *head1 = (node *)malloc(sizeof(node));
    node *head2 = (node *)malloc(sizeof(node));
    node *ReHead = (node *)malloc(sizeof(node));
    length1 = CreateLinklist(head1, str1);
    length2 = CreateLinklist(head2, str2);
    Result(head1, head2, ReHead, length1, length2);
    // printf("%d %d\n", length1, length2);
    BubbleSort(ReHead);
    // PrintLink(head1);
    // printf("\n");
    // PrintLink(head2);
    // printf("\n");
    PrintLink(ReHead);
}
