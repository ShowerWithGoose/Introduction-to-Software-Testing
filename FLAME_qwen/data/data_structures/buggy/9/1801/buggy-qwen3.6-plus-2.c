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
            break; // @@ Unreachable code; the break statement will never be executed because of the preceding return.
        }
    }
} // @@ Missing return statement at the end of a non-void function, which leads to undefined behavior if n <= 0.

int cmp(const void *q,const void *p)
{
    struct Line *a1=(struct Line *)q;
    struct Line *a2=(struct Line *)p;
    if(a1->x1>a2->x1) return 1;
    else if(a1->x1<a2->x1) return -1;
} // @@ Missing return 0; for the case when a1->x1 equals a2->x1, causing undefined behavior in qsort.
int main()
{
    int n,i;
    scanf("%d",&n);
    lines line[11]={0}; // @@ Array size is hardcoded to 11, which may cause buffer overflow if the input n exceeds 11.
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }//输入线段坐标

    qsort(line,n,sizeof(line[1]),cmp);

    int cnt[11]={0}; // @@ Array size is hardcoded to 11, which may cause buffer overflow if n exceeds 11.
    lines arr[1]={0};
    for(i=0;i<n;i++)
    {
        arr[0]=line[i];
        for(int j=0;j<n;j++)
        {
            if((arr[0].x2==line[j].x1)&&(arr[0].y2==line[j].y1))
            {
                cnt[i]++;
                arr[0]=line[j];
            }
        }
    }//得到各连续线段长度及其开始坐标

    int tmp=getMax(cnt,n);
    printf("%d %d %d",cnt[tmp]+1,line[tmp].x1,line[tmp].y1); // @@ Missing newline character '\n' at the end of the output, which may cause presentation or format mismatch errors.
}