#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int visit[105]={0},sum1,sum2,graph[100][100]={0},del[100],len;
char c[200];
void deep(int );
void wide(int );
void wide2(int );
int main()
{	    
    int i,j,k,x,flag=0;
	scanf("%d %d",&sum1,&sum2);
	for(i=0;i<sum2;i++)
	{
		scanf("%d %d",&j,&k);
		graph[j][k]=1;
		graph[k][j]=1;
	 } 
	 i=0;j=0;
	 deep(0);
	 printf("\n");
	 for(i=0;i<sum1;i++)
	 visit[i]=0;
	 wide(0);
	 printf("\n");
	 //
	 k=0;
	 scanf("%d",&x);
	 	for(i=0;i<sum1;i++)
	 	{
	 		graph[x][i]=0;
	 		graph[i][x]=0;
		 }
	 
	 for(i=0;i<sum1;i++)
	 visit[i]=0;
	 i=0;j=0;
	 deep(0);
	 printf("\n");
	 for(i=0;i<sum1;i++)
	 visit[i]=0;	
	 wide2(0);
	 return 0;
 } 
void deep(int a){
	int b;
	if(visit[a]==0)
	{
		printf("%d ",a);
		visit[a]=1;
	}	
	if(a<sum1)
	{
		for(b=0;b<sum1;b++)
		{
			if(graph[a][b]==1&&visit[b]==0)
			{				
				deep(b);
			}
		}
	}
}
void wide(int a){
    int s[100][100]={0},sum=0,t,m,count=0,n=0,w=0,flagg=0;
    printf("%d ",a);
    visit[a]=1;
    sum++;
    for(t=0;t<sum1;t++)
    {
    	if(graph[0][t]==1)
    	s[0][count++]=t;
	}    
    while(1)
    {
    	for(m=0;m<count;m++)
    	{
    		if(visit[s[n][m]]==0)
    		{
    			visit[s[n][m]]=1;
    			sum++;
    			printf("%d ",s[n][m]);
    			t=0;
    			for(t=0;t<sum1;t++)
    			{
    				if(visit[t]==0&&graph[s[n][m]][t]==1)
    				{    					
    					s[n+1][w++]=t;
    					//n++;
    					//sum++;
					}
				}
			}
		}
			n++;
		count=w;
		w=0;
		if(sum==sum1)
		flagg++;
		if(flagg==2)
		break;	
	}
}
void wide2(int a){
    int s[100][100]={0},sum=0,t,m,count=0,n=0,w=0,flagg=0;
    printf("%d ",a);
    visit[a]=1;
    sum++;
    for(t=0;t<sum1;t++)
    {
    	if(graph[0][t]==1)
    	s[0][count++]=t;
	}    
    while(1)
    {
    	for(m=0;m<count;m++)
    	{
    		if(visit[s[n][m]]==0)
    		{
    			visit[s[n][m]]=1;
    			sum++;
    			printf("%d ",s[n][m]);
    			t=0;
    			for(t=0;t<sum1;t++)
    			{
    				if(visit[t]==0&&graph[s[n][m]][t]==1)
    				{    					
    					s[n+1][w++]=t;
    					//n++;
    					//sum++;
					}
				}
			}
		}
			n++;
		count=w;
		w=0;
		if(sum==sum1-1)
		flagg++;
		if(flagg==2)
		break;	
	}
}










