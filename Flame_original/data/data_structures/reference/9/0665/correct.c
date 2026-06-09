#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct xianduan
{
	int x1;
	int y1;
	int x2;
	int y2;	
};
void sort (struct xianduan info[],int n);
int main()
{
	int n,i,j,k=0,l,count=0,max=0;
	int x,y;
	scanf("%d",&n);
	struct xianduan info[505];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&info[i].x1,&info[i].y1,&info[i].x2,&info[i].y2);
	}
	sort(info,n);
	/*printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",info[i].x1,info[i].y1,info[i].x2,info[i].y2);
	}
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		k=i;
		count=0;
		for(j=i+1;j<n;j++)
		{
			if((info[k].x2==info[j].x1)&&(info[k].y2==info[j].y1))			
			{
				count++;
				k=j;				
			}
		}
		if(count>max)
		{
			l=i;
			max=count;	
		}
	}
	printf("%d %d %d",max+1,info[l].x1,info[l].y1);
	return 0;
}
void sort(struct xianduan info[],int n)
{
	int i,j;
	struct xianduan temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(info[i].x1>info[j].x1)
			{
				temp.x1=info[i].x1;
				temp.y1=info[i].y1;
				temp.x2=info[i].x2;
				temp.y2=info[i].y2;
				info[i].x1=info[j].x1;
				info[i].y1=info[j].y1;
				info[i].x2=info[j].x2;
				info[i].y2=info[j].y2;
				info[j].x1=temp.x1;
				info[j].y1=temp.y1;
				info[j].x2=temp.x2;
				info[j].y2=temp.y2;
			}
		}
	}
}

