#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int num;
	int co;
};
typedef struct node mulit;
mulit a[3000],b[3000],c[3000];
int cmp(const void*p1,const void*p2)
{
 struct node *a=(struct node*)p1;
 struct node *b=(struct node*)p2;
 return b->co-a->co;
}
int main()
{
	int m=0,n=0,k=0;
	char s;
	do
	{
		scanf("%d%d%c",&a[n].num,&a[n].co,&s);
		n++;
	}while(s!='\n');
	do
	{
		scanf("%d%d%c",&b[m].num,&b[m].co,&s);
		m++;
	}while(s!='\n');
	qsort(a,n,sizeof(mulit),cmp);
	qsort(b,m,sizeof(mulit),cmp);
	for(int i = 0; i<n;i++)
	{
		for(int j = 0; j < m ;j++)
		{
			c[k].num = a[i].num * b[j].num;
			c[k].co = a[i].co + b[j].co;
			k++;
		}
	}
	qsort(c,k,sizeof(mulit),cmp);
	for(int i=0;i<k;i++)
	{
		if(c[i].co == c[i+1].co)
		{
			c[i+1].num = c[i].num + c[i+1].num;
			c[i].num =0;
		}
	}
	for(int i = 0; i<=k;i++)
	{
		if(c[i].num==0)
		continue;
		else 
		printf("%d %d ",c[i].num,c[i].co);
	}
	return 0;

}	

