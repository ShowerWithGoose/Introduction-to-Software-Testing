#include<stdio.h>
void swap(int x,int y);
struct node{
	int x1;
	int y1;
	int x2;
	int y2;
};
	struct node s[100];
int main()
{

	int startx,starty;
	int max=-1;

	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d %d %d %d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
	}
	for(int i=1;i<num;i++)
	{
		for(int j=1;j<=num-i;j++)
		{
			if(s[j].x1>s[j+1].x1)
			swap(j,j+1);
		}
	}
	for(int i=1;i<=num;i++)
	{
		int count=1;
		int tailx=s[i].x2;
		int taily=s[i].y2;
		for(int j=1;j<=num;j++)
		{
			if(tailx==s[j].x1&&taily==s[j].y1)
			{
				tailx=s[j].x2;
				taily=s[j].y2;

				count++;
				
			}
		}
		if(count>max)
		{
		max=count;
		startx=s[i].x1;
		starty=s[i].y1;
		}
	}
	printf("%d %d %d",max,startx,starty);

	return 0;
}
void swap(int x,int y)
{
	int temp=s[x].x1;
	s[x].x1=s[y].x1;
	s[y].x1=temp;
	temp=s[x].y1;
	s[x].y1=s[y].y1;
	s[y].y1=temp;
	temp=s[x].y2;
	s[x].y2=s[y].y2;
	s[y].y2=temp;
	temp=s[x].x2;
	s[x].x2=s[y].x2;
	s[y].x2=temp;	
}


