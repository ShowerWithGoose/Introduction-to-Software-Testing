#include<stdio.h>
#include<stdlib.h>

struct info
{
    int beginx;
    int beginy;
    int endx;
    int endy;
};

struct lines
{
    struct info position;
    struct lines* next;
};

struct lines* CreateList()
{
    struct lines* headNode = (struct lines*)malloc(sizeof(struct lines));
    headNode->next = NULL;
    return headNode;
}

struct lines* CreateNode(struct info position)
{
    struct lines* newNode = (struct lines*)malloc(sizeof(struct lines));
    newNode->position = position;
    newNode->next = NULL;
    return newNode;
}

void InsertNodeBySort(struct lines* headNode, struct info position)
{
    struct lines* newNode = CreateNode(position);
    struct lines* pMove = headNode;
    while(pMove->next)
    {
        if (pMove->next->position.beginx > position.beginx)
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
    int cnt = 1, max = 0;
    int n, i, j;
    struct lines *line = CreateList(), *pMove1, *pMove2;
    struct info record, mark, maxmark;

    scanf("%d", &n);

    for (i = 0;i < n;i ++)
    {
        scanf("%d %d %d %d", &record.beginx, &record.beginy, &record.endx, &record.endy);
        InsertNodeBySort(line, record);
    }

    while (line->next)
    {
        cnt = 1;
        mark = record = line->next->position;
        pMove1 = line->next;
        line->next = pMove1->next;
        free(pMove1);
        pMove1 = line->next;
        pMove2 = line;
        while (pMove1)
        {
            if (pMove1->position.beginx==record.endx&&pMove1->position.beginy==record.endy)
            {
                record = pMove1->position;
                pMove2->next = pMove1->next;
                free(pMove1);
                pMove1 = pMove2->next;
                cnt ++;
            }
            else
            {
                pMove1 = pMove1->next;
                pMove2 = pMove2->next;
            }
        }
        if (cnt > max)
        {
            max = cnt;
            maxmark = mark;
        }
    }

    printf("%d %d %d", max, maxmark.beginx, maxmark.beginy);

    return 0;
}

