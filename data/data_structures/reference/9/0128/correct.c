#include<stdio.h>
#include<string.h>
int x[200],y[200],k;//x，y储存坐标，k是端点数 
int chonghe(int);//
int main()
{
	int flag[100]={0};// flag记录线段是否与其他线段相连 
	int n,i,j,nb,fla=0,num[200]={0};//n是线段数 ,num记录连续线段数 
	int a[101]={-1};
	int b[101]={-1};//左右端点 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x[2*i],&y[2*i],&x[2*i+1],&y[2*i+1]);
	}
	k=2*n;
	for(i=0;i<k;i+=2)
	{
		if(flag[i/2]!=0)
		continue;
		j=i;
		while(chonghe(j)!=-1)
		{
			if(chonghe(j)%2==1)
			{
				num[i]++;
				j=chonghe(j)-1;
				flag[j/2]++;
			}
			else if(chonghe(j)%2==0)
			{
				num[i]++;
				j=chonghe(j)+1;
				flag[(j-1)/2]++;
			}
		}
		a[i/2]=j;
		j=i+1;
		while(chonghe(j)!=-1)
		{
			if(chonghe(j)%2==1)
			{
				num[i]++;
				j=chonghe(j)-1;
				flag[j/2]++;
			}
			else if(chonghe(j)%2==0)
			{
				num[i]++;
				j=chonghe(j)+1;
				flag[(j-1)/2]++;
			}
		}
		b[i/2]=j;
	}
	for(i=0;i<k;i+=2)
	{
		if(fla<num[i])
		{
			fla=num[i];
			nb=i;
		}
	}
	if(x[a[nb/2]]>x[b[nb/2]])
	{
		printf("%d %d %d",fla+1,x[b[nb/2]],y[b[nb/2]]);
	}
	else if(x[a[nb/2]]<x[b[nb/2]])
	{
		printf("%d %d %d",fla+1,x[a[nb/2]],y[a[nb/2]]);
	}
	return 0;
}
int chonghe(int a)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(x[a]==x[i]&&y[a]==y[i]&&i!=a)
		{
			return i;
		}
		else if(i==a)
		{
			continue;
		}		
	}
	return -1;
}



