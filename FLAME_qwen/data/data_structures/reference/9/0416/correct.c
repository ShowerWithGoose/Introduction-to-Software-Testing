#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct dot{
	int leftx,lefty;
	int rightx,righty;
	int num;			//记录每条线段的段数 
}dot[120];

int cmp(const void *a,const void *b);

int main()
{
	struct dot dot[120];
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&dot[i].leftx,&dot[i].lefty,&dot[i].rightx,&dot[i].righty);
		dot[i].num=1;
	}
	
	qsort(dot,n,sizeof(dot[0]),cmp);	
	
	int j=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((dot[i].leftx == dot[j].rightx) && (dot[i].lefty == dot[j].righty))
				dot[j].num+=dot[i].num;
		}
	} 
	
	int max=0,flag=0;
	for(i=0;i<n;i++)
	{
		if(dot[i].num>max)
		{			
			max=dot[i].num;
			flag=i;
		}	
	}
	
	printf("%d %d %d",max,dot[flag].leftx,dot[flag].lefty);
	return 0;	
}

int cmp(const void *a,const void *b)
{
	struct dot *c=(dot *)a;
	struct dot *d=(dot *)b;
	
	if(c->leftx != d->rightx)
		return d->leftx - c->leftx;
	else
		return d->lefty - c->lefty;
} 

