#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coefficient;
    int index;
    struct node* pNext;
}LinkList;

LinkList* ListInit(void);
int GetAndCreate(LinkList* HeadNode);
void InsertList(LinkList *HeadNode, int coefficient, int index);
void DestroyList(LinkList *HeadNode);
void PrintList(LinkList *HeadNode);

int main()
{
    LinkList* HeadNode1 = ListInit(), *HeadNode2 = ListInit(), *HeadNode3 = ListInit();//初始化

    //输入
    GetAndCreate(HeadNode1);
    GetAndCreate(HeadNode2);
    //循环运算并用最后一个链表储存
    LinkList *CurrentNode1 = HeadNode1;
    while (CurrentNode1->pNext != NULL){
        CurrentNode1 = CurrentNode1->pNext;

        LinkList *CurrentNode2 = HeadNode2;
        while (CurrentNode2->pNext != NULL){
            CurrentNode2 = CurrentNode2->pNext;
            int coefficient = CurrentNode1->coefficient * CurrentNode2->coefficient;
            int index = CurrentNode1->index + CurrentNode2->index;
            InsertList(HeadNode3, coefficient, index);
        }
    }
    //输出
    PrintList(HeadNode3);
    //删除所有链表
    DestroyList(HeadNode1);
    DestroyList(HeadNode2);
    DestroyList(HeadNode3);

    return 0;
}



LinkList* ListInit(void)
{
    LinkList *HeadNode = (LinkList *)malloc(sizeof(LinkList));
    if(HeadNode == NULL){
            printf("Insufficient space cache");
        return HeadNode;
    }
    HeadNode->pNext = NULL;
    return HeadNode;
}

int GetAndCreate(LinkList* HeadNode)
{
    int coefficient, index;
    char c;
    LinkList *CurrentNode = HeadNode;
    while (scanf("%d%d", &coefficient, &index) != EOF){
        CurrentNode->pNext = (LinkList*)malloc(sizeof(LinkList));
        CurrentNode = CurrentNode->pNext;
        CurrentNode->coefficient = coefficient;
        CurrentNode->index = index;
        CurrentNode->pNext = NULL;
        c = getchar();
        if (c == '\n')
            break;
    }
    return 1;
}

void InsertList(LinkList *HeadNode, int coefficient, int index)//根据结构中的index插入或合并
{
    LinkList *CurrentNode = HeadNode;
    while (CurrentNode->pNext != NULL){
        //index由高到底
        if (index == CurrentNode->pNext->index){//已有则加
            CurrentNode->pNext->coefficient += coefficient;
            return ;
        }

        else if (index > CurrentNode->pNext->index){//大于则插入
            LinkList *InsertNode = (LinkList*)malloc(sizeof(LinkList));
            InsertNode->index = index;
            InsertNode->coefficient = coefficient;
            InsertNode->pNext = CurrentNode->pNext;
            CurrentNode->pNext = InsertNode;
            return ;
        }

        CurrentNode = CurrentNode->pNext;//小于则看下一个
    }
    //末尾插入
    LinkList *InsertNode = (LinkList*)malloc(sizeof(LinkList));
    InsertNode->index = index;
    InsertNode->coefficient = coefficient;
    InsertNode->pNext = NULL;
    CurrentNode->pNext = InsertNode;
    return ;
}

void PrintList(LinkList *HeadNode)
{
    LinkList *CurrentNode = HeadNode;
    while (CurrentNode->pNext != NULL){
        CurrentNode = CurrentNode->pNext;
        printf("%d %d ", CurrentNode->coefficient, CurrentNode->index);
    }
    return ;
}

void DestroyList(LinkList *HeadNode){//彻底销毁
    if (HeadNode == NULL)
        return ;
    LinkList *CurrentNode = HeadNode;
    while (CurrentNode != NULL){
            LinkList *NextNode = CurrentNode->pNext;
            free(CurrentNode);
            CurrentNode = NextNode;
        }
    free(HeadNode);
    HeadNode = NULL;
    return ;
}

