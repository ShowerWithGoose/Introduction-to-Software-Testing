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
// @@ The source code provided in the "Source Code" section is missing the function definitions (implementations) for init_graph, add_edge, init_visit, dfs, bfs, init_queue, is_empty, enqueue, and dequeue. The compiler error "undefined reference" occurs because these functions are declared but not defined in the compiled translation unit. To fix this, the function bodies from the "Reference Program" must be appended to this file.