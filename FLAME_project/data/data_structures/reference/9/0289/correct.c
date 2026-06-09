#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct site
{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;//连起来的线段数
}line[110];
int cmp(const void *p, const void*q) {
	struct site *pp = (struct site*) p;
	struct site *qq = (struct site*) q;

	if((*pp).x1>(*qq).x1)return 1;
	else if((*pp).x1==(*qq).x1)return 0;
	else return -1;
}
int cmpNew(const void *p,const void *q){
	struct site *pp = (struct site*) p;
	struct site *qq = (struct site*) q;
	if((*pp).cnt>(*qq).cnt)return 1;
		else if((*pp).cnt==(*qq).cnt)return 0;
		else return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		}//读入线段坐标
	qsort(line, n, sizeof(line[0]), cmp);//根据x1排序
	for(int i=n-1;i>=0;i--)
	//从最右开始，逐个向前检索是否相接
	{
		for(int j=i-1;j>=0;j--)
		{
			if((line[j].x2==line[i].x1)&&(line[j].y2==line[i].y1))//接上了
					{
						line[j].cnt=line[i].cnt+1;
						break;
					}
				//	else//没接上，重新从1开始计数
				//	{
						//line[j].cnt=1;
				//	}
		}
		
	}
	qsort(line,n,sizeof(line[0]),cmpNew);
	printf("%d %d %d",line[n-1].cnt+1,line[n-1].x1,line[n-1].y1);
	return 0;
}

