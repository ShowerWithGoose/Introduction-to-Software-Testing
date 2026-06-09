#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a,const void *b);

struct node{
	int xi;
	int zhi;
}a[100000],b[100000],c[100000];

int main()
{
	char dot=' ';
	int numa=0,numb=0;
	
	//读入第一个多项式
	while(dot != '\n')
	{
		scanf("%d%d%c",&a[numa].xi,&a[numa].zhi,&dot); 
		numa++;
	}
	dot=' ';

	//读入第二个多项式 
	while(dot != '\n')
	{
		scanf("%d%d%c",&b[numb].xi,&b[numb].zhi,&dot); 
		numb++;
	}
	dot=' ';

	
	//两个多项式相乘
	int k=0,i=0,j=0;
	for(i=0;i<numa;i++)
	{
	 	for(j=0;j<numb;j++)
	 	{
	 		c[k].xi=a[i].xi * b[j].xi;
	 		c[k].zhi=a[i].zhi + b[j].zhi;
	 		k++;
		}
	}
	
	//指数从小到大快排，确保两两之间就能比较而不是乱序
	qsort(c,k,sizeof(c[0]),cmp);
	
	for(i=0;i<k;i++)
	{
		if((c[i].zhi == c[i+1].zhi))
		{
			c[i+1].xi=c[i].xi+c[i+1].xi;
			c[i].xi=0;
		}
	} 
	
	for(i=0;i<=k;i++)
	{
		if(c[i].xi != 0)
		{
			printf("%d %d ",c[i].xi,c[i].zhi);
		}
	}
	 return 0;
}


int cmp(const void *a,const void *b)
{
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	return d->zhi - c->zhi;
}

