#include<stdio.h>
struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
}lines[105];
struct hold
{
	int flag;
	int begin;
	int end;
}holds[105];
int count,max=-1;
int k1,k2;
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	int m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&lines[i].x1);
		scanf("%d",&lines[i].y1);
		scanf("%d",&lines[i].x2);
		scanf("%d",&lines[i].y2);
	}
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		{
			if((lines[j].x2==lines[k].x1)&&(lines[j].y2==lines[k].y1))
			{
				holds[j].flag=1;
				holds[j].begin=j;
				holds[j].end=k;
				break;
			}
		}		
	}
	for(m=1;m<=n;m++)
	{
		k1=m;
		while(holds[m].flag==1)
		{
			m=holds[m].end;
			count++;
		}
		if(count>max)
		{
			max=count;
			k2=k1;
		}
		m=k1;
		count=0;				
	}
	printf("%d %d %d",max+1,lines[k2].x1,lines[k2].y1);
	return 0;	
	
}

