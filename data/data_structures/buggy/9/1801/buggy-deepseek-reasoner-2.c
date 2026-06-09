#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
typedef struct Line lines;

int getMax(int cnt[],int n)
{
    int max=cnt[0];
    for(int i=0;i<n;i++)
    {
        if(cnt[i]>=max)
        {
            max=cnt[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(max==cnt[i])
        {
            return i;
            break;
        }
    }
}

int cmp(const void *q,const void *p)
{
    struct Line *a1=(struct Line *)q;
    struct Line *a2=(struct Line *)p;
    if(a1->x1>a2->x1) return 1;
    else if(a1->x1<a2->x1) return -1; // @@ [Comparator does not return 0 when x1 equals x1, causing undefined behavior in qsort]
}
int main()
{
    int n,i;
    scanf("%d",&n);
    lines line[11]={0}; // @@ [Array size fixed at 11; if n > 11, out-of-bounds access occurs]
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }//输入线段坐标
    
    qsort(line,n,sizeof(line[1]),cmp);

    int cnt[11]={0}; // @@ [Array size fixed at 11; if n > 11, getMax will read beyond bounds]
    lines arr[1]={0};
    for(i=0;i<n;i++)
    {
        arr[0]=line[i];
        for(int j=0;j<n;j++)
        {
            if((arr[0].x2==line[j].x1)&&(arr[0].y2==line[j].y1))
            {
                cnt[i]++;
                arr[0]=line[j]; // @@ [This assignment does not restart the inner search from j=0, so subsequent segments with index less than current j may be missed, causing incorrect chain length]
            }
        }
    }//得到各连续线段长度及其开始坐标

    int tmp=getMax(cnt,n);
    printf("%d %d %d",cnt[tmp]+1,line[tmp].x1,line[tmp].y1);
}