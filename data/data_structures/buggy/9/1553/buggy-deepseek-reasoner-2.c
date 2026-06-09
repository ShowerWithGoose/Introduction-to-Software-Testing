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
    int n,max=0,num[101]={}; // @@ array size may be insufficient for large n (runtime error)
    int x=0,y=0;
    scanf("%d",&n);
    struct xy wz[100]; // @@ array size may be insufficient for large n (runtime error)
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&wz[i].x1,&wz[i].y1,&wz[i].x2,&wz[i].y2);
    }
    qsort(wz,n,sizeof(struct xy),cmp); // @@ missing #include <stdlib.h> for qsort (compilation error)
    for(int i=n-1;i>0;i--) // @@ loop condition i>0 should be i>=0; otherwise the first segment (smallest x1) is never processed as a predecessor
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
    
    printf("%d %d %d",max+1,x,y); // @@ for isolated segments, x and y remain 0 instead of the segment's own start coordinates
    return 0;
}