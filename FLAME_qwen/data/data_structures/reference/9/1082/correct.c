#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int x1,y1;
	int x2,y2;
}node[105];

bool lian(int i,int j)
{
	if(node[i].x2==node[j].x1 && node[i].y2==node[j].y1) return 1;
	return 0;
}

int cmp(const void *m,const void *n)
{
	struct Node *M=(struct Node*)m;
	struct Node *N=(struct Node*)n;
	return (M->x1)-(N->x1);
}

int main()
{
	int n;
	int max=1,c=0,ip,f=0,step0=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
	}
	qsort(node,n,sizeof(node[0]),cmp);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(lian(i,j))
			{
				node[i].x2=node[j].x2;
				node[i].y2=node[j].y2;
				c++;
			}
		}	
		if(max<c)
		{
			max=c;
			step0=i;
		}
		c=0;
	}
	printf("%d %d %d\n",max+1,node[step0].x1,node[step0].y1);
} 

