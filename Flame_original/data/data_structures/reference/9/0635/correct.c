#include <stdio.h>
#include <stdlib.h>
int Find(int (*Line)[5],int Total,int x1,int y1,int x2,int y2);
int cmp(const void *p1,const void *p2);
int main()
{
	int Line[105][5]={0};
	int Sum[105]={0};
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&Line[i][0],&Line[i][1],&Line[i][2],&Line[i][3]);
        Sum[i]++;
	 } 
	qsort(Line,n,sizeof(Line[0]),cmp);
	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			int ans=Find(Line,i,Line[i][0],Line[i][1],Line[i][2],Line[i][3]);
			if(ans!=-1)
			{Sum[i]=-ans;
			int j;
			for(j=ans;Sum[j]<=0;j=-Sum[j]);
			Sum[j]++;
			}	
		}
	}
	 int Max=0,pMax=0;
	 for(i=0;i<n;i++)
	 {
	 	if(Sum[i]>Max)
	 	{Max=Sum[i];
	 	pMax=i;
		}
	 }
	 printf("%d %d %d",Max,Line[pMax][0],Line[pMax][1]);
	 return 0;
}
int Find(int (*Line)[5],int Total,int x1,int y1,int x2,int y2)
{
	int flag=1,i=0;
	for(i=0;flag&&i<Total;i++)
	{
		if(Line[i][2]==x1&&Line[i][3]==y1)
		{
			flag=0;
		}
	}
	if(0==flag)
	return (i-1);
	else return -1;
}
int cmp(const void *p1,const void *p2)
{
	int x=((int **)p1)[0];
	int y=((int **)p2)[0];
	if(x<y) return -1;
	else if(x>y) return 1;
	else return 0;
}

