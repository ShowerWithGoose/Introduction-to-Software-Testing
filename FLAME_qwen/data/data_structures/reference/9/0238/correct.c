#include <stdio.h>
#include <stdlib.h>

typedef struct date{
	int x1;
	int y1;
	int x2;
	int y2;
	int a;
}Date;


int cmp(const void*_a,const void*_b)
{
	Date *a =(Date*)_a;
	Date *b =(Date*)_b;
	return (a->x1)<(b->x1)?-1:1;
}

int main()
{
	int n,i,z=0;
	int j,sum[100]={0},l,max=0;
	int flag_i,max_i;
	Date line[200];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	qsort(line,n,sizeof(line[0]),cmp);
	//排序没有问题
	
	 
	for(i=0;i<n;i++)
	{
		line[i].a=0;
	}
	for(flag_i=0;flag_i<n;flag_i++)
	{
		line[flag_i].a=1;
		i=flag_i;
		for(j=i;j<n;j++)
		{
			if(line[j].a==1) continue;
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)//找收尾相同的点 
			{
				i = j;
				line[i].a = 1;
				continue;
			}
		}
		for(l=0;l<n;l++)//用累计加法，第二次所有减去第一次所有 
		{
			if(z==0) sum[0] += line[l].a;
			else 
			{
				sum[z] += line[l].a;
			}
		}
		if(z==0)
		{
			max_i = flag_i;
			max = sum[0];
		}
		else
		{
			if(max<(sum[z]-sum[z-1]))
			{
				max_i = flag_i;
				max = sum[z]-sum[z-1];
			}
		
		}
	
		z++;
	}
	printf("%d %d %d",max,line[max_i].x1,line[max_i].y1);
	return 0;
	
}

