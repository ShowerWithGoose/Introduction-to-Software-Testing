#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
	int x,y;
}node;
node a[110000],b[110000],c[1100000];
int cmp(const void *xx,const void *yy)
{
	node n1=*(node *)xx;
	node n2=*(node *)yy;
	return n2.y-n1.y;
}
int main()
{
	int A=0,B=0,x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		a[++A].x=x;a[A].y=y;
		char c=getchar();
		if(c=='\n') break;
	}
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		b[++B].x=x;b[B].y=y;
		char c=getchar();
		if(c=='\n') break;
	}
	int C=0;
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			C++;
			c[C].x=a[i].x*b[j].x;
			c[C].y=a[i].y+b[j].y;
		}
	}
	qsort(c+1,C,sizeof(node),cmp);
	x=c[1].x;y=c[1].y;
	for(int i=2;i<=C;i++)
	{
		if(y==c[i].y) x+=c[i].x;
		else
		{
			printf("%d %d ",x,y);
			x=c[i].x,y=c[i].y;
		}
	}
	printf("%d %d ",x,y);
	return 0;
}

