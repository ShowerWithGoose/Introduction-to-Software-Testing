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
                    merge(i,j,n);
                    n--;
                    j=0;
                    flag++;
                }
                else if((L[i].x1==L[j].x2)&&(L[i].y1==L[j].y2)) // @@ Allows reverse connection, violating the increasing x order requirement, leading to incorrect chain formation.
                {
                    merge(j,i,n);
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
        if(L[i].count>max) // @@ Should also update max = L[i].count; otherwise, the condition uses the same max value and will incorrectly pick later segments that exceed the initial max but not necessarily the global maximum.
        max_cursor=i; 
    }
    printf("%d %d %d",L[max_cursor].count,L[max_cursor].x1,L[max_cursor].y1);
    return 0;
}