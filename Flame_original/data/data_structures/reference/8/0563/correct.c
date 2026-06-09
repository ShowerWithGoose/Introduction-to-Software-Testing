#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int graph[900][900];
int visit[900];

void init_visit();
void init_graph();
void add_edge(int s,int t);
void dfs(int start);//深度优先
void bfs(int start);//广度优先

int queue[900];
int front,rear,count;
void init_queue();
int is_empty();
void enqueue(int temp);
int dequeue();

int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    int s,t;
    init_graph();
    for(int i=0;i<m;i++){
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
    for(int i=0;i<n;i++){
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

void add_edge(int s,int t)//无向图加边
{
    graph[s][t]=1;
    graph[t][s]=1;
}

void init_visit()
{
    memset(visit,0,sizeof(visit));
}

void dfs(int start)//递归
{
    printf("%d ",start);
    visit[start]=1;//标记已经访问过
    for(int i=0;i<n;i++){
        if(graph[start][i]&&!visit[i]){//如果有边且没有访问过
            dfs(i);//dfs
        }
    }
}

void bfs(int start)//迭代
{

    init_visit();
    init_queue();
    enqueue(start);
    while(!is_empty()){
        int temp=dequeue();
        printf("%d ",temp);
        for(int i=0;i<n;i++){//将与此结点相连且未访问的结点加入队列
            if(!visit[i]&&graph[i][temp]==1){
                enqueue(i);
            }
        }
    }
}

void init_queue()
{
    for(int i=0;i<900;i++){
        queue[i]=-1;
    }
    front=0;
    rear=900-1;
    count=0;
}

int is_empty()
{
    return count==0;
}

void enqueue(int temp)
{
    visit[temp]=1;
    rear=(rear+1)%900;
    queue[rear]=temp;
    count++;
}

int dequeue()
{
    int temp;
    temp=queue[front];
    count--;
    front=(front+1)%900;
    return temp;
}


