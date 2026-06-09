#include<stdio.h>
#include<string.h>
int f(int,int,int);
int Num,t,TempX,TempY;
int Point[101][5];
int main()
{
	int i,Max=0,Temp=0,X,Y;
	scanf("%d",&Num);
	//printf("%d",Num);
	memset(Point,0,sizeof(Point));
	for(i=1;i<=Num;i=i+1)
	{
		scanf("%d %d %d %d",&Point[i][1],&Point[i][2],&Point[i][3],&Point[i][4]);
	}
	//printf("%d\n",Point[1][1]);
	for(i=1;i<=Num;i=i+1)
	{
		Temp=0;
		t=0;
		Temp=f(Point[i][3],Point[i][4],i);
		t=0;
		Temp=Temp+f(Point[i][1],Point[i][2],i);
		Temp=Temp+1;
		if(Temp>Max)
		{
			Max=Temp;
			X=TempX;
			Y=TempY;
		}
	}
	printf("%d %d %d",Max,X,Y);
	return 0;
}

int f(int x,int y,int i)
{
	int j;
	for(j=1;j<=Num;j=j+1)
	{
		if(j==i) continue;
		if(Point[j][1]==x&&Point[j][2]==y)
		{
			t=t+1;
			return f(Point[j][3],Point[j][4],j);
		}
		else if(Point[j][3]==x&&Point[j][4]==y)
		{
			t=t+1;
			return f(Point[j][1],Point[j][2],j);
		}
	}
	TempX=Point[i][1];
	TempY=Point[i][2];
	return t;
}

