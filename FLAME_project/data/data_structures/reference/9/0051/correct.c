//3_1
#include <stdio.h>

struct point
{
	int x;
	int y;
	int num;
};

int main(int argc, char const *argv[])
{
	struct point p[205],ca1,ca2;
	int n,con[105][105]={},sw[105]={},ansn=0,ansx,ansy,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&ca1.x,&ca1.y,&ca2.x,&ca2.y);
		int flag1=0,flag2=0,num1,num2;
		for(int j=0;j<sum;j++)
		{
			if(ca1.x==p[j].x&&ca1.y==p[j].y) flag1=1,num1=p[j].num;
			if(ca2.x==p[j].x&&ca2.y==p[j].y) flag2=1,num2=p[j].num;
		}
		if(!flag1)
		{
			p[sum].x=ca1.x;
			p[sum].y=ca1.y;
			p[sum].num=sum;
			num1=sum;
			sum++;
		}
		if(!flag2)
		{
			p[sum].x=ca2.x;
			p[sum].y=ca2.y;
			p[sum].num=sum;
			num2=sum;
			sum++;
		}
		con[num1][num2]=1;
		con[num2][num1]=1;
		sw[num1]=1;
		sw[num2]=1;
	}
	for(int i=0;i<sum-1;i++)
	{
		for(int j=0;j<sum-i-1;j++)
		{
			if(p[j].x>p[j+1].x)
			{
				struct point tmp;
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<sum-1;i++)
	{
		if(sw[p[i].num])
		{
			int cnt=0,left=p[i].num,x=p[i].x,y=p[i].y;
			sw[p[i].num]=0;
			for(int j=i+1;j<sum;j++)
			{
				if(con[left][p[j].num])
				{
					sw[p[j].num]=0;
					cnt++;
					left=p[j].num;
				}
			}
			if(cnt>ansn) ansx=x,ansy=y,ansn=cnt;
		}
	}
	printf("%d %d %d\n",ansn,ansx,ansy);
	return 0;
}
