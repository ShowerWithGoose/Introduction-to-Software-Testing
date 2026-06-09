#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  G[10][10];
int visited[10];
int numv,nume;
int Q[20];
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
int delete; // @@ [variable name 'delete' is a reserved keyword in C++ and may cause issues in some compilers or contexts, though it's technically allowed in C; however, more critically, after deleting the vertex, the traversal still considers all 'numv' vertices including the deleted one, which violates the problem requirement that the graph after deletion excludes the vertex entirely]
scanf("%d",&delete);
for(int i=0;i<numv;i++){
    G[delete][i]=0;
    G[i][delete]=0;
}//删除顶点和边；
travelDFS(); // @@ [this DFS still runs over all original 'numv' vertices, including the deleted vertex (which is now isolated but still present), but the problem states that the graph after deletion should exclude the vertex entirely; thus, traversals should only consider the remaining n-1 vertices, not include the deleted vertex even as an isolated node]
printf("\n");
front=0;
rear=-1;
travelBFS(); // @@ [same issue as above: BFS also includes the deleted vertex in the traversal range because 'numv' hasn't been reduced, so visited[] and loops still go up to original numv, potentially printing or processing the deleted vertex if it were reachable—but since it's disconnected, it won't be printed, yet the logic is flawed because the graph size effectively changes]
printf("\n");
return 0;
}