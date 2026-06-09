#include<stdio.h>
typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}Line;
Line L[105];
void merge(int i,int j,int n)
{
    L[i].x2=L[j].x2;
    L[i].y2=L[j].y2;
    L[i].count+=L[j].count;
    for(;j<n;j++)
    L[j]=L[j+1]; // @@ [This loop accesses L[j+1] when j == n-1, causing out-of-bounds read/write. Also, after shifting elements, the loop condition and index management are flawed, leading to incorrect merging and potential data corruption.]
}
int main()
{
    int n,flag=1,max=0,max_cursor=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&L[i].x1,&L[i].y1,&L[i].x2,&L[i].y2);
        L[i].count=1;
    }
    while(flag)
    {
        flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(j==i)
                continue;
                if((L[i].x2==L[j].x1)&&(L[i].y2==L[j].y1))
                {
                    merge(i,j,n);
                    n--;
                    j=0; // @@ [Resetting j to 0 inside the loop causes reprocessing of already checked indices and may skip some pairs due to loop increment after continue or break-like behavior. This leads to incomplete or incorrect merging.]
                    flag++;
                }
                else if((L[i].x1==L[j].x2)&&(L[i].y1==L[j].y2))
                {
                    merge(j,i,n);
                    n--;
                    j=0; // @@ [Same issue as above: resetting j to 0 disrupts loop iteration logic and can cause missed merges or infinite loops in some cases.]
                    flag++;
                }
            }
        }
    }
    max=L[0].count;
    max_cursor=0;
    for(int i=0;i<n;i++)
    {
        if(L[i].count>max)
        max_cursor=i; // @@ [The variable 'max' is never updated in this loop, so the comparison always uses the initial value (L[0].count). Thus, max_cursor may not point to the actual maximum element.]
    }
    printf("%d %d %d",L[max_cursor].count,L[max_cursor].x1,L[max_cursor].y1);
    return 0;
}