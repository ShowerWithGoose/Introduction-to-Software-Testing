#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int n;
}node; 
int cmp(const void* p1,const void* p2)
{
	struct node* c=(node*)p1;
	struct node* d=(node*)p2;
	return d->n-c->n;
}
struct node a[114514],b[114514];
struct node p[114514]; 
int main()
{
	int numa=0,numb=0;
	char c='/0';
	while(c!='\n')
	{
		scanf("%d%d%c",&a[numa].data,&a[numa].n,&c);
		numa++;
	}
	c='/0';
	while(c!='\n')
	{
		scanf("%d%d%c",&b[numb].data,&b[numb].n,&c);
		numb++;
	}
	int i,j,k=0;
	for(i=0;i<numa;i++)
	{
		for(j=0;j<numb;j++)
		{
			p[k].data=a[i].data*b[j].data;
			p[k].n=a[i].n+b[j].n;
			k++;
		}
	}
	qsort(p,k,sizeof(a[0]),cmp);
	for(i=0;i<k;i++)
	{
		if(p[i].n==p[i+1].n&&p[i].n!=0)
		{
			p[i+1].data+=p[i].data;
			p[i].data=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(p[i].data!=0)
		{
			printf("%d %d ",p[i].data,p[i].n);
		}
	}
	return 0;
}


