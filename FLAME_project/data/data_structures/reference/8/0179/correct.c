#include<stdio.h>
#include<math.h>
#include<string.h> 
                 
                 
int Visited[1024]={0};//标志相应顶点是否被访问 

/*
void BFS(struct ver G[],int v){
	struct edge *p;
	//VISIT(G,v)访问
	Visited[v]=1;//表示某点被访问完成
	en 
} 
*/


int juzhen[100][100]={0};//邻接矩阵//二维必须固定第二层大小 
void createjz(int juzhen[][100],int bian,int v1,int v2){//矩阵 边数 前顶点 后顶点 
     int i;
     int u=v1,v=v2;
     for(i=0;i<bian;i++){
     	juzhen[u][v]=juzhen[v][u]=1;
	 }
} 
void deletejz(int juzhen[][100],int point,int v){//矩阵 顶点数 要删除的顶点 
	int i;
	for(i=0;i<point;i++){
		juzhen[v][i]=0;//清零第v行，删除从v出发的边 
		juzhen[i][v]=0;//清零第v列，删除连接v的边 
	} 
}
/////
void jzDFS(int v,int vnum){//顶点 顶点数 //图矩阵的深度优先遍历 
	int i,p;
	//访问当前顶点 
	for(i=0;i<vnum;i++)
	if(juzhen[v][i]!=0&&Visited[i]==0){
		break;
	}
	//printf("%d",v);这里可以对当前顶点做操作 
	//i表示找到的连接顶点 
	Visited[v]=1;//标记当前顶点 
	
	for(p=i;p<vnum;p++){
		if(!Visited[p]&&juzhen[v][p]==1){
		printf(" %d",p);	//在递归前输出，保证一定会输出进行递归的p值 
			jzDFS(p,vnum);
		}
	}

}
//BSF的准备 
int queue[1024],head=0,rear=-1;//queue的空间要尽量大
int isempty(){
	return head>rear;
} 
void push(int x){
	queue[++rear]=x;
}

//
void jzBSF(int v,int vnum){//     //图矩阵的广度优先遍历 
int i;int j;
	push(v);

	Visited[v]=1;

	while(!isempty()){
		
		v=queue[head++];
		for(i=0;i<vnum;i++){
			if(!Visited[i]&&juzhen[v][i]==1){
				push(i);

				printf(" %d",i);
				Visited[i]=1;
			}
		}
	}
} 

int main(){
	int vnum,edgenum,i,j,k,bef,aft;
	scanf("%d %d",&vnum,&edgenum);
	for(i=0;i<edgenum;i++){
		scanf("%d %d",&bef,&aft);
		createjz(juzhen,edgenum,bef,aft); 
	}

	int del;
	scanf("%d",&del);
	printf("0");
jzDFS(0,vnum);

	printf("\n0");
	for(i=0;i<vnum;i++) Visited[i]=0;//清空 
jzBSF(0,vnum);
	


printf("\n0");
	for(i=0;i<vnum;i++) Visited[i]=0;//清空 
	deletejz(juzhen,vnum,del);
	jzDFS(0,vnum);
	

printf("\n0");
	for(i=0;i<vnum;i++) {
	Visited[i]=0;//清空 
	queue[i]=0;}
	rear=-1;head=0;
	deletejz(juzhen,vnum,del);
jzBSF(0,vnum);
	return 0;
}


/*
9 10
0 1
0 2
1 4
1 3
1 8
6 8
3 6
2 7
5 7
2 5
3
*/ 







