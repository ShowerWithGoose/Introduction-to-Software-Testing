#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
int G[maxn][maxn];
int V[maxn];
int n,m;
int queue[maxn];
int front,rear,count;
void init_queue();
int is_empty();
void enqueue(int temp);
int dequeue();
void init_V();
void init_G();
void add_edge(int s,int t);
void dfs(int start);
void bfs(int start);
int main()
{
    scanf("%d %d",&n,&m);
    int s,t;
    init_G();
    for(int i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        add_edge(s,t);
    }
    int will_del_node;
    scanf("%d",&will_del_node);
    init_V();
    dfs(0);
    printf("\n");
    bfs(0);
    printf("\n");
    for(int i=0;i<n;i++){
        G[will_del_node][i]=0;
        G[i][will_del_node]=0;
    }
    init_V();
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}
void init_queue()
{
    for(int i=0;i<maxn;i++){
        queue[i]=-1;
    }
    front=0;
    rear=maxn-1;
    count=0;
}
int is_empty()
{
    return count==0;
}
void enqueue(int temp)
{
    V[temp]=1;
    rear=(rear+1)%maxn;
    queue[rear]=temp;
    count++;
}
int dequeue()
{
    int temp;
    temp=queue[front];
    count--;
    front=(front+1)%maxn;
    return temp;
}
void init_V()
{
    memset(V,0,sizeof(V));
}
void init_G()
{
    memset(G,0,sizeof(G));
}
void add_edge(int s,int t)
{
    G[s][t]=1;
    G[t][s]=1;
}
void dfs(int start)
{
    printf("%d ",start);
    V[start]=1;
    for(int i=0;i<n;i++){
        if(G[start][i]&&!V[i]){
            dfs(i);
        }
    }
}
void bfs(int start)
{

    init_V();
    init_queue();
    enqueue(start);
    while(!is_empty()){
        int temp=dequeue();
        printf("%d ",temp);
        for(int i=0;i<n;i++)
            if(!V[i]&&G[i][temp]==1)enqueue(i);
    }
}

