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
    line l[10]; // @@ The array size is fixed at 10, but the problem constraints allow up to 105 segments (as seen in the reference program). This can cause buffer overflow if n > 10.
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    qsort(l,n,sizeof(l[0]),compare);
    for(int i=0;i<n;i++)
    {
        int x=l[i].x2,y=l[i].y2;
        int flag=1; // @@ The variable 'flag' should be of type int, but it is used to count the number of segments. However, the logic is flawed: it should be reset to 1 for each starting segment i, but the inner loop only counts segments that connect directly to the current chain, not all possible chains starting from i. Additionally, the variable name 'flag' is misleading; it should be 'length' or 'count'.
        for(int j=i+1;j<n;j++)
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
    printf("%d %d %d",max,p->x1,p->y1); // @@ If p is NULL (e.g., when n=0 or no segment has len > 1), dereferencing p causes undefined behavior. Also, the problem expects the starting point of the longest continuous line, but the code only checks chains starting from each segment i, which may not find the true longest chain because it doesn't consider that a segment could be part of a longer chain starting from an earlier segment.
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
        return -1;
}