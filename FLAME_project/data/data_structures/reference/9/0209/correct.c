#include<stdio.h>
#include<stdlib.h>
struct Point_{
	int x;
	int y;
};
struct Segment_{
	struct Point_ v1,v2,start_point;
	int Length;
	int chosen;
}Segment[105];
int cmp(const void *p1,const void *p2)
{
	return ((struct Segment_*)p1)->v1.x-((struct Segment_*)p2)->v1.x;
}
int main()
{
	int i,j,k;
	int num;
	int Length=0;
	int Max;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&Segment[i].v1.x,&Segment[i].v1.y,&Segment[i].v2.x,&Segment[i].v2.y);
		Segment[i].Length=1;
		Segment[i].start_point.x=Segment[i].v1.x;
		Segment[i].start_point.y=Segment[i].v1.y;
		
	}
	
	qsort(Segment,num,sizeof(Segment[0]),cmp);
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(Segment[i].v2.x==Segment[j].v1.x&&Segment[i].v2.y==Segment[j].v1.y&&j<num)
			{
				Segment[j].Length=Segment[i].Length+1;
				
				Segment[j].start_point.x=Segment[i].start_point.x;
				Segment[j].start_point.y=Segment[i].start_point.y;
				break;
			}
			
		}
		if(Segment[j].Length>Length)
		Max=j;
	}
	printf("%d %d %d",Segment[Max].Length,Segment[Max].start_point.x,Segment[Max].start_point.y);
	return 1;
}

