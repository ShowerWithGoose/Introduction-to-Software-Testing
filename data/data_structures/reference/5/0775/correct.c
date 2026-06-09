#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int x[100005],y[100005];
struct LLN
{ 
	int num;
	int data;
};
struct LLN a[10005],b[10005],c[10005];
int cmp(const void *pa,const void *pb)
{
	struct LLN x=*(struct LLN*)pa;
	struct LLN y=*(struct LLN*)pb;
	if(y.data==x.data)
		return y.num-x.num; 
	else
		return y.data-x.data;
	
}
int main()
{
	int i=0,j=0,k=0,n,m;
	char q;
	while(1)
	{
		scanf("%d%d%c",&a[i].num,&a[i].data,&q);
		if(q=='\n')
			break;
		i++;
	}
	while(1)
	{
		scanf("%d%d%c",&b[j].num,&b[j].data,&q);
		if(q=='\n')
			break;
		j++;
	}
	for(m=0;m<=i;m++)
	{
		for(n=0;n<=j;n++)
		{
			c[k].data=a[m].data+b[n].data; 
			c[k].num=a[m].num*b[n].num;
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(m=0;m<k;m++)
	{
		if(c[m].data==c[m+1].data)
		{
			c[m+1].num+=c[m].num;
			c[m].num=0;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(m=0;m<=k;m++)
	{
		if(c[m].num==0)
			continue;
		else
		{
			printf("%d %d ",c[m].num,c[m].data);
		}
	}
	return 0;	
} 


