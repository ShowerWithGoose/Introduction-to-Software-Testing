#include <stdio.h>
struct Line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;

};
struct Line line[1000];

int cmp(const void* p1,const void* p2)
{
	struct Line* pa=(struct Line*) p1;
	struct Line* pb=(struct Line*) p2;
	if(pa->x1<pb->x1) return 1;
	else if(pa->x1>pb->x1) return -1;
	
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{   line[i].num=1;
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
//		printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
		}
	
	qsort(line,n,sizeof(line[0]),cmp);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2) line[j].num+=line[i].num;
		}
	}
	int cnt=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(cnt<line[i].num) cnt=line[i].num,flag=i;
		
	}
	printf("%d %d %d",cnt,line[flag].x1,line[flag].y1);
	return 0;
  

	
}

