#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[105][105];
int visited[105]={0}; 
int rear=-1,front=-1;
int queue[100]={0};
void mapdepth(int n,int total)
{
	int i;
	if(visited[n]==1)
	{
		printf("%d ",n);
		visited[n]=0;
	}
	for(i=0;i<total;i++)
	{
		if(visited[i]==1&&table[n][i]==1)
		mapdepth(i,total);
	}
}
void mapbround(int pos,int total)
{
	int i,j;
	if(visited[pos]==1)
	{
		printf("%d ",pos);
		visited[pos]=0;
		queue[++rear]=pos;
	}
	while(front<rear)
	{
		j=queue[++front];
		if(visited[j]==1)
		{
			printf("%d ",j);
			visited[j]=0;
		}	
		for(i=0;i<total;i++)
		{				
			if(visited[i]==1&&table[j][i]==1)
			queue[++rear]=i;
		}			
	}
}
int main()
{
int n,num,out;
int pot1,pot2;
int i,j,k;
scanf("%d%d",&n,&num);
for(i=0;i<num;i++)
{
	scanf("%d%d",&pot1,&pot2);
	table[pot1][pot2]=table[pot2][pot1]=1;
}
scanf("%d",&out);
for(i=0;i<n;i++)
visited[i]=1;
mapdepth(0,n);
printf("\n");
for(i=0;i<n;i++)
visited[i]=1;
mapbround(0,n);
printf("\n");
for(i=0;i<n;i++)
visited[i]=1;
for(i=0;i<n;i++)	//É¾³ý 
{
	table[out][i]=table[i][out]=0;
}
mapdepth(0,n);
printf("\n");
for(i=0;i<n;i++)
visited[i]=1;
rear=-1,front=-1;
for(i=0;i<105;i++)
queue[i]=1;
mapbround(0,n);
return 0;
}


