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
int delete; // @@ [variable name 'delete' is a reserved keyword in C++, but more critically, in C it's allowed but poor practice; however, the real issue is that after deleting vertex 'delete', the graph still has 'numv' vertices including the deleted one, but traversal should skip the deleted vertex. However, the main bug is that the array size of G is fixed to 10x10, but problem states n can be up to 100]
scanf("%d",&delete);
for(int i=0;i<numv;i++){
    G[delete][i]=0;
    G[i][delete]=0;
}//删除顶点和边；
travelDFS(); // @@ [DFS and BFS still traverse all vertices from 0 to numv-1, including the deleted vertex. The deleted vertex should be excluded from traversal, but the code doesn't adjust numv or skip the deleted vertex during traversal]
printf("\n");
front=0;
rear=-1;
travelBFS(); // @@ [same issue: BFS will still try to visit the deleted vertex if it's reachable (but it's disconnected), but more importantly, the problem requires the graph to remain connected after deletion, yet the traversal includes the deleted vertex which is now isolated. However, the specification says "the graph is connected both before and after deleting the specified vertex", meaning the deleted vertex is removed entirely from the graph, so traversals should only consider the remaining n-1 vertices. But this code keeps numv unchanged and still iterates over all original vertices, including the deleted one. Since the deleted vertex has no edges, it won't be visited if starting from 0 (as long as 0 != delete), but if the deleted vertex is not 0, then DFS(0) won't visit it anyway because its edges are removed. However, the bigger issue is the fixed array size]
printf("\n");
return 0;
}