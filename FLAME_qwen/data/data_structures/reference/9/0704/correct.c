#include <stdio.h>
#include <stdlib.h>
#define N 100 + 5
typedef struct string1
{
    int headx;
    int heady;
    int endx;
    int endy;
} str;

typedef struct string2
{
    int num;
    int hx;
    int hy;
    int ex;
    int ey;
} Head;

str s[N];     //输入线段
Head h[N];    //连续线段
int hnum = 1; //连续线段个数
int comp(const void *a, const void *b)
{
    return (*(str *)a).headx - (*(str *)b).headx;
}
int main()
{
    int strnum;
    scanf("%d", &strnum);
    for (int i = 0; i < strnum; i++)
        scanf("%d %d %d %d", &s[i].headx, &s[i].heady, &s[i].endx, &s[i].endy);
    qsort(s, strnum, sizeof(s[0]), comp);
    // for (int i = 1; i < strnum; i++)
    //     printf("%d %d %d %d\n", s[i].headx, s[i].heady, s[i].endx, s[i].endy);
    h[0].hx = s[0].headx;
    h[0].hy = s[0].heady;
    h[0].ex = s[0].endx;
    h[0].ey = s[0].endy;
    h[0].num++; //初始化一个连续线段
    for (int i = 1; i < strnum; i++)
    {
        int flag = 0;
        for (int j = 0; j < hnum; j++)
        {
            if (h[j].hx == s[i].endx && h[j].hy == s[i].endy)
            {
                h[j].hx = s[i].headx;
                h[j].hy = s[i].heady;
                h[j].num++;
                flag = 1;
            }
            else if (h[j].ex == s[i].headx && h[j].ey == s[i].heady)
            {
                h[j].ex = s[i].endx;
                h[j].ey = s[i].endy;
                h[j].num++;
                flag = 1;
            }

            else if (h[j].ex == s[i].endx && h[j].ey == s[i].endy)
            {
                h[j].ex = s[i].endx;
                h[j].ey = s[i].endy;
                h[j].num++;
                flag = 1;
            }

            else if (h[j].hx == s[i].headx && h[j].hy == s[i].heady)
            {
                h[j].hx = s[i].headx;
                h[j].hy = s[i].heady;
                h[j].num++;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            h[hnum].hx = s[i].headx;
            h[hnum].hy = s[i].heady;
            h[hnum].ex = s[i].endx;
            h[hnum].ey = s[i].endy;
            h[hnum].num++;
            hnum++;
        }
    }
    // int max->num = 0;
    Head *max = &h[0];
    for (int k = 1; k < hnum; k++)
    {
        if (h[k].num > max->num)
        {
            // max->num = h[k].num;
            max = &h[k];
        }
    }
    printf("%d %d %d", max->num, max->hx, max->hy);
}
