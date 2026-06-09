#include<stdio.h>

struct line 
{
	int headx;
	int heady;
	int endx;
	int endy;
};

int main()
{
	int n,ans,max,temx,temy,temmax;
	int i,j;
	struct line le[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&le[i].headx,&le[i].heady,&le[i].endx,&le[i].endy);
	
	max=0;
	ans=0;
	temmax=0;
	
	for(i=0;i<n;i++)
	{
		temx=le[i].endx;
		temy=le[i].endy;
		
		for(j=0;j<n;j++)
		{
			if(temx==le[j].headx&&temy==le[j].heady)
			{
				max++;
				temx=le[j].endx;
				temy=le[j].endy;
				j=-1;
			}//若当前线段起点可以被连接，则再遍历一次寻找下一个连接 
		}
		
		if(max>temmax)
		{
			temmax=max;
			ans=i;
		}
		
		max=0;
		
		}
		
		printf("%d %d %d",temmax+1,le[ans].headx,le[ans].heady);
		return 0;
}


