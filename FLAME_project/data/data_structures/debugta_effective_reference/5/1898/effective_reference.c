#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
	int x,y;
}node;
node A[110000],B[110000],C[1100000];
int cmp(const void *xx,const void *yy)
{
	node n1=*(node *)xx;
	node n2=*(node *)yy;
	return n2.y-n1.y;
}
int main()
{
	int i=0,j=0,x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		A[++i].x=x;A[i].y=y;
		char C=getchar();
		if(C=='\n') break;
	}
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		B[++j].x=x;B[j].y=y;
		char C=getchar();
		if(C=='\n') break;
	}
	int k=0;
	for(int i=1;i<=i;i++)
	{
		for(int j=1;j<=j;j++)
		{
			k++;
			C[k].x=A[i].x*B[j].x;
			C[k].y=A[i].y+B[j].y;
		}
	}
	qsort(C+1,k,sizeof(node),cmp);
	x=C[1].x;y=C[1].y;
	for(int i=2;i<=k;i++)
	{
		if(y==C[i].y) x+=C[i].x;
		else
		{
			printf("%d %d ",x,y);
			x=C[i].x,y=C[i].y;
		}
	}
	printf("%d %d ",x,y);
	return 0;
}

