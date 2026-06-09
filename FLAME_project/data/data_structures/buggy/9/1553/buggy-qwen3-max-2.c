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
        for(int j=n-1;j>0&&j!=i;j--)
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
    
    printf("%d %d %d",max+1,x,y); // @@ [The variables x and y are only updated when a connection is found. If the longest chain starts from a segment that never appears as the predecessor (i.e., it's the very first segment in the chain), then x and y remain 0, leading to wrong starting point. Also, the loop bounds skip index 0, so segments at index 0 are never considered as starting points or properly processed.]
    return 0;
}