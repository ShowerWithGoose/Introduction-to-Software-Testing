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
    L[j]=L[j+1]; // @@ [This loop accesses L[j+1] when j == n-1, causing out-of-bounds read/write; also, shifting elements this way corrupts data and breaks linkage tracking]
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
                    j=0; // @@ [Resetting j to 0 inside the loop causes reprocessing of already merged segments and may skip some due to loop increment; also leads to undefined behavior after array shift]
                    flag++;
                }
                else if((L[i].x1==L[j].x2)&&(L[i].y1==L[j].y2))
                {
                    merge(j,i,n);
                    n--;
                    j=0; // @@ [Same issue as above: resetting j disrupts loop logic and causes incorrect iteration after modifying array size and contents]
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
        max_cursor=i; // @@ [Missing update of 'max' variable; so comparison always uses initial max=0 or stale value, leading to wrong max_cursor selection]
    }
    printf("%d %d %d",L[max_cursor].count,L[max_cursor].x1,L[max_cursor].y1);
    return 0;
}