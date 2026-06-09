#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct line
{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
};
typedef struct line LINE;
LINE Line[105];

int ComparebyX(const void *a, const void *b);

int main()
{
    int num, NumofLongestLine = 0, CurrentNum = 0;
    int Longest_start_x, Longest_start_y, Longest_end_x, Longest_end_y; //线段的起点和终点坐标
    int x, y; //最长线的起点，用于输出

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d%d%d%d", &Line[i].start_x, &Line[i].start_y, &Line[i].end_x, &Line[i].end_y);
    
    qsort(Line, num, sizeof(LINE), ComparebyX);

    /*for (int i = 0; i < num; i++)
        printf("%d %d %d %d\n", Line[i].start_x, Line[i].start_y, Line[i].end_x, Line[i].end_y);*/

    for (int i = 0; i < num; i++) //判断是否接入
    {
        CurrentNum = 1;
        
        Longest_start_x = Line[i].start_x;
        Longest_start_y = Line[i].start_y; //初始化最长线起点
        Longest_end_x = Line[i].end_x;
        Longest_end_y = Line[i].end_y; //初始化最长线终点

        for (int j = 0; j < num; j++)
        {
            if (Longest_end_x == Line[j].start_x && Longest_end_y == Line[j].start_y) //如果两条线接在一起了
            {
                Longest_end_x = Line[j].end_x;
                Longest_end_y = Line[j].end_y; //更新最长线终点
                CurrentNum++;
            }
        }
        if (CurrentNum > NumofLongestLine) //更新线段数
        {
            NumofLongestLine = CurrentNum;
            x = Line[i].start_x;
            y = Line[i].start_y;
        }
    }

    printf("%d %d %d", NumofLongestLine, x, y);

    return 0;
}

int ComparebyX(const void *a, const void *b)
{
    LINE *p1 = (LINE *)a;
    LINE *p2 = (LINE *)b;
    if (p1->start_x < p2->start_x)
        return -1;
    else if (p1->start_x > p2->start_x)
        return 1;
    else if (p1->start_x == p2->start_x)
    {
        if (p1->end_x < p2->end_x)
            return -1;
        else if (p1->end_x > p2->end_x)
            return 1;
        else
            return 0;
    }
}
