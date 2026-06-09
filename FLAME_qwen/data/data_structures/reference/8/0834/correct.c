#include<stdio.h>
int map[100][100],visited[100]={0},stack[105],queue[105];
int n,m,d,top=-1,front=0,rear=-1,len=0; 
void visit1(int n);
void DFS(int a);
void visit2(int n);
void BFS(int a); 
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		map[a][b]=map[b][a]=1;
	}
	scanf("%d",&d);
	visit1(n);
	printf("\n");
	visit2(n);
	printf("\n");
	//for(int i=d;i<n;i++)
	//for(int j=0;j<n;j++)
	//map[i][j]=map[i+1][j];
	//for(int j=d;j<n;j++)
	//for(int i=0;i<n-1;i++)
	//map[i][j]=map[i][j+1];
	for(int i=0;i<n;i++){
		map[i][d]=0;
		map[d][i]=0; 
	}
	visit1(n);
	printf("\n");
	visit2(n);
	printf("\n");
	return 0;
}

void visit1(int n)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
    DFS(0);
}
void DFS(int a)
{
	int j;
	visited[a]=1;
	printf("%d ",a);
	for(j=0;j<n;j++){
		if(map[a][j]==1&&visited[j]==0){	
			DFS(j);
		}	
	}
}

void visit2(int n)
{
	for(int i=0;i<n;i++)
	visited[i]=0;
	BFS(0);
}
void BFS(int a)
{
	int j;
	visited[a]=1;
	queue[++rear]=a;
	len++;
	while(len>0){
		int b=queue[front++];
		len--;
		printf("%d ",b);
		for(j=0;j<n;j++){
		if(map[b][j]==1&&visited[j]==0){
	    	visited[j]=1;	
			queue[++rear]=j;
			len++;
		}	
	}
	}
}

