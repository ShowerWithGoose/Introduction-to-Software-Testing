#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define N 105
#define ll long long
#define MAX(a,b) (((a)-(b)<=0)?(b):(a))
#define MIN(a,b) (((a)-(b)<=0)?(a):(b))

//开数组，每个存按当前检查的能接在一起的左右端点，也有线段数（中间的点不显示）

typedef struct
{
    int x; int y;
}Point;
typedef struct
{
    Point point1;//左
    Point point2;//右
    int len;
}Line;

int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, n = 0;
    Line lines[N] = { 0 };
    scanf("%d", &n);
    int t = 0;//记录不能接一起的小段个数
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (i == 0)
        {
            lines[t].point1.x = x1; lines[t].point1.y = y1;
            lines[t].point2.x = x2; lines[t].point2.y = y2; // @@ [Typo: originally assigned y2 to .x instead of .y]
            lines[t].len++;
            t++;
        }
        else
        {
            int flag1 = 0;//记录有没有能接上的
            for (int j = 0; j < t; j++)
            {
                if (x1 == lines[j].point2.x && y1 == lines[j].point2.y)//接右边
                {
                    lines[j].point2.x = x2;
                    lines[j].point2.y = y2;
                    lines[j].len++;
                    flag1 = 1;
                    break;
                }
                else if (x2 == lines[j].point1.x && y2 == lines[j].point1.y)//接左边
                {
                    lines[j].point1.x = x1;
                    lines[j].point1.y = y1;
                    lines[j].len++;
                    flag1 = 1;
                    break;
                }
            }
            if (!flag1)//不能接
            {
                lines[t].point1.x = x1; lines[t].point1.y = y1;
                lines[t].point2.x = x2; lines[t].point2.y = y2;
                lines[t].len++;
                t++;
            }
        }
    }
    int flag2 = 1;//记录有没有接的行为
    while (flag2)//有的话就继续找还能不能接
    {
        flag2 = 0;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                if (lines[i].point1.x == lines[j].point2.x && lines[i].point1.y == lines[j].point2.y && lines[i].len && lines[j].len)
                {//j接到i左边
                    lines[i].point1.x = lines[j].point1.x;
                    lines[i].point1.y = lines[j].point1.y;
                    lines[i].len += lines[j].len;
                    lines[j].len = 0;//标记一下接到其他地方了
                    flag2++;
                    continue;
                }
                else if (lines[i].len && lines[j].len && lines[i].point2.x == lines[j].point1.x && lines[i].point2.y == lines[j].point1.y)
                {//j接到i右边
                    lines[i].point2.x = lines[j].point2.x;
                    lines[i].point2.y = lines[j].point2.y;
                    lines[i].len += lines[j].len;
                    lines[j].len = 0;//标记一下接到其他地方了
                    flag2++;
                    continue;
                }
            }
        }
    }
    int num = 0;
    int res_len = lines[0].len;
    for (int i = 0; i < t; i++)//找最多的
    {
        if (lines[i].len > res_len)
        {
            num = i;
            res_len = lines[i].len;
        }
    }
    printf("%d %d %d\n", res_len, lines[num].point1.x, lines[num].point1.y);
    
    /*for (int i = 0; i < t; i++)我调试的时候打印的
    {
        if (lines[i].len)
        {
            printf("%d %d %d %d %d %d\n", i, lines[i].len, lines[i].point1.x, lines[i].point1.y, lines[i].point2.x, lines[i].point2.y);
        }
    }*/

    return 0;
}