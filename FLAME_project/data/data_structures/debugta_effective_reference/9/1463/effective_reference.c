#include<stdio.h>
#include<stdlib.h>
struct line{
	int start[2];
	int end[2];
	int num;
}loc[100];
int n;
int cmp(const void*a,const void*b)
{
	struct line c=*(struct line*)a;
	struct line d=*(struct line*)b;
	if(c.num>d.num) return -1;
	else if(c.num<d.num) return 1;
	return 0;
}
int cmpfuc(int x);
int main() {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) 
    {
    	scanf("%d%d%d%d",&loc[i].start[0],&loc[i].start[1],&loc[i].end[0],&loc[i].end[1]);
	}
	for(i=0;i<n;i++)
	{
		loc[i].num=0;
		int j=i;
		while(cmpfuc(j)!=-1)
		{
			j=cmpfuc(j);
			loc[i].num++;
		}
	}
	//接下来将loc[n]按照loc[i].count进行qsort排序
	qsort(loc,n,sizeof(loc[0]),cmp); 
	printf("%d %d %d",loc[0].num+1,loc[0].start[0],loc[0].start[1]);
	return 0;
}
int cmpfuc(int x)//搜索有没有线的首端点与loc[x]的末端点重重合，如果有，返回这一点在loc中的标号
//没有则返回-1 
{
	int i;
	for(i=0;i<n;i++)
	{
		if(loc[i].start[0]==loc[x].end[0]&&loc[i].start[1]==loc[x].end[1])
		{
			return i;
		}
	}
	return -1;
}

