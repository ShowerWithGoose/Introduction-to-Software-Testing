#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>

struct info
{
    char word[100];
    int cnt;
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

void InsertorMergeBySort(struct Node* headNode, struct info record)
{
    struct Node* newNode = CreateNode(record);
    struct Node* pMove = headNode;
    while(pMove->next)
    {
        if (strcmp(pMove->next->data.word, record.word) == 0)
        {
            pMove->next->data.cnt ++;
            free(newNode);
            return;
        }
        else if (strcmp(pMove->next->data.word, record.word) > 0)
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
    struct Node *keywords = CreateList(), *pMove;
    struct info record;
    int i = 0;
    FILE *in;

    in = fopen("article.txt", "r");

    while((record.word[0] = fgetc(in)) != EOF)
    {
        if (record.word[0]>='a'&&record.word[0]<='z'||record.word[0]>='A'&&record.word[0]<='Z')
        {
            i = 1;
            if (record.word[0]>='A'&&record.word[0]<='Z')
                record.word[0] -= 'A'-'a';
            while ((record.word[i] = fgetc(in)) != EOF)
            {
                if (record.word[i]<'A'||(record.word[i]>'Z'&&record.word[i]<'a')||record.word[i]>'z')
                    break;
                else if (record.word[i]>='A'&&record.word[i]<='Z')
                    record.word[i] -= 'A'-'a';
                i ++;
            }
            record.word[i] = '\0';
            record.cnt = 1;
            InsertorMergeBySort(keywords, record);
        }
        else continue;
    }

    for (pMove = keywords->next;pMove;pMove = pMove->next)
    {
        printf("%s %d\n", pMove->data.word, pMove->data.cnt);
    }

    fclose(in);

    return 0;
}



