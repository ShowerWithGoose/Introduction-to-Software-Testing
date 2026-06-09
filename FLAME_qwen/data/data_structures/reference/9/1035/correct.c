#include<stdio.h>
#include<stdlib.h>
struct lines{
	int x1;
	int x2;
	int y1;
	int y2;
};
struct lines line[105];
int mark[105];
int n;
void search(int begin,int index);  //index为第一条线段，begin为现在走到了哪条线段 
int cmp(const void *p1,const void *p2)
{
	struct lines *a=(struct lines*)p1;
	struct lines *b=(struct lines*)p2;
	if(a->x1<=b->x1) return -1;
	else return 1;
}
int main()
{
	int i,j;
//	for(i=0;i<=30;i++) printf("%d",mark[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++) mark[i]=1;  //初始化标记数组，每组线段的个数是1 
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(struct lines),cmp);
//	for(i=0;i<n;i++) printf("%d ",line[i].x1);
	for(i=0;i<n-1;i++)
		search(i,i);
	int max=0,k;
	for(i=0;i<n;i++)
	{
		if(max<mark[i])
		{
			max=mark[i];
			k=i;
		}
	}
	printf("%d %d %d\n",max,line[k].x1,line[k].y1);
	return 0;
 } 
 void search(int begin,int index)
 {
 	int j;
 	if(begin==n-1||mark[index]==0) return ; //如果遍历完所有线段或者最开始的线段就已经被连过了 
 /*	if(mark[begin+1]==0) //说明这个线段已经被连过了 
 	{
 		search(begin+1,index);
 		return ;
	}*/
 	for(j=begin+1;j<n;j++)
 	{
 		if(line[begin].x2==line[j].x1&&line[begin].y2==line[j].y1)
 		{
 			mark[index]++;
 			mark[j]=0;
 			search(j,index);
 			break;
		 }
	}
 }

