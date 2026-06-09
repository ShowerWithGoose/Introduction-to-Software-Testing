#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int findline(int);
int lines;
typedef struct{
	int x1,y1,x2,y2;
}line;
	line xd[100+3];
	
int main()
{
	scanf("%d",&lines);
	int i,count[100+3]={0};
	for(i=0;i<lines;i++)
	{
		scanf("%d %d %d %d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
	}
	
	for(i=0;i<lines;i++)
	{
			count[i]=findline(i);
	}
	
	int max=count[0],record=0;
	for(i=0;i<lines;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			record=i;
		}
	}
	
	/*printf("%d %d %d\n",lines,record,max);
	for(i=0;i<lines;i++)
	{
		printf("%d\n",count[i]);
	}*/
	
	printf("%d %d %d\n",max,xd[record].x1,xd[record].y1);
	return 0;
}

int findline(int start)
{
	int j;
	for(j=0;j<lines;j++)
	{
		if(xd[j].x1==xd[start].x2&&xd[j].y1==xd[start].y2)
		{
			return findline(j)+1;
		}
		else
			continue;
	}
	if(j==lines)
		return 1;
}

