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
    init_graph(); // @@ [Linker error: function definition missing or not linked properly]
    for(i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        add_edge(s,t); // @@ [Linker error: function definition missing or not linked properly]
    }
    int will_del_node;
    scanf("%d",&will_del_node);
    init_visit(); // @@ [Linker error: function definition missing or not linked properly]
    dfs(0); // @@ [Linker error: function definition missing or not linked properly]
    printf("\n");
    bfs(0); // @@ [Linker error: function definition missing or not linked properly]
    printf("\n");
    for(i=0;i<n;i++){
        graph[will_del_node][i]=0;
        graph[i][will_del_node]=0;
    }
    init_visit(); // @@ [Linker error: function definition missing or not linked properly]
    dfs(0); // @@ [Linker error: function definition missing or not linked properly]
    printf("\n");
    bfs(0); // @@ [Linker error: function definition missing or not linked properly]
    return 0;
}