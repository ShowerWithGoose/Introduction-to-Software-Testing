#include<stdio.h>
#include<stdlib.h>
struct List{
	int x1,y1,x2,y2;
}Line[105];
int cmpfunc(const void*x,const void*y)
{
	struct List xx=*(struct List*)x;//xx的写法确实有趣 
	struct List yy=*(struct List*)y;
	return xx.x1 -yy.x1 ;
}
int main()
{
	int n,i=0,j=0,k=0,length=0,m=0,xy,yx;//length记录有效长度 ，m暂时记录 ,xy记录上一个点,yx记录起点 
	scanf("%d",&n);
	while(~scanf("%d%d%d%d",&Line[i].x1 ,&Line[i].y1 ,&Line[i].x2 ,&Line[i].y2 ))
	{
		i++;
	}
	qsort(Line,i,sizeof(Line[0]),cmpfunc);
	for(j=0;j<i;j++)
	{
		xy=j;
		for(m=1,k=j+1;k<i;k++)
		{
			if(Line[xy].x2 ==Line[k].x1 &&Line[xy].y2 ==Line[k].y1)
			{
				m++;
				xy=k;
			}
		}
		if(m>length)
		{
			length=m;
			yx=j; 
		} 
	} 
	printf("%d %d% d%",length,Line[yx].x1 ,Line[yx].y1 );
}

