#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
struct Line line[2000];

int cmp1(const void *a,const void *b)
{
	struct Line *aa=(struct Line *)a;
	struct Line *bb=(struct Line *)b;
	if(aa->x1!=bb->x1) return aa->x1-bb->x1;
	else return aa->y1-bb->y2;
}

int cmp2(const void *a,const void *b)
{
	struct Line *aa=(struct Line *)a;
	struct Line *bb=(struct Line *)b;
	return aa->num-bb->num;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		line[i].num=1; 
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	qsort(line,i,sizeof(line[0]),cmp1);	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			continue;
			else
			{
				if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2)
				{
					line[i].x2=line[j].x2;
					line[i].y2=line[j].y2;
					line[i].num+=line[j].num;
					line[j].num=0;
					line[j].x1=0;
					line[j].x2=0;
					line[j].y1=0;
				}
			}
		}
	}
	qsort(line,n,sizeof(line[0]),cmp2);
	printf("%d %d %d\n",line[n-1].num,line[n-1].x1,line[n-1].y1);
	return 0;
}

