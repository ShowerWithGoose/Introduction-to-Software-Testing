#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void find(int k);

struct line{
	int first_x;
	int first_y;
	int last_x;
	int last_y;

}xl[100];
int num;
int count[100]={0};
int line_num=0;
int main()
{
	
	scanf("%d",&num);
	
	int i,j;
	for(i=0;i<num;i++)
	{
		scanf("%d %d %d %d",&xl[i].first_x,&xl[i].first_y,&xl[i].last_x,&xl[i].last_y);
		
	}
	

	for(i=0;i<num;i++)
	{
		
		find(i);
		count[i]=line_num+1;
		line_num=0;
	}
	
	int max_num=count[0],x=xl[0].first_x,y=xl[0].first_y;
	
	for(i=1;i<num;i++)
	{
		if(count[i]>max_num)
		{
			max_num=count[i];
			x=xl[i].first_x;
			y=xl[i].first_y;
		}
	}
	printf("%d %d %d",max_num,x,y);
	
	return 0;
}

void find(int k)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(i==k)
			continue;
		else
		{
			if(xl[k].last_x==xl[i].first_x&&xl[k].last_y==xl[i].first_y)
			{
				
				line_num++;
				find(i);
			}
		}
	}
}





