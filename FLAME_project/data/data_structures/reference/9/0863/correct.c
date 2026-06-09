#include<stdio.h>
#include<stdlib.h>
struct node{
	int x;
	int y;
};
struct l{
	int index;
	int len;
};
int main()
{
	struct l line[120];
//	int length=0;
	//int index=0;
	int z;int k;
	int max=1;
	int first;
	struct node one[120];
	struct node two[120];
	int n;
	int i;int j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&one[i].x ,&one[i].y ,&two[i].x ,&two[i].y );
		line[i].len=1;//[i]代表首元素为i index代表上一个元素，save存储所有元素 
		line[i].index =i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(two[i].x==one[j].x &&two[i].y==one[j].y )
			{
				for(z=0;z<n;z++)
				{
					if(line[z].index ==i)
					{
						line[z].len=line[z].len+line[j].len ;
						line[z].index =line[j].index ;
						if(line[z].len >max&&z!=n) 
						{
							max=line[z].len ;
							first=z;
						 } 
						
					}
				}
			}
			else if(two[j].x==one[i].x &&two[j].y==one[i].y )
			{
				for(k=0;k<n;k++)
				{
					if(line[k].index ==j)
					{
						line[k].len=line[k].len +line[i].len ;
						line[k].index=line[i].index ;
						if(line[k].len >max&&k!=n)
						{
							max=line[k].len ;
							first=k;
						 } 
						
					}
					
				}
			}
		}
	}

	printf("%d ",max);
	printf("%d %d",one[first].x ,one[first].y );
	return 0;
}

