#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
} pt;
pt point[200];
int cmp(pt *a, pt *b)
{
    return (a->x1 - b->x1);
}
int find(int a, int b, int time)
{
    for (int i = a + 1; i < b; i++)
    {
        if (point[a].x2 == point[i].x1 && point[a].y2 == point[i].y1)
        {
            time++;
            return find(i, b, time);
        }
    }
    return time;
} //找到所有连成串的
int num, a, b, c, d, j, k, e[50], f[50], maxtime, head, time = 1, o;
typedef struct shuchu
{
    int amount;
    int kz;
} s;
s sc[200];
int main()
{
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        point[i].x1 = a;
        point[i].x2 = c;
        point[i].y1 = b;
        point[i].y2 = d;
    }
    //按x从小到大排序
    qsort(point, num, sizeof(pt), cmp);
    for (j = 0; j < num; j++)
    {
        for (int l = 1; l < num - j; l++)
        {
            if (point[j].x2 == point[j + l].x1 && point[j].y2 == point[j + l].y1)
            {
                sc[k].amount = find(j + l, num, time);
                sc[k].kz = j;
                k++;
                break;
            }
        }
    } //将每一个点都当做线段开头看能连多少，然后找到最大值输出
    maxtime = sc[0].amount;
    for (int i = 0; i < 200; i++)
    {
        if (sc[i].amount > maxtime)
            maxtime = sc[i].amount;
    } //找到最长的
    for (int i = 0; i < 200; i++)
    {
        if (maxtime == sc[i].amount)
        {
            o = sc[i].kz;
            break;
        }
    } //找到对应的起点
    printf("%d %d %d", maxtime + 1, point[o].x1, point[o].y1);
}
