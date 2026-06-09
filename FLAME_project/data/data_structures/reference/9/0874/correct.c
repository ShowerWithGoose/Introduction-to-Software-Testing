#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int x1,y1,x2,y2;
	int fpt,pt;
}a[100005];
int n;
int main()
{
    scanf("%d",&n);int i,j;
    for(i=1;i<=n;i++){scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);a[i].fpt=a[i].pt=-1;}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    if(i!=j&&a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
    {
    	a[i].pt=j;a[j].fpt=i;
    }
    int ans=0,ansx,ansy;
    for(i=1;i<=n;i++)if(a[i].fpt==-1)
    {
    	int ji=0,k=i;
    	for(;k!=-1;k=a[k].pt)ji++;
    	if(ji>ans)
    	{
    		ans=ji;ansx=a[i].x1;ansy=a[i].y1;
    	}
    }
    printf("%d %d %d",ans,ansx,ansy);
	return 0;
} 

