#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt; //代表线段的条数
} Line;

int cmp1(const void *p1, const void *p2); //对线段端点排序
int cmp2(const void *p1, const void *p2); //对线段条数排序

int main()
{
    Line s[107], m = {0, 0, 0, 0, 0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        s[i].cnt = 1; //初始化条数为1
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
    qsort(s, n, sizeof(Line), cmp1); //对坐标排序(升序)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) //同一条线段
                continue;
            else
            {
                if (s[i].x2 == s[j].x1 && s[i].y2 == s[j].y1)
                {
                    s[i].x2 = s[j].x2;
                    s[i].y2 = s[j].y2;
                    s[i].cnt += s[j].cnt;
                    s[j] = m; //连上的线段清零
                }
            }
        }
    }
    qsort(s, n, sizeof(Line), cmp2); //对条数排序(升序)
    printf("%d %d %d", s[n - 1].cnt, s[n - 1].x1, s[n - 1].y1);
    return 0;
}

int cmp1(const void *p1, const void *p2) // p1、p2按升序排列
{
    Line *a = (Line *)p1;
    Line *b = (Line *)p2;
    if (a->x1 != b->x1)
        return a->x1 - b->x1;
    else
        return a->y1 - b->y1;
}

int cmp2(const void *p1, const void *p2)
{
    Line *a = (Line *)p1;
    Line *b = (Line *)p2;
    return a->cnt - b->cnt;
}
