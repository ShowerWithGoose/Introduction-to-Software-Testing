#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node
{
    char *word;
    int num;
    struct node *Next;
}Node;//建立链表

Node* initList(void);
int getWord(FILE *in, char word[]);
void recordWord(Node *HeadNode,const char *word);
void printList(Node *HeadNode);
void destroyList(Node *HeadNode);

int main()
{
    FILE *in;//打开文件
    if ((in = fopen("article.txt", "r")) == NULL){
        printf("Can't open file books.txt!\n");
        return 1;
    }

    Node *HeadNode = initList();//头节点
    char word[30];
    while (getWord(in, word) != -1){//读取单词（每次读取一个单词，直到返回错误）
        recordWord(HeadNode, word);//将单词进行统计算（升序）和存入
    }

    printList(HeadNode);//输出

    fclose(in);
    destroyList(HeadNode);//销毁

    return 0;
}



Node* initList(void)
{
    Node *HeadNode = (Node *)malloc(sizeof(Node));
    if (HeadNode == NULL){
            printf("Insufficient space cache");
        return HeadNode;
    }
    HeadNode->Next = NULL;
    return HeadNode;
}

int getWord(FILE *in, char word[])
{
    char c;
    do{
        if(fscanf(in, "%c", &c) == EOF)
            return -1;//未读取到，返回-1
    }while(!isalpha(c));

    word[0] = tolower(c);
    int i = 1;
    while (isalpha(c = fgetc(in)))
        word[i++] = tolower(c);
    word[i] = '\0';

    return 1;
}

void recordWord(Node *HeadNode,const char *word)
{
    Node *CurrentNode = HeadNode;

    for ( ; CurrentNode->Next != NULL; CurrentNode = CurrentNode->Next){
        int cnt = strcmp(CurrentNode->Next->word, word);
        if (cnt == 0){//如果当前节点的下一节点的单词和所给单词相同，则num+1
            CurrentNode->Next->num++;
            return ;
        }

        else if (cnt > 0){//如果当前节点的下一节点的单词比所给单词大，则插入
            Node *InsertNode = (Node*)malloc(sizeof(Node));
            InsertNode->word = (char *)malloc(strlen(word) + 1);//开辟新空间
            strcpy(InsertNode->word, word);
            InsertNode->num = 1;
            InsertNode->Next = CurrentNode->Next;
            CurrentNode->Next = InsertNode;

            return ;
        }
    }

    Node *InsertNode = (Node*)malloc(sizeof(Node));//末尾插入
    InsertNode->word = (char *)malloc(strlen(word) + 1);
    strcpy(InsertNode->word, word);
    InsertNode->num = 1;
    InsertNode->Next = CurrentNode->Next;//即NULL
    CurrentNode->Next = InsertNode;

    return ;
}

void printList(Node *HeadNode){//这个HeadNode指向头结点，底下的代码有小改动
    Node *CurrentNode = HeadNode->Next;
    if (CurrentNode == NULL){
            return ;
    }
    while (CurrentNode != NULL){
        printf("%s %d\n", CurrentNode->word, CurrentNode->num);
        CurrentNode = CurrentNode->Next;
    }
    return ;
}

void destroyList(Node *HeadNode){//彻底销毁
    Node *CurrentNode = HeadNode->Next;
    while (CurrentNode != NULL){
            Node *NextNode = CurrentNode->Next;
            free(CurrentNode->word);//释放单词所占地址
            free(CurrentNode);
            CurrentNode = NextNode;
    }
    free(HeadNode);
    return ;
}



