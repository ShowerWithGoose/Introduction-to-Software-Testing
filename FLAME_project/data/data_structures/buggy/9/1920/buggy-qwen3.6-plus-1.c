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
    int flag2=0;
    for(int i=1;i<num;i++)
    {
        flag2=0; // @@ The flag2 variable needs to be reset to 0 for each new segment i to correctly track if a connection was found in the current iteration.
        for(int j=0;j<=time;j++)
        {
            if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
            {
                line[j].x2=line[i].x2;
                line[j].y2=line[i].y2;
                ds[j]++;
                flag2=1;
                break; // @@ Once a segment is connected to a chain, we should break out of the inner loop. Continuing to check other chains is incorrect because a segment can only belong to one chain (given the constraints), and modifying 'line[i]' or continuing checks might lead to logical errors or double counting if not handled carefully. More importantly, if we don't break, the logic below for adding a new chain might execute incorrectly or the loop might behave unexpectedly. Actually, the main issue is that if we find a match, we shouldn't add it as a new chain. The current code structure adds it as a new chain if flag2 is 0 at the end of the loop. If we find a match, flag2 becomes 1. We must ensure we don't process further j's unnecessarily, but strictly speaking, breaking is an optimization/correctness fix to prevent potential issues if multiple matches were possible (though constraint says no 3 segments share endpoint). However, the critical bug is below.
            }
            // else branch removed from here because it was logically flawed. It was adding the segment as a new chain for EVERY j that didn't match, which is wrong.
            if(j==time&&flag2==0)
            {
                time++;
                line[time]=line[i]; // @@ If no connection was found after checking all existing chains (j goes up to time), then this segment starts a new chain. It should be placed at index time+1 (which becomes the new time after increment). The original code had "line[time+1]=line[i]" inside the else block of the match check, which executed multiple times or incorrectly. It should only happen once if no match is found.
                ds[time]=1; // @@ Initialize the count for the new chain.
                break; 
            }
        }
    }
    int max=ds[0];
    int flag=0;
    for(int i=1;i<=time;i++)
    {
        if(ds[i]>max)
        {
            max=ds[i];
            flag=i;
        }
    }
    printf("%d %d %d",max,line[flag].x1,line[flag].y1);
    return 0;
}