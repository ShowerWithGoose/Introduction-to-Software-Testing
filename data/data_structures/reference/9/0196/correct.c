#include<stdio.h>
#include<stdlib.h>
struct node{
	int x1,y1,x2,y2,num,fa;
}a[105];
int cmp(const void *p1,const void *p2)
{
	struct node *a=(struct node *)p1;
	struct node *b=(struct node *)p2;
	return a->x1-b->x1;
}
int main()
{
	int i,n,j,max=1,fl;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2),a[i].num=1;
	qsort(a+1,n,sizeof(struct node),cmp);
	for(i=1;i<=n;i++)
	    for(j=i+1;j<=n;j++)
	    if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2)
		{
			a[j].fa=i;
			a[j].num=a[i].num+1;
			if(a[j].num>=max) 
			{
				max=a[j].num;
				fl=j;
			}
	    }
	while(a[fl].fa) fl=a[fl].fa;
	printf("%d %d %d",max,a[fl].x1,a[fl].y1);
 } 

