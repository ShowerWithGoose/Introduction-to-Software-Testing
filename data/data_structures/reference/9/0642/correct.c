#include<stdio.h>
#include<stdlib.h>
int lines[105][4];    //0-》开始x    1-》开始y   2-》结束x    3-》结束y 
typedef struct {
	int length;
	int xx;     //起始  x   y  
	int yy;
}res;
res going[105];
void qsort( void *base, size_t num, size_t wid, int (*rise_double)(const void *e1, const void *e2) );
int cmp(const void *a, const void *b)
{
	int *c=(int*)a;
	int *d=(int*)b;
	if(*c!=*d) return *c-*d;
	else return 0;
}
int count(int );
int main()
{
	int i=0,num;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&lines[i][0],&lines[i][1],&lines[i][2],&lines[i][3]);
	}
	qsort(lines,num, sizeof(lines[0]), cmp);
	int flag=count(num);
	printf("%d %d %d",going[flag].length+1,going[flag].xx,going[flag].yy);
	return 0;
}
int count(int num)
{
	int i,j,k,max=0,sign;
	for(i=0;i<num;i++)
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(lines[k][2]==lines[j][0]&&lines[k][3]==lines[j][1])
			{
				going[i].length++;
				going[i].xx=lines[i][0];
				going[i].yy=lines[i][1];
				k=j;
			}
		}
	}
	for(i=0;i<num;i++)
	{
		if(going[i].length>max)
		{
			max=going[i].length;
			sign=i;
		}
	}
	return sign;
}





