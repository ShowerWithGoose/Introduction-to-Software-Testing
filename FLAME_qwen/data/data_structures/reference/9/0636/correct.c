#include <stdio.h>//不可能有三个线段共点;支持各方向线段
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100
struct lines{
	int x1,y1,x2,y2,linenum;
}line[MAXLINE];
int linecmp_hori(const void *aa,const void *bb)//横排从小到大排
{
	struct lines *a=(struct lines *)aa;
	struct lines *b=(struct lines *)bb;
	return (((*a).x1<(*b).x1)?-1:1);
}
int main()
{
	int n,i,j,pre,count,maxnum=0,linenum=0,start,startx,starty,maystart1,maystart1side,maystart2,maystart2side,flag;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].linenum=0;	
	}
	qsort(line,n,sizeof(line[0]),linecmp_hori);//横坐标小在前
	for (i=0;i<n;i++)
	{
		count=1;
		flag=1;
		pre=i;
		if (!line[i].linenum)
		{
			linenum++;
			line[i].linenum=linenum;
			for (j=0;j<n;j++)
			{
				if (!line[j].linenum)
				{
					if (((line[pre].x1==line[j].x1)&&(line[pre].y1==line[j].y1))||((line[pre].x2==line[j].x1)&&(line[pre].y2==line[j].y1)))
					{
						line[j].linenum=linenum;
						count++;
						maystart1side=2;
						pre=j;
						j=0;//每次从头开始找可能有一端相同的线段
					}
					else if (((line[pre].x1==line[j].x2)&&(line[pre].y1==line[j].y2))||((line[pre].x2==line[j].x2)&&(line[pre].y2==line[j].y2)))
					{
						line[j].linenum=linenum;
						count++;
						maystart1side=1;
						pre=j;
						j=0;//每次从头开始找可能有一端相同的线段
					}
				}
			}
			maystart1=pre;
			pre=i;
			for (j=0;j<n;j++)//一开始可能分叉，从第i个线段的另一个方向两遍
			{
				if (!line[j].linenum)
				{
					if (((line[pre].x1==line[j].x1)&&(line[pre].y1==line[j].y1))||((line[pre].x2==line[j].x1)&&(line[pre].y2==line[j].y1)))
					{
						line[j].linenum=linenum;
						count++;
						maystart2side=2;
						pre=j;
						j=0;//每次从头开始找可能有一端相同的线段
					}
					else if (((line[pre].x1==line[j].x2)&&(line[pre].y1==line[j].y2))||((line[pre].x2==line[j].x2)&&(line[pre].y2==line[j].y2)))
					{
						line[j].linenum=linenum;
						count++;
						maystart2side=1;
						pre=j;
						j=0;//每次从头开始找可能有一端相同的线段
					}
				}
			}
			maystart2=pre;
		}
		if (count>maxnum)
		{
			maxnum=count;
			if (flag)
			{
				if (maystart1side==1)
				{
					start=(line[i].x1<=line[maystart1].x1?i:maystart1);
					startx=line[start].x1;
					starty=line[start].y1;
				}
				else if (maystart1side==2)
				{
					start=(line[i].x1<=line[maystart1].x2?i:maystart1);
					if (start==i)
					{
						startx=line[start].x1;
						starty=line[start].y1;
					}
					else
					{
						startx=line[start].x2;
						starty=line[start].y2;
					}
				}
				else
				{
					startx=line[i].x1;
					starty=line[i].y1;
				}
			}
			else
			{
				if (maystart1side==1)
				{
					if (maystart2side==1)
					{
						start=(line[maystart1].x1<=line[maystart2].x1?maystart1:maystart2);
						startx=line[start].x1;
						starty=line[start].y1;
					}
					else if (maystart2side==2)
					{
						start=(line[maystart1].x1<=line[maystart2].x2?maystart1:maystart2);
						if (start==maystart1)
						{
							startx=line[start].x1;
							starty=line[start].y1;
						}
						else
						{
							startx=line[start].x2;
							starty=line[start].y2;
						}
					}
				}
				else if (maystart1side==2)
				{
					if (maystart2side==2)
					{
						start=(line[maystart1].x2<=line[maystart2].x2?maystart1:maystart2);
						startx=line[start].x2;
						starty=line[start].y2;
					}
					else if (maystart2side==1)
					{
						start=(line[maystart1].x2<=line[maystart2].x1?maystart1:maystart2);
						if (start==maystart1)
						{
							startx=line[start].x2;
							starty=line[start].y2;
						}
						else
						{
							startx=line[start].x1;
							starty=line[start].y1;
						}
					}
				}
			}
		}
	}
	printf("%d %d %d",maxnum,startx,starty);
	return 0;
}



