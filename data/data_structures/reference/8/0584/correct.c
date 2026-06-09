#include<stdio.h>
#include<string.h>

void travelDFS(int);
void travelBFS(int);

int dot_n,edge_n;
int matrix[100][100]={0},visited[100]={0};

int main(){
	int i,j=0,k=0,del_v;
	scanf("%d%d",&dot_n,&edge_n);
	int dot1,dot2;
	for(i=0;i<edge_n;i++){
		scanf("%d%d",&dot1,&dot2);
		matrix[dot1][dot2]=1;
		matrix[dot2][dot1]=1;
	}
	travelDFS(0);
	memset(visited,0,sizeof(visited));
	printf("\n");
	travelBFS(0);
	memset(visited,0,sizeof(visited));
	printf("\n");
	scanf("%d",&del_v);
	for(i=0;i<dot_n;i++){
		matrix[i][del_v]=0;
		matrix[del_v][i]=0;
	}
	travelDFS(0);
	memset(visited,0,sizeof(visited));
	printf("\n");
	travelBFS(0);
	memset(visited,0,sizeof(visited));
	printf("\n");
}

void travelDFS(int v){
	int i;
	printf("%d ",v); 
	visited[v]=1;		
	for(i=0;i<dot_n;i++){
		if (matrix[v][i]==1&&visited[i]==0)	
			travelDFS(i);
	}
}

void travelBFS(int v){
	int team[100]={0},head=-1,last=0;
	int i,temp;
	team[++head]=v;
	while(head<=last){
		temp=team[head++];
		if(visited[temp]==0)
		printf("%d ",temp);
		visited[temp]=1;
		for(i=0;i<dot_n;i++){
			if(matrix[temp][i]==1&&visited[i]==0){
				team[++last]=i;
			}
		}
	}
}


