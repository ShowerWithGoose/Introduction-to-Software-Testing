#include <stdio.h>

int point[150][150];
int book[150];  //0表示还没访问 
int queue[150];
int point_num,edge_num;

void dfs(int);
void bfs();

int main()
{
	
	scanf("%d%d",&point_num,&edge_num);
	
	int i,a,b;
	for(i=1;i<=edge_num;i++){
		scanf("%d%d",&a,&b);
		point[a][b]=1;  point[b][a]=1;
	}
	//深度优先 
	book[0]=1;
	dfs(0);  printf("\n");
	
	//广度优先
	for(i=0;i<point_num;i++) book[i]=0; 
	bfs();  printf("\n");
	
	//删除
	scanf("%d",&a);
	for(i=0;i<point_num;i++){
		point[a][i]=0;  point[i][a]=0;
	} 
	
	//深度优先
	for(i=0;i<point_num;i++) book[i]=0;
	book[0]=1;
	dfs(0);  printf("\n");
	
	//广度优先
	for(i=0;i<point_num;i++) book[i]=0; 
	bfs();  printf("\n");
	
	return 0;
}

void dfs(int n){
	int i;
	book[n]=1;  printf("%d ",n);  //已经访问 
	
	for(i=0;i<point_num;i++){
		if(point[n][i]==1&&book[i]==0){
			dfs(i);
		}
	}
}

void bfs(){
	int head=0,tail=1;
	queue[0]=0;  book[0]=1;
	
	int i;
	while(head<tail){
		printf("%d ",queue[head]);  
		for(i=0;i<point_num;i++)
			if(point[queue[head]][i]==1&&book[i]==0){
				queue[tail]=i;  tail++;
				book[i]=1;
			}
		head++;
		
	}
}
	

