#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int start_x,start_y;
	int end_x,end_y;
}Line;
Line a[200],ans;int MAX=-1;
int sym[1000];
int start_x,start_y;
int end_x,end_y,n,i,j,stop;
void DFS(int x1,int y1,int x2,int y2,int k,int k1)
{
	int stop=1;
	if(k>MAX)
	{
		ans.start_x=x1;ans.start_y=y1;
		ans.end_x=x2;ans.end_y=y2;
		MAX=k;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(i==k1) continue;
		if((x2==a[i].start_x)&&(y2==a[i].start_y)&&(sym[i]==0)) 
		{
			sym[i]=1;DFS(x1,y1,a[i].end_x,a[i].end_y,k+1,k1);stop=0;
		}
		if((x1==a[i].end_x)&&(y1==a[i].end_y)&&(sym[i]==0)) 
		{
			sym[i]=1;DFS(a[i].start_x,a[i].start_y,x2,y2,k+1,k1);stop=0;
		}
		
	}
	if(stop==1) return;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].start_x,&a[i].start_y,&a[i].end_x,&a[i].end_y);
	}
	for(i=1;i<=n;i++)
	{
		if(!sym[i])
		DFS(a[i].start_x,a[i].start_y,a[i].end_x,a[i].end_y,1,i);
//		for(j=1;j<=n;j++)  sym[j]=0;
	}
	printf("%d %d %d",MAX,ans.start_x,ans.start_y);
}
	
	

