#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
int graph[maxn][maxn];
int visit[maxn];
void init_visit();
void init_graph();
void add_edge(int s,int t);
void dfs(int start);
void bfs(int start);
int queue[maxn];
int front,rear,count;
void init_queue();
int is_empty();
void enqueue(int temp);
int dequeue();

int n,m;

int main()
{
	int i;
    scanf("%d %d",&n,&m);
    int s,t;
    init_graph();
    for(i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        add_edge(s,t);
    }
    int will_del_node;
    scanf("%d",&will_del_node);
    init_visit();
    dfs(0);
    printf("\n");
    bfs(0);
    printf("\n");
    for(i=0;i<n;i++){
        graph[will_del_node][i]=0;
        graph[i][will_del_node]=0;
    }
    init_visit();
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}

void init_graph()
{
    memset(graph,0,sizeof(graph));
}

void add_edge(int s,int t)
{
    graph[s][t]=1;
    graph[t][s]=1;
}

void init_visit()
{
    memset(visit,0,sizeof(visit));
}

void dfs(int start)
{
	int i;
    printf("%d ",start);
    visit[start]=1;
    for(i=0;i<n;i++){
        if(graph[start][i]&&!visit[i]){
            dfs(i);
        }
    }
}

void bfs(int start)
{
	int i;
    init_visit();
    init_queue();
    enqueue(start);
    while(!is_empty()){
        int temp=dequeue();
        printf("%d ",temp);
        for(i=0;i<n;i++){
            if(!visit[i]&&graph[i][temp]==1){
                enqueue(i);
            }
        }
    }
}

void init_queue()
{
	int i;
    for(i=0;i<maxn;i++){
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
    visit[temp]=1;
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

