#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct segment {
	int x1;
	int y1;
	int x2;
	int y2;
}seg,*pseg;
int cmp(const void *p1, const void *p2);
int main()
{
	int i,j,k,num;
	seg line[105];
	int cnt[105]={0},flag=0;
	scanf("%d",&num);
	for (i=0;i<num;i++)
		scanf("%d %d %d %d",&line[i].x1, &line[i].y1,&line[i].x2, &line[i].y2);
	qsort(line,num,sizeof(line[0]),cmp);
	for (i=0;i<num;i++)
	{
		if (line[i].x1 ==-1018 && line[i].x2==-1018 && line[i].y1 ==-1018 && line[i].y2==-1018)
			continue;
		for (j=i+1;j<num;j++)
		{
			
			if (line[j].x1 ==line[i].x2&& line[j].y1 ==line[i].y2)
			{
				line[i].x2=line[j].x2;
				line[i].y2=line[j].y2;
				line[j].x1=-1018;
				line[j].y1=-1018;
				line[j].x2=-1018;
				line[j].y2=-1018;
				cnt[i]++;
			}
		}
	}
	flag=0;
	for (i=1;i<num;i++)
	{
		if (cnt[i]>cnt[flag])
			flag=i;
	 } 
	printf("%d %d %d",cnt[flag]+1,line[flag].x1,line[flag].y1);
	return 0;
}
int cmp(const void *p1, const void *p2)
{
	pseg a = (pseg) p1;
	pseg b = (pseg) p2;
	return (a->x1)-(b->x1);
}

