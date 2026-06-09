#include<stdio.h>
struct Line
{
	int x1,y1,x2,y2;
};
struct Line line[101];
int n;
int search(int,int *);
int main()
{
	int i,max=0,id1,p,id2,a,b,x4,y4,y5,x5;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	for(i=0;i<n;i++)
	{
		if(search(i,&p)>max)
		{max=search(i,&p);
		id1=i;
		if(p==1)
		{x4=line[id1].x1;
		y4=line[id1].y1;
		}
		else
		{x4=line[id1].x2;
		y4=line[id1].y2;
		}
		
		}
		else if(search(i,&p)==max)
		{id2=i;
	if(p==1)
		{x5=line[id2].x1;
		y5=line[id2].y1;
		}
		else
		{x5=line[id2].x2;
		y5=line[id2].y2;
		}

		}
	}
	printf("%d",max);
	if(x4<x5)
	printf(" %d %d",x4,y4);
	else
	printf(" %d %d",x5,y5);
	return 0;
}
int search(int xx,int *p)
{
	int i,status,cnt1=1,cnt2=1,flag=0,now=xx;
	int x3,y3;
	x3=line[xx].x2;
	y3=line[xx].y2;
	while(1)
	{
		i=0;
		flag=0;
		while(i<n)
		{   if(i==now)
			i++;
			if(line[i].x1==x3&&line[i].y1==y3)
			{
				now=i;
				cnt1++;
				x3=line[i].x2;
				y3=line[i].y2;
				flag=1;
				break;
			}
			else if(line[i].x2==x3&&line[i].y2==y3)
			{
				now=i;
				cnt1++;
				x3=line[i].x1;
				y3=line[i].y1;
				flag=1;
				break;
			}
			else
			i++; 
		}
		if(flag==0)
		break;
	}
	x3=line[xx].x1;
	y3=line[xx].y1;
	now=xx;
	while(1)
	{
		i=0;
		flag=0;
		while(i<n)
		{   if(i==now)
			i++;
			if(line[i].x1==x3&&line[i].y1==y3)
			{
				now=i;
				cnt2++;
				x3=line[i].x2;
				y3=line[i].y2;
				flag=1;
				break;
			}
			else if(line[i].x2==x3&&line[i].y2==y3)
			{
				now=i;
				cnt2++;
				x3=line[i].x1;
				y3=line[i].y1;
				flag=1;
				break;
			}
			else
			i++; 
		}
		if(flag==0)
		break;
	}
	if(cnt1>cnt2)
	{*p=1;
	return cnt1;
	}
	else
	{
		*p=2;
		return cnt2;
	}
}



