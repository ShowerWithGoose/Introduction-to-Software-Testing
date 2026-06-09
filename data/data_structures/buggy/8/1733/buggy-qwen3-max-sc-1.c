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
int delete; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools, though it's technically allowed in pure C. However, more critically, after deleting the vertex, the code still runs DFS/BFS over all 'numv' vertices including the deleted one, which violates the problem requirement that traversal should only include remaining vertices. But the immediate compilation error likely stems from 'delete' being a reserved word in C++ mode. Since the error message says "gcc: not found", this might be a red herring — however, given the context of expected behavior, the real logical errors are below. But per instructions, we mark lines with potential errors.]

scanf("%d",&delete);
for(int i=0;i<numv;i++){
    G[delete][i]=0;
    G[i][delete]=0;
}//删除顶点和边；
travelDFS(); // @@ [This DFS still traverses all 'numv' vertices, including the deleted vertex (which is now isolated but still considered). The problem states the graph remains connected after deletion and traversal should only include existing vertices. However, the code does not reduce 'numv', so the deleted vertex (non-zero) is still included in traversal range, possibly causing incorrect output. But since the problem says the graph is connected after deletion and start is 0 (not deleted), it may still work if the deleted vertex is just ignored due to no edges. However, the bigger issue is in BFS queue state reuse.]

printf("\n");
front=0;
rear=-1;
travelBFS();
printf("\n");
return 0;
}