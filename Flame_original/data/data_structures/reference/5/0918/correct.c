#include<stdio.h>
#include<stdlib.h>
struct n{
	int num;
	int en;
}a[100000],b[100000],c[100000];
int cmp(const void *a,const void *b)
{
	struct n *c=(struct n *)a;
	struct n *d=(struct n *)b;
	return d->en-c->en;
}
char o=' ';
int main()
{
	int i=0;
	int j=0;
	int k=0;
	while(o!='\n')
	{
		scanf("%d%d%c",&a[i].num,&a[i].en,&o);
		++i;
	}
	o=' ';
	while(o!='\n')
	{
		scanf("%d%d%c",&b[j].num,&b[j].en,&o);
		++j;
	}
	for(int t=0;t<i;t++)
	{
		for(int s=0;s<j;s++)
		{
			c[k].num=a[t].num*b[s].num;
			c[k].en=a[t].en+b[s].en;
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(int t=0;t<k;t++)
	{
		if(c[t].en==c[t+1].en&&c[t].en!=0)
		{
			c[t+1].num=c[t].num+c[t+1].num;
			c[t].num=0;
		}
	}
	for(int t=0;t<k;t++)
	{
		if(c[t].num!=0)
		{
			printf("%d %d ",c[t].num,c[t].en);
		}
	}
	return 0;
}

