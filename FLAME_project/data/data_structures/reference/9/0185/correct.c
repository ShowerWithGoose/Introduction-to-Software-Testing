#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
};
int count[100];
int cmp(const void *a,const void *b)
{
	struct Line*a1=(struct Line*)a;
	struct Line*b1=(struct Line*)b;
	if(a1->x1-b1->x1!=0)
	{
		return ((a1->x1)-(b1->x1));
	}
	else if(a1->x2-b1->x2!=0)
	{
		return ((a1->x2)-(b1->x2));
	}
	else if(a1->y1-b1->y1!=0)
	{
		return ((a1->y1)-(b1->y1));
	}
	
	else
	{
		return ((a1->y2)-(b1->y2));
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	struct Line line[n]; 
//	struct Line* line=(struct Line*)malloc(n*sizeof(struct Line));
	int i,num;
	for(i=0,num=1;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
//		line[i].number=num;
//		num++;
		line[i].flag=-1;
	}
	qsort(line,n,sizeof(line[0]),cmp);
	
//	for(i=0;i<n;i++)
//		printf("%d %d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].flag);
	
	int j,index=0;
	struct Line *temp;
	int m;
	for(m=0;m<n;m++)
	{
		if(line[m].flag==-1)
		{
			temp=&line[m];
			temp->flag=index;
			count[index]++;
			for(j=m+1;j<n;j++)
			{
				if(line[j].flag!=-1)
					continue;
				if(line[j].x1==temp->x2&&line[j].y1==temp->y2)
				{
					line[j].flag=index;
					count[index]++;
					temp=&line[j];
				}
			}
		}
		
		index++;
	}
	
	int max=0,maxnum;
	for(i=0;i<index;i++)
	{
		if(max<=count[i])
		{
			max=count[i];
			maxnum=i;
		}
	}
	int x3,y3;
	for(i=0;i<n;i++)
	{
		if(line[i].flag==maxnum)
		{
			x3=line[i].x1;
			y3=line[i].y1;
			break;
		}
	}
	
	printf("%d %d %d",max,x3,y3);
	return 0;
 } 

