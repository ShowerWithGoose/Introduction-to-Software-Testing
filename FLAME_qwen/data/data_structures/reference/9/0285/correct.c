// 一边输入，一边更新
// 哈希表直接映射，结点重复为二的记录在同一条线上，记录，同时加上前面的线段数
// 更新最大线段数
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


typedef struct Point
{
    int x[2];
    int y[2];
}Point;


Point point[100];

int cmp(const void* e1, const void* e2)
{
    return (*(Point*)e1).x[0] - (*(Point*)e2).x[0];
}

int main()
{
    int max = INT_MIN;

    int tmpx = 0;
    int tmpy = 0;
    int nums = 0;

    int k;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
    scanf("%d%d", &point[i].x[0], &point[i].y[0]);
    scanf("%d%d", &point[i].x[1], &point[i].y[1]);
    }

    qsort(point,  n, sizeof(point[0]), cmp);

    for(int i = 0; i < n; i++)
    {
        nums = 0 ;
        k = i;

        for(int j = i + 1; j < n; j++)
        {
            if(point[k].x[1] == point[j].x[0] && point[k].y[1] == point[j].y[0])
        {
                    nums++;
                    k = j;
        }
        }
        if(max < nums)
            {
                max = nums;
                tmpx = point[i].x[0];
                tmpy = point[i].y[0];
            }
    }

    printf("%d %d %d\n",  max + 1, tmpx, tmpy);
    return 0;
}
