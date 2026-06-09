#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct x
{	int xi;
	int mi;
};
void lowbubble(struct x a[],int n)
{	int i,j;
	struct x tmp;
	for(i=0;i<=n-1;i++)
	for(j=n;j>=i+1;j--)
	if(a[j].mi>a[j-1].mi)
	tmp=a[j],a[j]=a[j-1],a[j-1]=tmp;
}
int main()
{	struct x a[10005],b[10005],ans[10005];
	int i=0,j=0,n=0,m,k,l,y;
	char p,q=' ';
	while(q!='\n')
	{	scanf("%d%c%d%c",&a[i].xi,&p,&a[i].mi,&q);
		i++;
	}
	q=' ';
	while(q!='\n')
	{	scanf("%d%c%d%c",&b[j].xi,&p,&b[j].mi,&q);
		j++;
	}
	for(k=0;k<i;k++)
	for(l=0;l<j;l++)
	{	ans[n].xi=a[k].xi*b[l].xi;
		ans[n++].mi=a[k].mi+b[l].mi;
	}
	lowbubble(ans,n);
	for(m=0;m<n;m++)
	if(ans[m].mi==ans[m-1].mi)
	{	ans[m-1].xi+=ans[m].xi;
		for(y=m;y<n-1;y++)
		ans[y]=ans[y+1];
		n--;m--;
	}
	for(m=0;m<n;m++)
	printf("%d %d ",ans[m].xi,ans[m].mi);
	return 0;
}



