#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int ver,edge,aa[100][100]={};

int visited[100];
void DFS(int s)
{
	int j;
	for(j=0;j<ver;j++)
	{
		if(visited[j]==0)
		{
			if(aa[s][j]==1||aa[j][s]==1)
			{
				printf("%d ",j);
				visited[j]++;
				DFS(j);
			}
		}		
	}
}

void BFS(int (*a)[100])
{
    int i,j,line[100]={},rear=1,k;
    int visit[100]={};
    for(i=0;i<rear;i++)
    {
        visit[line[i]]++;
        for(j=0;j<ver;j++)
        {
            if(visit[j]==0)
            {
                if(a[line[i]][j]==1||a[j][line[i]]==1)
                {
                	int judge=0;
                	for(k=0;k<rear;k++)
                	{
                		if(line[k]==j) judge=1; 
					}
					if(judge==1) continue;
                    line[rear]=j;
                    rear++;
                    a[line[i]][j]=0;
                    a[j][line[i]]=0;
                }
            }
        }
    }
    for(i=0;i<ver;i++)
    {
        printf("%d ",line[i]);
    }
    printf("\n");
}

void BFS2(int (*a)[100])
{
    int i,j,line[100]={},front=0,rear=1,k;
    int visit[100]={};
    for(i=0;i<rear;i++)
    {
        visit[line[i]]++;
        for(j=0;j<ver;j++)
        {
            if(visit[j]==0)
            {
                if(a[line[i]][j]==1||a[j][line[i]]==1)
                {
                	int judge=0;
                	for(k=0;k<rear;k++)
                	{
                		if(line[k]==j) judge=1; 
					}
					if(judge==1) continue;
                    line[rear]=j;
                    rear++;
                    a[line[i]][j]=0;
                    a[j][line[i]]=0;
                }
            }
        }
    }
    for(i=0;i<ver-1;i++)
    {
        printf("%d ",line[i]);
    }
    printf("\n");
}

int main()
{ 
    int b[100][100]={},d[100][100]={};
    int i,j,k;
    scanf("%d%d",&ver,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d%d",&j,&k);
        aa[j][k]=1;
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
        	b[i][j]=aa[i][j];
        	d[i][j]=aa[i][j];
		}
    }	
	
	int x;
	scanf("%d",&x);
    
    printf("0 ");
	visited[0]++;
	DFS(0);
	printf("\n");
	
    BFS(b);
	


	for(i=0;i<ver;i++)
	{
		aa[i][x]=0;
		aa[x][i]=0;
		d[i][x]=0;
		d[x][i]=0;
		visited[i]=0;
	}
	
	printf("0 ");
	visited[0]++;
	DFS(0);
	printf("\n");

	BFS2(d);

}


