#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  G[10][10]; // @@ [Insufficient array size: max vertices is 100, but array size is only 10]
int visited[10]; // @@ [Insufficient array size: max vertices is 100, but array size is only 10]
int numv,nume;
int Q[20]; // @@ [Insufficient queue size: max vertices is 100, but queue size is only 20]
int front=0,rear=-1;
void DFS(int v)
{//在图G中，从顶点V开始进行深度优先遍历
    visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(int i=0; i<numv;  i++)
         if( !visited[i] &&G[v][i]==1)
             DFS(i);
}
void  travelDFS()
{
    int i;
    for(i=0; i<numv; i++) visited[i] = 0 ;//初始化
    DFS(0);
}
void BFS( int v)
{
    visited[v] = 1; //标识某顶点已入队
    Q[++rear]=v;
    while( !(front>rear)){
         v = Q[front++];  //取出队头元素
         printf("%d ",v); //访问当前顶点
         for(int i=0; i<numv;  i++ ) //访问该顶点的每个邻接顶点
             if( !visited[i]&&G[v][i]==1) {
                    visited[i] = 1; //标识某顶点入队
                    Q[++rear]=i;
           }
     }
}
void  travelBFS()
{
    int i;
    for(i=0; i<numv; i++) visited[i] = 0 ;
    BFS(0);
}
int main(){
scanf("%d%d",&numv,&nume);
int v1,v2;//输入顶点个数，边个数
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        G[i][j]=0;
    }
}//初始化G邻接矩阵
for(int i=0;i<nume;i++){
scanf("%d%d",&v1,&v2);
G[v1][v2]=1;
G[v2][v1]=1;
}//建邻接矩阵
travelDFS();
printf("\n");
travelBFS();
printf("\n");
int delete;
scanf("%d",&delete);
for(int i=0;i<numv;i++){
    G[delete][i]=0;
    G[i][delete]=0;
}//删除顶点和边；
travelDFS();
printf("\n");
front=0;
rear=-1;
travelBFS();
printf("\n");
return 0;
}