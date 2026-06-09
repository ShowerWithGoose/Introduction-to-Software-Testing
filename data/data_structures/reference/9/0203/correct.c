#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct each_short_line{
	int x1,y1,x2,y2;
	int next_line;
	int prev_line;
}lines;
int cmp(const void *a,const void *b){
	lines c=*(lines*)a;
	lines d=*(lines*)b;
	if(c.x1-d.x1!=0) return c.x1-d.x1;
	else return c.y1-d.y1;
}
int main()
{
	lines line[105];
	int index[105]={0};
	int num,i,j,MAX,MAX_line;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].next_line=0;
		line[i].prev_line=0;
	}
	qsort(line,num,sizeof(line[0]),cmp);
	
	//for(int x=0;x<num;x++) printf("%d %d %d %d\n",line[x].x1,line[x].y1,line[x].x2,line[x].y2);
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<=num;j++)
		{
			if(line[j].prev_line==0&&line[j].x1==line[i].x2&&line[j].y1==line[i].y2)
			{
			line[j].prev_line=i+1;
			line[i].next_line=j;
			}
		}
	}
	//	for(int x=0;x<num;x++) printf("%d\n",line[x].next_line);
	for(i=0;i<num;i++)
	{
		for(j=i;j<num;)
		{
			if(line[j].next_line!=0)
		{
			index[i]++;
			j=line[j].next_line;
			continue;
		}
		else 
		break;	
		}
	}
	MAX=index[0];
	for(j=1;j<num;j++)
	{
		if(index[j]>MAX)
		{
		MAX=index[j];
		MAX_line=j;
		}
	}
	
	printf("%d %d %d",MAX+1,line[MAX_line].x1,line[MAX_line].y1);
	return 0;
}

