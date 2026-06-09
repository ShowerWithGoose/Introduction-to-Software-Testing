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
    line l[10]; // @@ [The array size is fixed to 10, but the problem does not specify a maximum number of segments. The reference program uses 105, and test cases may exceed 10, causing buffer overflow.]
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    qsort(l,n,sizeof(l[0]),compare);
    for(int i=0;i<n;i++)
    {
        int x=l[i].x2,y=l[i].y2;
        int flag=1;
        for(int j=i+1;j<n;j++) // @@ [The inner loop only checks segments after index i in the sorted array, but a continuous chain might require connecting to a segment that appears before i in the array if sorting is only by x1. However, due to the sort by x1, and given x1 < x2 for each segment, this may be acceptable. But the bigger issue is that the chaining logic assumes segments are contiguous in the sorted array, which is not guaranteed—two segments that connect may not be adjacent after sorting by x1 alone.]
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
    printf("%d %d %d",max,p->x1,p->y1); // @@ [If no segment has len > 1, then max remains 1 and p remains NULL, leading to dereferencing a NULL pointer, which causes undefined behavior (likely segmentation fault). This matches the "Compilation Error" label incorrectly—actually it's a runtime error—but the test environment may report it as a compilation-like failure due to crash.]
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
        return -1; // @@ [The comparison function does not return 0 when elements are equal, violating the requirement of qsort that the comparator must define a strict weak ordering. This can lead to undefined behavior in qsort. Additionally, it always returns -1 in the else case, even when l1.x1 == l2.x1 and l1.x2 == l2.x2, which should return 0.]
}