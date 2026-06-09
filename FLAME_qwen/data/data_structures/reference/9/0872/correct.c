#include<stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;
}l[105];
struct maxline{
	int x;
	int y;
	int max;
}ml;
int stx,sty,fix,fiy;

int aaa;

int n;
void input()
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	ml.max=-1;
	for(j=0;j<n;j++)
	{
		l[j].cnt=1;
	}
}
void initline(int j)
{
	int i=0;
	for(i=j;i<n-1;i++)
	{
		l[i]=l[i+1];
	}
}
void judgenode(int i)
{
	int j=0,flag=0;
	for(j=0;j<n;j++)
	{
		if(l[j].x1==l[i].x2&&l[j].y1==l[i].y2)
		{
			
			if(l[j].cnt!=1)
			{
				l[i].cnt+=l[j].cnt;
			}
			else
			l[i].cnt++;
			
			l[i].x2=l[j].x2;
			l[i].y2=l[j].y2;
			initline(j);
			if(i>=j)
			{
				aaa++;
				i--;
			}
			
			
			j--;
			
			n--;
			
		}
	}
}
void findmax()
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		if(ml.max<l[i].cnt)
		{
			ml.max=l[i].cnt;
			ml.x=l[i].x1;
			ml.y=l[i].y1;
		}
	}
	printf("%d %d %d",ml.max,ml.x,ml.y);
}
int main()
{
	
	int i=0,j=0;
	scanf("%d",&n);
	input();
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			judgenode(i);
			i-=aaa;
			aaa=0;
		}
	}
	
	findmax();
}

