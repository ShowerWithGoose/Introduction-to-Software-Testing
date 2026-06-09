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
    L[j]=L[j+1];
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
                    merge(i,j,n); // @@ Logical error: shifting the array left changes indices; if j < i, the element at index i is replaced by the next one, causing the outer loop to skip segments or process incorrect ones
                    n--;
                    j=0;
                    flag++;
                }
                else if((L[i].x1==L[j].x2)&&(L[i].y1==L[j].y2))
                {
                    merge(j,i,n); // @@ Logical error: same index shifting issue as above, leading to incorrect traversal and potential missed merges
                    n--;
                    j=0;
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
        max_cursor=i; // @@ Logical error: max is not updated when a larger count is found, so max_cursor will incorrectly point to the last segment with count > initial max, not the actual maximum
    }
    printf("%d %d %d",L[max_cursor].count,L[max_cursor].x1,L[max_cursor].y1);
    return 0;
}