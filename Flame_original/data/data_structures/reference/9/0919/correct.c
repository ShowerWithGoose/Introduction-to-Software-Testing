#include<stdio.h>
#include<stdlib.h> 
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	struct line* next;
};

int count[107];

int main()
{
	int n,i,j;
	struct line node[107];
	struct line* ptr;
	ptr =(struct line*)malloc(sizeof(struct line)); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
		node[i].next = NULL;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(node[i].x2==node[j].x1 && node[i].y2 == node[j].y1)
			{
				node[i].next = &(node[j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ptr = &(node[i]);
		while(ptr->next != NULL)
		{
			count[i]++;
			ptr = ptr->next;
		}
		count[i]++;
	}
	int ans,max=0;
	for(i=0;i<n;i++)
	{
		if(count[i] > max)
		{
			max = count[i];
			ans = i;
		}
	}
	printf("%d %d %d",count[ans],node[ans].x1,node[ans].y1);
	return 0;
}
























