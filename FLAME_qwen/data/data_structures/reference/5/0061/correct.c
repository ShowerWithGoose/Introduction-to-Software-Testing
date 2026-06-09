#include<stdio.h>
#include<string.h>
struct exp{			
	int co;				 
	int en;				 
};
typedef struct exp ex;
ex a[2000],b[2000],c[2000];
int cmp(const void*p1,const void*p2);
int main()
{	
	int i,j,k=0;
	int n=0,m=0;
	char ch;
	do   
	{
		scanf("%d%d%c",&a[n].co,&a[n].en,&ch);
		n++;
	}while(ch!='\n');
	do
	{
		scanf("%d%d%c",&b[m].co,&b[m].en,&ch);
		m++;
	}while(ch!='\n');
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[k].co=a[i].co*b[j].co;
			c[k].en=a[i].en+b[j].en; 
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp); 
	for(i=0;i<k;i++)
	{
		if(c[i].en == c[i+1].en && c[i].en!=0)
		{
			c[i+1].co+=c[i].co;
			c[i].co=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(c[i].co==0) 
			continue;
		else
			printf("%d %d ",c[i].co,c[i].en);
	}
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct exp *a=(struct exp*)p1;
	struct exp *b=(struct exp*)p2;
	return b->en-a->en;
}


