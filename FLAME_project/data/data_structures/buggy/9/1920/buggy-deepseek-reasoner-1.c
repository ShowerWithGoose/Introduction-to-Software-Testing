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
    return line1->x1-line2->x1; // @@ [Sorting only by x1 may cause incorrect ordering; should also sort by y1.]
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
    int flag2=0; // @@ [flag2 should be reset inside the outer loop for each i iteration.]
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
            else // @@ [The else block should not be inside the inner loop; it should be after the inner loop to add new chain only if no match found.]
            {
                line[time+1]=line[i]; // @@ [This incorrectly overwrites line[time+1] for every non-matching j, and may corrupt data.]
                if(j==time&&flag2==0) // @@ [This condition is misplaced; should be after the inner loop, not inside else, and should check flag2==0.]
                {
                    time++; // @@ [time increment should happen only when adding a new chain, but the placement is wrong due to incorrect else block.]
                    break; // @@ [Break is inappropriate here; the logic should not break from inner loop inside else.]
                }
            }
        }
    }
    int max=ds[0];
    int flag=0;
    for(int i=1;i<=time;i++) // @@ [Should start from i=0 to include the first chain in maximum search.]
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