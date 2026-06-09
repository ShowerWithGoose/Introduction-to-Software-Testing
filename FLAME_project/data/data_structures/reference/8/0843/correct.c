#include<stdio.h>
#define MAX 256
int graph[MAX][MAX],k=1000;
int  Visited[MAX]={0};
void DFS(int  G[][MAX], int v,int n)
{
    int i=0,p;
    Visited[v] = 1; 
    if(v!=k)
        printf("%d ",v);
    for(; i<n; i++){
        p = G[v][i];
        if( Visited[i] !=1&&i!=v&&p!=0)
            DFS(G,i,n);
    }
         
} 
void  travelDFS(int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( Visited[i]!=1 ) DFS(graph, i,n);
    printf("\n");
}
int front,count,rear=MAX-1,queue[MAX],e;
int emptyQ(){
    return count==0;
}
void enQueue(int p){

        rear=(rear+1)%MAX;
        queue[rear]=p;
        count++;
    
}
int deQueue(){
        count--;
        e=queue[front];
        front=(front+1)%MAX;
        return e;
    
}
void BFS(int  G[][MAX], int v, int n)//广度遍历
{
    int i=0,p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(v);
    while( !emptyQ()){
        v = deQueue();  //取出队头元素
        if(v!=k)
            printf("%d ",v);
        for(i=0; i<n; i++ ){
            p = G[v][i]; 
            if( Visited[i] !=1&&i!=v&&p!=0 ) {
                Visited[i] = 1; //标识某顶点入队
                enQueue(i);
           }
        }
     }
}

void  travelBFS(int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(graph, i,n);
    printf("\n");
}
void createGraph(){ 
    
    int i,n,v1,v2,l;
    scanf("%d%d",&n,&l);
    for(i=0; i<l; i++){
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    travelDFS(n);
    travelBFS(n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        graph[i][k]=0;
        graph[k][i]=0;
    }
    travelDFS(n);
    travelBFS(n);
}
int main(){
    int i=0;
    createGraph();
}

