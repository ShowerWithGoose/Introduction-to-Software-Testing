#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct node{
	int x1,y1,x2,y2;
	int l,r;
}s[1000]; 
int n=0,cnt=0;
int cmp(const void*p,const void *q)
{
	struct node*a,*b;
	a=(struct node *)p;
	b=(struct node *)q; 
	if (a->x1>b->x1) 
	return 1;
	else return -1;
}
void add()
{
	int i,j,k;
	int book[1000]={0};
	for (i=1;i<=n;i++)
	{
		for (j=1;j<i;j++)
		{
			if (s[j].x2==s[i].x1&&s[j].y2==s[i].y1)
			{
			  s[j].r=i;
			  s[i].l=j;
			  book[i]=1;	
			}
		}
	}
	int sum=0,max=-1,x=0,y=0;
	for (i=1;i<=n;i++)
	{
		k=i;
		if (book[i]==1) continue;
		sum=1;
		while (s[k].r!=-1)
		{
			sum++;
			k=s[k].r;
		}
		if (sum>max) {
		max=sum;
		x=s[i].x1;
		y=s[i].y1;
	}
	}
	printf("%d %d %d",max,x,y);
	return;
}
int main()
{
		int i,j,k;
	scanf("%d",&n);

	for (i=1;i<=n;i++)
   {
    scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
    s[i].l=-1;
    s[i].r=-1;
   }
   qsort(&s[1],n,sizeof(s[0]),cmp);

   add();
	return 0;
}


