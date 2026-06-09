#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int x, y;
} Point;

typedef struct 
{
    Point start, end;
} Line;

int qsortCmp(const void * vp1,const void * vp2)
{
    Line * p1 = (Line*)vp1;
    Line * p2 = (Line*)vp2;

    if (p1->start.x-p2->start.x != 0)
    {
        return p1->start.x-p2->start.x;
    }
    else
    {
        return p1->start.y-p2->start.y;
    }
    
}

int isConnectable(Line l1, Line l2);
int cntLine(Line save[], int index);
int n;

int main()
{
    
    Line saveLine[100];
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        Line * tmp = saveLine+i;
        scanf("%d%d%d%d", 
            &tmp->start.x, &tmp->start.y, 
            &tmp->end.x, &tmp->end.y);
    }

    qsort(saveLine, n, sizeof(Line), qsortCmp);

    // for (int i = 0; i < n; i++)
    // {
    //     Line * tmp = saveLine+i;
    //     printf("%d %d %d %d\n", 
    //         tmp->start.x, tmp->start.y, 
    //         tmp->end.x, tmp->end.y);
    // }
    int max = 0;
    int maxIndex = -1;
    for (int i = 0; i < n; i++)
    {
        int tmpCnt = cntLine(saveLine,i);
        if (tmpCnt > max)
        {
            max = tmpCnt;
            maxIndex = i;
        }
    }
    // printf("index:%d\n", maxIndex);
    printf("%d %d %d", max, saveLine[maxIndex].start.x, saveLine[maxIndex].start.y);
    // system("pause"); 
    return 0;
}

int usedLine[100];

int cntLine(Line save[], int index)
{
    for (int i = index+1; i < n; i++)
    {
        if (isConnectable(save[index], save[i]))
        {
            return cntLine(save, i)+1;
        }
    }

    return 1;
}

int isConnectable(Line l1, Line l2)
{
    return l1.end.x == l2.start.x && l1.end.y == l2.start.y; 
}
