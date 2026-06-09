#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define  pr printf
#define ll long long

int NOL;
int x[105],y[105],m[105],n[105];
int max[2],temp[2],hx[2];
int op,lenth,len[105];
void NEXT(int v);
int judge(int p,int q);
int main()
{
	int i,j,k;
	scanf("%d",&NOL);
	//pr("%d\n",NOL);
	for(i=1;i<=NOL;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&m[i],&n[i]);
	}
	#if 0
	for(i=1;i<=NOL;i++)
	{
		pr("%d %d %d %d\n",x[i],y[i],m[i],n[i]);
	}
	#endif
	max[0]=0;										//连续线段条数 
	max[1]=1;										//连续线段的起点所在线段编码 
	for(i=1;i<=NOL;i++)
	{
		hx[0]=i;
		lenth=1;
		NEXT(i);
		//hx[0]=0;
	}
	printf("%d %d %d",max[0],x[max[1]],y[max[1]]);
	return 0;
	
}
void NEXT(int v)
{
	int i,flag=0;
	for(i=1;i<=NOL;i++)
	{
		op=judge(i,v);
		if(op>=1&&op<=NOL)
		{
			flag=1;
			NEXT(op);
		}
	}
	if(flag==0)
	{
		temp[1]=hx[0];
		temp[0]=lenth;
		len[hx[0]]=lenth;
		if(max[0]<temp[0]){
			max[0]=temp[0];
			max[1]=temp[1];
		}
		
	}
	#if 0
	
	#endif
}
int judge(int p,int q)
{
	if(x[p]==m[q]&&y[p]==n[q])
	{
		lenth++;
		return p;
	}
	else return 0;
}

