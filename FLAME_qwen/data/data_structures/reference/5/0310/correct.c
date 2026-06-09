#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct multi{
	int a,b;
}a1[1010],b1[1010],c1[4040];
typedef struct multi *node;
int fun(const void *a,const void *b)
{
	node p=(node)a;
	node q=(node)b;
	return q->b-p->b;
}
int main()
{
	int i,j,n=0;
	int l1=0,l2=0;
	for(i=0;;i++)
	{
		scanf("%d%d",&a1[i].a,&a1[i].b);
		l1++;
		if(getchar()=='\n')	break;
	}
	for(i=0;;i++)
	{
		scanf("%d%d",&b1[i].a,&b1[i].b);
		l2++;
		if(getchar()=='\n')	break;
	}
	qsort(a1,l1,sizeof(a1[0]),fun);
	qsort(b1,l2,sizeof(b1[0]),fun);
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			c1[n].a=a1[i].a*b1[j].a;
			c1[n].b=a1[i].b+b1[j].b;
			n++;
		}
	}
	qsort(c1,n,sizeof(c1[0]),fun);
	for(i=0;i<n;i++)
	{
		if(c1[i].b==c1[i+1].b&&c1[i+1].b!=0)
		{
			c1[i+1].a+=c1[i].a;
			c1[i].a=0;
		}
	}
	qsort(c1,n,sizeof(c1[0]),fun);
	for(i=0;i<n;i++)
	{
		if(!c1[i].a)	continue;
		else
			printf("%d %d ",c1[i].a,c1[i].b);
	}
	return 0;
}

