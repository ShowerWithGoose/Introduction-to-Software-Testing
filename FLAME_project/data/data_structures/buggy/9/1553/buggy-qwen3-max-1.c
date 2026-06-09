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
    for(int i=n-1;i>0;i--) // @@ [Loop starts from n-1 down to 1, skipping index 0; thus, segments that start at the very beginning (index 0 after sorting) are never considered as starting points of a chain.]
    {
        for(int j=n-1;j>0&&j!=i;j--) // @@ [Inner loop also skips index 0, so it cannot link to or from the first segment in sorted order, breaking chains that should include it.]
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
    
    printf("%d %d %d",max+1,x,y); // @@ [If no chain is found (e.g., only one segment or all chains broken due to loop bounds), max remains 0 and x,y remain 0,0 — but the correct answer should at least be 1 and the starting point of some segment. Also, the starting point recorded is from the head of the chain (wz[i]), but in DP chaining, we should track the actual start of the full chain, not just the current segment's start.]
    return 0;
}