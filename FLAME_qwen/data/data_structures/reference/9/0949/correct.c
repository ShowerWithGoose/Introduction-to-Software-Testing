#include<stdio.h>
#define Maxn 105 
struct node{
    int x1,x2,y1,y2;
}Line[Maxn];
int n,ans=0,num;
void dfs(int ori,int j,int sum)
{
    if(sum>ans)
    {
        ans=sum;
        num=ori;
    }
    for(int i=0;i<n;i++)
        if(Line[j].x2==Line[i].x1&&Line[j].y2==Line[i].y1)
        {
            dfs(ori,i,sum+1);
        }
    
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&Line[i].x1,&Line[i].y1,&Line[i].x2,&Line[i].y2);
    for(int i=0;i<n;i++)
        dfs(i,i,0);
    printf("%d %d %d",ans+1,Line[num].x1,Line[num].y1);
    return 0;
}
