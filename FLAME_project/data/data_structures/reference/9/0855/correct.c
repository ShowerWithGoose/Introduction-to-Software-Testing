#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int startx;
    int starty;
    int endx;
    int endy;
} Line; //这是一个线段输入的结构体；
typedef struct Node
{
    int linefromx;
    int linefromy;
    int lineendx;
    int lineendy;
    int cnt;
} LLine; //这是一个为了存储所有可能线段的结构体；
int cmp(const void *p1, const void *p2);
Line line[105];
LLine lline[105];
int main()
{
    int num;
    int cnt = 0;
    scanf("%d", &num);
    int i;
    for (i = 0; i < num; i++)
    {
        scanf("%d%d%d%d", &line[i].startx, &line[i].starty, &line[i].endx, &line[i].endy);
    } //对所有的线段进行输入；
    //下一步是找到所有可能的起点；
    int j;
    for (i = 0; i < num; i++)
    {
        int flag = 1;
        for (j = 0; j < num; j++)
        {
            if (i == j)
                continue; //排除同一条线段；
            else if (line[i].startx == line[j].endx && line[i].starty == line[j].endy)
            {
                flag = 0; //说明此时line[i]这条线段前面接了另一条线段，他不是起点，排除；
            }
        }
        //现在需要将所有的起点，全部放进建立的存储连续线段起点的结构体；
        if (flag == 1)
        {
            lline[cnt].linefromx = line[i].startx;
            lline[cnt].linefromy = line[i].starty;
            lline[cnt].lineendx = line[i].endx;
            lline[cnt].lineendy = line[i].endy;
            cnt++;
        }
        //将起点信息全部储存完毕；
        //下面开始对所有可能的终点进行搜索；
    }
     for (i = 0; i < cnt; i++)
     {
         lline[i].cnt = 1; //所有的成功连接的线段至少都是由一条线段构成；
     }
    for (i = 0; i < cnt; i++) //开始进行遍历
    {
        for (j = 0; j < num; j++)
        {
            if (lline[i].lineendx == line[j].startx && lline[i].lineendy == line[j].starty)
            {
                //进行覆盖
                lline[i].lineendx = line[j].endx;
                lline[i].lineendy = line[j].endy;
                j = -1; //重新搜索；
                lline[i].cnt++;
            }
        }
    }
    qsort(lline, cnt, sizeof(LLine), cmp);
    printf("%d %d %d\n", lline[0].cnt, lline[0].linefromx, lline[0].linefromy);
    return 0;
}
int cmp(const void *p1, const void *p2)
{
    LLine *a = (LLine *)p1;
    LLine *b = (LLine *)p2;
    if (a->cnt < b->cnt)
        return 1;
    else if (a->cnt == b->cnt)
        return 0;
    else if (a->cnt > b->cnt)
        return -1;
}
