#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct js
{
	int xi;//系数 
	int zhi;//指数 
}a[10000],b[10000],c[10000],exchange;
void order(struct js c[10000],struct js exchange,int q);
int main()
{
	int i=0,j=0,f,k,q=0,Q;
	char p=' ';
	while(p!='\n')
	{
		scanf("%d %d%c",&a[i].xi,&a[i].zhi,&p);//第一行 
		i=i+1;
	}
	p=' ';
	while(p!='\n')
	{
		scanf("%d %d%c",&b[j].xi,&b[j].zhi,&p);//第二行 
		j=j+1;
	}
	for(k=0;k<i;k++)
	{
		for(f=0;f<j;f++)//相乘 
		{
			c[q].xi=a[k].xi *b[f].xi;
			c[q].zhi=a[k].zhi+b[f].zhi;
			q=q+1;
		}
	}
	Q=q;//相乘后的项数 
	for(i=0;i<Q;i++)
	{
		for(j=i+1;j<Q;j++)
		{
			if(c[i].zhi==c[j].zhi)//合并指数相同的项 
			{
				c[i].xi=c[i].xi+c[j].xi;//系数相加 
				c[j].xi=0;//系数赋值0，便于输出时跳过 
			}
		}
	}
	order(c,exchange,Q);//排序 
	for(i=0;i<Q;i++)
	{
		if(c[i].xi!=0)
		{
			printf("%d %d ",c[i].xi,c[i].zhi);//输出系数不为0的 
		}
	}
	return 0;
}
void order(struct js c[10000],struct js exchange,int q)
{
	int i,j;
	for(i=0;i<q;i++)
	{
		for(j=i+1;j<q;j++)
		{
			if(c[i].zhi<c[j].zhi)
			{
				exchange=c[i];
				c[i]=c[j];
				c[j]=exchange;
			}
		}
	}
}


