#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
struct Line{
	int x1,x2,y1,y2;
};
typedef struct Line Line;
Line line[101];
int n;
int max_line=0;
int x,y;
int Max(int line,int b){return line>b?line:b;}
int Min(int line,int b){return line<b?line:b;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(line[i].x1>line[j].x1)
			{
				Line tmp;
				tmp.x1=line[i].x1;
				tmp.x2=line[i].x2;
				tmp.y1=line[i].y1;
				tmp.y2=line[i].y2;
				line[i].x1=line[j].x1;
				line[i].x2=line[j].x2;
				line[i].y1=line[j].y1;
				line[i].y2=line[j].y2;
				line[j].x1=tmp.x1;
				line[j].x2=tmp.x2;
				line[j].y1=tmp.y1;
				line[j].y2=tmp.y2;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k=i,num=0;
		for(int j=i+1;j<=n;j++)
		{
			if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1)
			{
				k=j;
				num++;
			}
		}
		if(num>max_line)
		{
			max_line=num;
			x=line[i].x1;
			y=line[i].y1;
		}
	}
	max_line++;
	printf("%d %d %d",max_line,x,y);
	return 0;
}



