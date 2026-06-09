//
//  main.c
//  line
//
//  Created by  on 2022/3/25.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 105
#define num_of(x) (sizeof(x)/sizeof(x[0]))

typedef struct {
    int x1, y1, x2, y2, flag, cnt;
}point, *point_ptr;

int is_connect(int, int);
int rank(const void *, const void *);
void compare(int, int *, int, int *);

point a[MAXN];
int main()
{
    int n, i, max_cnt=0, num=0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].flag=0;
    }
    qsort(a, n, sizeof(point), rank);//按x1排好序
    
    for (i=0; i<n; i++)
    {
        if (a[i].flag)
            continue;
        a[i].cnt=1+is_connect(i, n);
        compare(a[i].cnt, &max_cnt, i, &num);
    }
    printf("%d %d %d\n", max_cnt, a[num].x1, a[num].y1);
    return 0;
}

int is_connect(int i, int n)
{
    for (int j=i+1; j<n; j++)
    {
        if (a[j].flag)
            continue;
        else if (a[j].x1==a[i].x2 && a[j].y1==a[i].y2)
        {
            a[j].flag=1;
            return (1+is_connect(j, n));
        }
    }
    return 0;
}

int rank (const void *p1, const void *p2)
{
    point_ptr pp1=(point_ptr)p1, pp2=(point_ptr)p2;
    if (pp1->x1>pp2->x1)
        return 1;
    else if (pp1->x1<pp2->x1)
        return -1;
    else
        return 0;
}

void compare(int a1, int *a2, int b1, int *b2)
{
    if (a1>*a2)
    {
        *a2=a1;
        *b2=b1;
    }
}

