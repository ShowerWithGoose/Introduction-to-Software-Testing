#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	int a;
	int n;
};
int cmp(const void *a,const void *b)
{
	return (*(struct node *)a).n-(*(struct node *)b).n;
}
char p,q;
int main()
{
	struct node b[10000];
	struct node c[10000];
	struct node d[10000];
	int i=0,f=0,g=0;
	while(1){
	scanf("%d%d%c",&b[i].a,&b[i].n,&p);
	i++;
	if(p=='\n')
	{
		break;
	}
	
	}
	f=i;
	int j=0;
	while(1){
	scanf("%d%d%c",&c[j].a,&c[j].n,&q);
	j++;
	if(q=='\n')
	{
		break;
	}
	
	}
	g=j;
	int k=0;
	i=0,j=0;
	for(k=0;k<(f*g);k++)
	{
		d[k].a=b[i].a*c[j].a;
		d[k].n=b[i].n+c[j].n;
		i++;
		if(i==f)
		{
			i=0;
			j++;
		}
	}
	qsort(d,k,sizeof(struct node),cmp);
	int h=0;
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(d[i].n==d[j].n)
			{
				d[i].a=d[j].a+d[i].a;
				for(h=j;h<k-1;h++)
				{
					d[h].a=d[h+1].a;
					d[h].n=d[h+1].n;
				}
					k--;
					j--;
			}
		}
	}
//	for(i=0;i<f;i++)
//	{
//	printf("%d %d ",b[i].a,b[i].n);
//	}
//	printf("\n");
//	for(i=0;i<g;i++)
//	{
//	printf("%d %d ",c[i].a,c[i].n);
//	}
//	printf("\n");
	for(i=k-1;i>=0;i--)
	{
	printf("%d %d ",d[i].a,d[i].n);
	}
	
return 0;
}


