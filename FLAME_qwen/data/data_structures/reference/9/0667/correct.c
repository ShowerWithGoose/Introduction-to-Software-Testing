#include<stdio.h>
struct position{
	int x1;
	int y1;
	int x2;
	int y2; 
};
int main()
{
	struct position data[1000],tmp;
	int i=0,n,j=0,num=0,xx,yy,maxnum=0,shou1,shou2;
	scanf("%d",&n);
	while(i<n)
	{
		scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
		i++;
	}
	i=0;
	while(i<n-1) //横轴从小到大排序 
	{
		while(j<n-i-1)
		{
			if(data[j].x1>data[j+1].x1)
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
			j++;
		}
		i++; j=0;
	}
	i=0; j=1; 
	while(i<n-1)
	{
		shou1=data[i].x2; shou2=data[i].y2;
		while(j<n)
		{
			if(shou1==data[j].x1 && shou2==data[j].y1)
			{
				shou1=data[j].x2; shou2=data[j].y2;
				num++;
			}
			j++;
		}
		if(num>maxnum)
		{
			maxnum=num; xx=data[i].x1; yy=data[i].y1;
		}
		i++; num=0; j=i+1;
	}
	printf("%d %d %d",maxnum+1,xx,yy);
	return 0;
}

