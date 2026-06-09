#include<stdio.h>
#include<stdlib.h>
struct node{
	int l,r,h,x;
}a[10005];
int num;
void insert(int pos)
{
	if(a[num].x<a[pos].x)
	{
		if(a[pos].l==0) 
		{
			a[pos].l=num;
			a[num].h=a[pos].h+1;
			return;
		}
		insert(a[pos].l);  
	}
	else 
	{
		if(a[pos].r==0) 
		{
			a[pos].r=num;
			a[num].h=a[pos].h+1;
			return;
		}
		insert(a[pos].r);  
	}
 } 
void bianli(int pos)
{
	if(a[pos].l==0&&a[pos].r==0) 
	{
		printf("%d %d\n",a[pos].x,a[pos].h);
		return;
	}
	if(a[pos].l) bianli(a[pos].l);
	if(a[pos].r) bianli(a[pos].r);
}
int main()
{
	int n,x,i;
	scanf("%d",&n);
	scanf("%d",&a[++num].x);a[1].h=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		a[++num].x=x;
		insert(1);
	}
	bianli(1);
 } 

