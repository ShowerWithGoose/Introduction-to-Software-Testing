#include<stdio.h>
struct xy
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int cmp(const void *aa,const void *bb)
{
    if((*(struct xy*)aa).x1>(*(struct xy*)bb).x1)
    {
        return 1;
    }
    else if((*(struct xy*)aa).x1<(*(struct xy*)bb).x1)
    {
        return -1;
    }
    return 0;
}
int main()
{
    int n,max=0,num[101]={};
    int x=0,y=0;
    scanf("%d",&n);
    struct xy wz[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&wz[i].x1,&wz[i].y1,&wz[i].x2,&wz[i].y2);
    }
    qsort(wz,n,sizeof(struct xy),cmp);
    for(int i=n-1;i>0;i--)
    {
        for(int j=n-1;j>0&&j!=i;j--) // @@ The inner loop condition `j>0` should be `j>=0` to include index 0, and the loop should also check all j, not just those with j>0. Additionally, the logic only checks connections from i to j where i > j, but due to sorting by x1, a segment with smaller x1 may connect to a segment with larger x1, so the direction of traversal is incorrect.
        {
            if(wz[i].x2==wz[j].x1&&wz[i].y2==wz[j].y1)
            {
                num[i]=num[j]+1;
                if(num[i]>max)
                {
                    max=num[i];
                    x=wz[i].x1;
                    y=wz[i].y1;
                }
            }
        } 
    }
    
    printf("%d %d %d",max+1,x,y);
    return 0;
}