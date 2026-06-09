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
    int flag2=0; // @@ [flag2 should be reset inside the for i loop, not once; also used incorrectly after loop]
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
                line[time+1]=line[i]; // @@ [should only be assigned after the inner loop if no match found, not for every non-matching j]
            }
            if(j==time&&flag2==0) // @@ [j is not accessible outside its for loop; logic should be placed after the loop using a separate match flag]
            {
                time++;
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