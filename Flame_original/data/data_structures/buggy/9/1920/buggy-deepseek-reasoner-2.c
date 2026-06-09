#include<stdio.h>
#include<stdlib.h>
struct xd
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int cmp(const void*p,const void *q)//cmp
{
    struct xd *line1=(struct xd*)p;
    struct xd *line2=(struct xd*)q;
    return line1->x1-line2->x1;
}
struct xd line[105];
int ds[105];
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        ds[i]=1;
    }
    qsort(line,num,sizeof(struct xd),cmp);
    int time=0;
    int flag2=0; // @@ Should be reset to 0 for each i (i.e., inside outer loop)
    for(int i=1;i<num;i++)
    {
        for(int j=0;j<=time;j++)
        {
            if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
            {
                line[j].x2=line[i].x2;
                line[j].y2=line[i].y2;
                ds[j]++;
                flag2=1;
            }
            else
            {
                line[time+1]=line[i]; // @@ This else branch executes for every j that does not match, causing repeated overwrites. Assignment should occur only once after inner loop if no match.
            }
            if(j==time&&flag2==0) // @@ Condition depends on flag2 not reset each i; also break disrupts control flow
            {
                time++;
                break; // @@ Break prematurely exits inner loop, causing incomplete handling
            }
        }
    }
    int max=ds[0];
    int flag=0;
    for(int i=1;i<=time;i++) // @@ Should start from i=0 to include the first chain (line[0] and ds[0])
    {
        if(ds[i]>max) // @@ When i starts from 1, ds[0] is never compared to max
        {
            max=ds[i];
            flag=i;
        }
    }
    printf("%d %d %d",max,line[flag].x1,line[flag].y1);
    return 0;
}