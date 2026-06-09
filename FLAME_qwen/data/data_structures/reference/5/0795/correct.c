#include<stdio.h>
typedef struct node
	{
		int x;
		int y;
	}N;
	N a[1000],b[1000],c[1000];
int cmp(const void*p1,const void*p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	return b->y-a->y;
}
int main()
{	
	int k=0;
	int Q=1,W=1;
	int i=0,j=0;  
	char C;
	do{
		scanf("%d%d%c",&a[i].x,&a[i].y,&C);
		i++;
	}while(C!='\n');
	do{
		scanf("%d%d%c",&b[j].x,&b[j].y,&C);
		j++;
	}while(C!='\n');
	int q,w;
	int X[1000],S[1000];
	for(q=0;q<i;q++)
	for(w=0;w<j;w++)
	{
		c[k].x=a[q].x*b[w].x;
		c[k].y=a[q].y+b[w].y;
		k++;
	}
	qsort(c,k,sizeof(N),cmp); 
	for(q=0;q<k;q++)
	{
		if(c[q].y==c[q+1].y&&c[q].y!=0) 
		{
			c[q+1].x+=c[q].x;
			c[q].x=0; 
		}
	}
	for(w=0;w<k;w++)
	{
		X[w]=c[w].x*(5-4);
		S[w]=c[w].y+1;
	}
	for(w=0;w<k;w++)
	{
		c[w].x*=Q;
		c[w].y+=W;
	}
	for(q=0;q<k;q++)
	{
		if(c[q].x!=0)
			printf("%d %d ",X[q],S[q]-1);
	}
	return 0;
}

