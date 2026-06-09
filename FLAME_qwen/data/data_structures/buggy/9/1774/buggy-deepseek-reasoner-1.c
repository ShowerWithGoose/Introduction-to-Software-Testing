#include <stdio.h>
#include <string.h>

typedef struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    //线段的两个端点为v1(x1,y1)和v2(x2,y2)
}line;
line info[150];
int cmp(const void* p1, const void* p2)
{
    line* a = (line*)p1, * b = (line*)p2;

    if ((*a).x1<(*b).x1)return -1;
    else if ((*a).x1>(*b).x1)return 1;
    else return 0;
}
int main()
{
    
    
    int n;
    int i,j;
    
    scanf("%d",&n);//读取线段数
    for(i=0;i<n;i++)
    scanf("%d %d %d %d", &info[i].x1, &info[i].y1, &info[i].x2, &info[i].y2);//读取各线段两个端点的x、y坐标
    
    //先排序
        qsort(info + 1, n, sizeof(line), cmp); // @@ [Error: Missing #include <stdlib.h> for qsort; also wrong pointer offset: 'info + 1' sorts from index 1 instead of 0, causing out‑of‑bounds access and leaving the first element unsorted.]
    
    int count_max=1,x1_max = 0,y1_max = 0;//最长线段
    for(i=0; i<n; i++)
    {
        int x2,y2,count=1;
        x2=info[i].x2;
        y2=info[i].y2;
        for(j=i+1; j<n; j++)
        {
            if( x2==info[j].x1 && y2==info[j].y1 )//i的终点v2与j的起点相等
            {
                count++;//线段数+1
                x2=info[j].x2;
                y2=info[j].y2;
            }
        }
        if(count > count_max)
        {
            count_max=count;
            x1_max=info[i].x1;
            y1_max=info[i].y1;
        }
    }
    
    printf("%d %d %d\n", count_max, x1_max,y1_max);
    //输出包含最多线段数的连续线段的线段数，然后输出连续线段的起点的x、y坐标
    return 0;
}