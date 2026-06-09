#include <stdio.h>
#include <stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int time[105];
struct line len[105];
int cmp(const void *a,const void *b)
{
	struct line pa=*((struct line*)a);
	struct line pb=*((struct line*)b);
	return pa.x1-pb.x1;
}
int main()
{
	int n,i,j;
	int max,p=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&len[i].x1,&len[i].y1,&len[i].x2,&len[i].y2);
	qsort(len,n,sizeof(len[0]),cmp);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(len[j].x1==len[i].x2&&len[j].y1==len[i].y2)
			{
				len[i].x2=len[j].x2;
				len[i].y2=len[j].y2;
				time[i]++;
			}
		}
	}
	max=time[0];
	for(i=1;i<n;i++)
	{
		if(max<time[i])
		{
			max=time[i];p=i;
		}
	}
	printf("%d %d %d\n",max+1,len[p].x1,len[p].y1);
	return 0;
 } 

