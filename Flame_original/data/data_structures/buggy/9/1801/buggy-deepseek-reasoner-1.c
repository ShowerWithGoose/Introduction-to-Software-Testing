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
} // @@ Function lacks a return statement when n==0; potential undefined behavior (but n>0 by problem constraints, minor)

int cmp(const void *q,const void *p)
{
    struct Line *a1=(struct Line *)q;
    struct Line *a2=(struct Line *)p;
    if(a1->x1>a2->x1) return 1;
    else if(a1->x1<a2->x1) return -1; // @@ Missing return for the case a1->x1 == a2->x1; leads to undefined behavior in qsort (should also compare y1)
}
int main()
{
    int n,i;
    scanf("%d",&n);
    lines line[11]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }//输入线段坐标
    
    qsort(line,n,sizeof(line[1]),cmp);

    int cnt[11]={0};
    lines arr[1]={0};
    for(i=0;i<n;i++)
    {
        arr[0]=line[i]; // @@ Starting chain from every segment; does not account for segments that may appear before it in the chain (which have smaller x1). Thus cnt[i] only counts segments after this index, not the full length of the continuous line that includes this segment. Results in incorrect starting point and length.
        for(int j=0;j<n;j++)
        {
            if((arr[0].x2==line[j].x1)&&(arr[0].y2==line[j].y1))
            {
                cnt[i]++;
                arr[0]=line[j];
            }
        }
    }//得到各连续线段长度及其开始坐标

    int tmp=getMax(cnt,n); // @@ Uses index from cnt array which only represents partial chain length; starting point line[tmp] may not be the true start of the longest continuous segment.
    printf("%d %d %d",cnt[tmp]+1,line[tmp].x1,line[tmp].y1);
}