#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct exp{			 
	int co;				
	int po;				
};
typedef struct exp ex;
ex a[3000],b[3000],d[3000];
int cmp(const void*p1,const void*p2)
{
	struct exp *a=(struct exp*)p1;
	struct exp *b=(struct exp*)p2;
	return b->po-a->po;
}
int main()
{	
	int i,j,k=0,n=0,m=0;
	char c;
	do   
	{
		scanf("%d%d%c",&a[n].co,&a[n].po,&c);
		n++;
	}while(c!='\n');
	do	
	{
		scanf("%d%d%c",&b[m].co,&b[m].po,&c);
		m++;
	}while(c!='\n');
	qsort(b,m,sizeof(ex),cmp);
	qsort(a,n,sizeof(ex),cmp);
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			d[k].po=a[i].po+b[j].po;
			d[k].co=a[i].co*b[j].co; 
			k++;
		}
	}
	qsort(d,k,sizeof(ex),cmp); 
	for(i=0;i<=k-1;i++)
	{
		if(d[i].po==d[i+1].po&&d[i].po!=0) 
		{
			d[i+1].co+=d[i].co;
			d[i].co=0; 
		}
	}
	qsort(d,k,sizeof(ex),cmp); 
	for(i=0;i<k;i++)
	{
		if(d[i].co!=0)
		{
			printf("%d %d ",d[i].co,d[i].po);
		}
	}
	return 0;
}


