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
    int n,max=0,num[101]={}; // @@ Fixed array sizes may cause buffer overflow if n > 100. max should be initialized to 1 to correctly handle cases where n=1 or no segments connect.
    int x=0,y=0; // @@ Initializing x and y to 0 leads to incorrect output when the longest chain has length 1 or no connections exist. They should be initialized to the first segment's coordinates.
    scanf("%d",&n);
    struct xy wz[100]; // @@ Hardcoded size 100 is insufficient for larger inputs, causing potential buffer overflow.
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&wz[i].x1,&wz[i].y1,&wz[i].x2,&wz[i].y2);
    }
    qsort(wz,n,sizeof(struct xy),cmp);
    for(int i=n-1;i>0;i--) // @@ Condition i>0 skips index 0, which may be the start of the longest chain. Should be i>=0.
    {
        for(int j=n-1;j>0&&j!=i;j--) // @@ Condition j>0 skips index 0. Should be j>=0. Iterating j from n-1 down to i+1 is also more efficient and logically correct.
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
    
    printf("%d %d %d",max+1,x,y); // @@ If max remains 0, x and y will incorrectly print 0. The initialization or update logic must ensure correct starting coordinates are captured.
    return 0;
}