#include<stdio.h>
#include <stdlib.h>
struct Line
{
	int headx;
	int heady;
	int tailx;
	int taily;
	int num;
};
int cmp(const void*a,const void*b)
	{
		struct Line *a1 = (struct Line*)a;
		struct Line *b1 = (struct Line*)b;
		if(((*a1).headx-(*b1).headx)<0)
			return -1;
		return 1;
	}
int main()
{
	struct Line a[110];
	int n,flag[110]={0},max=-1,num,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].headx,&a[i].heady,&a[i].tailx,&a[i].taily);
	}
	qsort(a,n,sizeof(struct Line),cmp);
	k=0;
	for(i=k;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k].tailx==a[j].headx)
			{
				if(a[k].taily==a[j].heady)
				{
					flag[i]++;
					k=j;
				}
					
			}	
		}
	}
	for(i=0;i<n;i++)
	{
		if(flag[i]>max)
		{
			max = flag[i];
			num = i;
		}	
	}
	printf("%d ",max+1);
	printf("%d %d",a[num].headx,a[num].heady);
	return 0;
} 
//qsort¿ìÅÅ 
/*
int cmp(const void*a,const void*b){
    struct data *a1=(struct data*)a;
    struct data *b1=(struct data*)b;
    if(strcmp(a1->name,b1->name)<0)
        return -1;
    return 1;
    */
    

