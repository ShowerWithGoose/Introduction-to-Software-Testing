#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807£¨>10^18£©   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

struct Line
{
	int x1;
	int x2;
	int y1;
	int y2;
};
int cmp(const void *e1, const void *e2)
{
     return ((struct Line*)e1)->x1-((struct Line*)e2)->x1;//ÉýÐò ·´Ö®½µÐò 
}

int main()
{
	int num,k,flag,flag1,xt1,yt1;
	scanf("%d",&num);
	struct Line line[200];
	for(int i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	qsort(line, num, sizeof(line[0]), cmp);
	flag=1;
	flag1=0;
	for(int i=0;i<num;i++)
	{
		k=i;
		for(int j=i;j<num;j++)
		{
			if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2)
			{
			    flag+=1;
				i=j;
			}
		}
		if(flag>flag1)
		{
			flag1=flag;
			xt1=line[k].x1;
			yt1=line[k].y1;
		}
		i=k;
		flag=1;
	}
	printf("%d %d %d",flag1,xt1,yt1);
} 

