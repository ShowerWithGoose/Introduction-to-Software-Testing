#include<stdio.h>
#include<stdlib.h>
struct LINE
{
    int x1,x2,y1,y2;
    int len;
};
int compare(const void *p1,const void *p2);
typedef struct LINE line;
int main()
{
    int n;
    scanf("%d",&n);
    line l[10]; // @@ [The array size is fixed to 10, but the problem does not specify an upper bound of 10 segments. This can cause buffer overflow for n > 10.]
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    qsort(l,n,sizeof(l[0]),compare);
    for(int i=0;i<n;i++)
    {
        int x=l[i].x2,y=l[i].y2;
        int flag=1;
        for(int j=i+1;j<n;j++) // @@ [The inner loop only checks segments after index i in the sorted array, but a continuous chain might require connecting to segments that appear before i in the array if sorting is only by x1. However, due to the sort by x1, this may be acceptable, but the bigger issue is that the chaining logic assumes segments are contiguous in the array, which they may not be even after sorting by x1.]
        {
            if(l[j].x1==x&&l[j].y1==y)
            {
                flag++;
                x=l[j].x2;
                y=l[j].y2;
            }
        }
        l[i].len=flag;

    }
    int max=1;
    line *p=NULL;
    for(int i=0;i<n;i++)
    {
        if(l[i].len>max)
        {
            max=l[i].len;
            p=&l[i];
        }
    }
    printf("%d %d %d",max,p->x1,p->y1); // @@ [If no segment has length > 1, then p remains NULL (since max stays 1 and initial p is NULL), leading to dereferencing a NULL pointer and undefined behavior.]
    return 0;
}
int compare(const void *p1,const void *p2)
{
    line l1=*(line *)p1;
    line l2=*(line *)p2;
    if(l1.x1>l2.x1)
    return 1;
    else if(l1.x1==l2.x1&&l1.x2>l2.x2)
    return 1;
    else
        return -1; // @@ [The comparison function does not return 0 when elements are equal, violating the requirement of qsort's comparison function to define a strict weak ordering. This can lead to undefined behavior in qsort.]
}