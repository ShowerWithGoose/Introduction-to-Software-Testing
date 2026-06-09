#include<stdio.h>
#include<string.h>
struct line
{	int x1;
	int y1;
	int x2;
	int y2;
};
void upbubble(struct line a[],int n)
{	int i,j;
	struct line tmp;
	for(i=0;i<=n-1;i++)
	for(j=n;j>=i+1;j--)
	if(a[j].x1<a[j-1].x1)
	tmp=a[j],a[j]=a[j-1],a[j-1]=tmp;
}
int search(struct line a[],int m,int n)
{	int i;
	for(i=m+1;i<n;i++)
	if(a[m].x2==a[i].x1&&a[m].y2==a[i].y1)
	break;
	if(i==n)
	return 0;
	return 1+search(a,i,n);
}
int main()
{	int n,i,ans[10005],max=0,flag;
	scanf("%d\n",&n);
	struct line sum[10005];
	for(i=0;i<n-1;i++)
	scanf("%d%d%d%d\n",&sum[i].x1,&sum[i].y1,&sum[i].x2,&sum[i].y2);
	scanf("%d%d%d%d",&sum[i].x1,&sum[i].y1,&sum[i].x2,&sum[i].y2);
	upbubble(sum,n);
	for(i=0;i<n;i++)
	ans[i]=search(sum,i,n)+2;
	for(i=0;i<n;i++)
	if(ans[i]>=max)
	max=ans[i],flag=i;
	printf("%d %d %d",max,sum[flag].x1,sum[flag].y1);
	return 0;
}



