#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
};

struct b
{
	int cnt;
	int start1;
	int start2;
};

int cmp(const void*p1,const void*p2)
{
	struct line *x=(struct line*)p1;
	struct line *y=(struct line*)p2;
	if(x->x1 !=y->x1 ) return x->x1 - y->x1;
	else return x->y1 - y->y1;
}

int main(int argc, const char * argv[])
{
	struct line lines[110];
	struct b B[110];
	int n;
	int flagfound=0,temp,flag1=0,flagfound1=0;
	int cnt[110],num;
	int i,j,k;
	int max=0;
	memset(cnt,0,sizeof(cnt));
	memset(B,0,sizeof(B));
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1,&lines[i].x2,&lines[i].y2);
		num++;
	}
	qsort(lines,num,sizeof(lines[0]),cmp);
	for(i=0;i<num;i++)
	{
		flag1=0;
		flagfound=0;
		flagfound1=0;
		for(j=0;j<num;j++)//第一个点 
		{
			if(lines[j].x1 != 0&&lines[j].y1 != 0&&lines[j].x2 != 0&&lines[j].y2 != 0)
			{
				for(k=0;k<num;k++)//第二个点 
				{
					if((lines[j].x2==lines[k].x1&& lines[j].y2==lines[k].y1) )
					{
						if(flag1==0)
						{
							B[i].start1 =lines[j].x1 ;
							B[i].start2 =lines[j].y1 ;
						}
						flag1=1;
						flagfound=1;
						flagfound1=1;
						temp=k;
						B[i].cnt++;
						lines[j].x1 =0;
						lines[j].y1 =0;
						lines[j].x2 =0;
						lines[j].y2 =0;
						break;
					}
					else
					{
						flagfound1=0;
						continue;
					}
				}
				if(flagfound1!=0)
					j=temp-1;
			}
			if(flagfound1==0&&flagfound==1)
			{
				lines[j].x1 =0;
				lines[j].y1 =0;
				lines[j].x2 =0;
				lines[j].y2 =0;
				break;
			}
		}
		
		
	}
	for(i=0;i<num;i++)
	{
		if(B[i].cnt >max)
		{
			max=B[i].cnt;
			temp=i;
		}
	}
	printf("%d %d %d",B[temp].cnt+1 ,B[temp].start1 ,B[temp].start2 );
	
	
	return 0;
}

