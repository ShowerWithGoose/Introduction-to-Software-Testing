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
    for(int i=n-1;i>0;i--) @@ [Loop starts from n-1 down to 1, skipping index 0; should include i=0 to consider all segments as potential starting points]
    {
        for(int j=n-1;j>0&&j!=i;j--) @@ [Inner loop also skips index 0; may miss connections ending at segment 0. Also condition j>0 excludes j=0 which could be a valid predecessor]
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
    
    printf("%d %d %d",max+1,x,y); @@ [If no chain is found (max remains 0), it prints 1 and (0,0) which may not correspond to any actual segment's start point; also fails to handle case where longest chain starts at an unconnected segment]
    return 0;
}