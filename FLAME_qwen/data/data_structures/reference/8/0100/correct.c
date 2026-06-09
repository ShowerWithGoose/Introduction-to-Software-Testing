#include<stdio.h>
#include<stdlib.h>
int map[101][101]={0};
int visit[101]={0},num;
int des[101]={0},k=0;

void dps(int t)
{
	int i; 
	for(i=0;i<num;i++)
	{
		if(map[t][i]&&visit[i]==-1)
		{
			des[k++]=i;
			visit[i]=t;
			dps(i);
		}
	 } 
	 return ;
}
void addq(int max)
{
	int i,t=0,j;
	for(i=0;i<num;i++)
	{
		if(map[t][i]&&visit[i]==-1)
		{
			des[k++]=i;
			visit[i]=t;
		}
		if(max==k)
		break;
	}
	while(max!=k)
	{
		t++;
		for(i=0;i<num;i++)
	{
		j=des[t];
		if(map[j][i]&&visit[i]==-1)
		{
			des[k++]=i;
			visit[i]=j;
		}
		if(max==k)
		break;
	}
	}
	return ;
}
int main()
{
	int tmp1,tmp2,n,i;
	scanf("%d%d",&num,&n);
	for(i=0;i<num;i++)
	{
		visit[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		map[tmp1][tmp2]=1;
		map[tmp2][tmp1]=1;
	}
	des[k++]=0;
	visit[0]=-2;
	dps(0);
	for(i=0;i<num;i++)
	printf("%d ",des[i]);
	printf("\n");
	k=0;
	for(i=0;i<num;i++)
	visit[i]=-1;
	des[k++]=0;
	visit[0]=-2;
	addq(num);
	for(i=0;i<num;i++)
	printf("%d ",des[i]);
	printf("\n");
	scanf("%d",&n);
	for(i=0;i<num;i++)
	visit[i]=-1;
	visit[n]=-2;
	k=0;
	des[k++]=0;
	visit[0]=-2;
	dps(0);
	for(i=0;i<num-1;i++)
	printf("%d ",des[i]);
	printf("\n");
	k=0;
	for(i=0;i<num;i++)
	visit[i]=-1;
	visit[n]=-2;
	des[k++]=0;
	visit[0]=-2;
	addq(num-1);
	for(i=0;i<num-1;i++)
	printf("%d ",des[i]);
	return 0;
 } 

