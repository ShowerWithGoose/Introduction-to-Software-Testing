#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int tu[109][109],arry2[109],d[109];
void BFS(int a, int t);
void beforeB(int a);
void beforeD(int a);
void DFS(int a, int t);
int main()
{
 	int i,j,k,ver,side,shan;
 	scanf("%d%d",&ver,&side);
	for (k=0;k<side;k++)
 	{
  		scanf("%d%d",&i,&j);
  		tu[i][j]=1;
		tu[j][i]=1;
 	}
 	scanf("%d",&shan);
 	beforeD(ver);
 	memset(arry2,0,sizeof(arry2));
 	beforeB(ver); 	
 	for(i=0;i<ver;i++)
 	{
  		tu[i][shan]=0;
  		tu[shan][i]=0;
 	}
 	memset(arry2,0,sizeof(arry2));
 	beforeD(ver);
 	memset(d,-1,sizeof(d));
 	memset(arry2,0,sizeof(arry2));
 	beforeB(ver);
 	return 0;
}
void DFS(int a, int t)
{
 	int i;
 	printf("%d ",t);
	arry2[t]=-1; 	 	
 	for(i=0;i<a;i++)
 		if(tu[t][i]==1&&arry2[i]!=-1)
			DFS(a, i); 
}

void beforeD(int a)
{
 	int i,j;
 	for(i=0;i<a;i++)
  	for(j=0;j<a;j++)
   		if(tu[i][j]==1&&arry2[i]!=-1)
    	{
     		DFS(a,i);
     		break;
    	}
 	printf("\n");
 	return;
}

void BFS(int a, int t)
{
 	int i,start=0,end=-1;
 	printf("%d ",t);
 	arry2[t]=-1;
 	d[++end]=t;
 	while(start<=end)
 	{
  		t=d[start++];
  		for (i=0;i<a;i++)
  			if (tu[t][i]&&arry2[i]!=-1)
    		{
     			printf("%d ",i);
     			arry2[i]=-1;
     			d[++end]=i;
    		}
 	}
 	return;
}
void beforeB(int a)
{
 	int i,j;
 	for(i=0;i<a;i++) 	
  		for(j=0;j<a;j++)
   			if(tu[i][j]==1&&arry2[i]!=-1)
    		{
     			BFS(a,i);
     			break;
    		} 	
 	printf("\n");
  	return;
}

