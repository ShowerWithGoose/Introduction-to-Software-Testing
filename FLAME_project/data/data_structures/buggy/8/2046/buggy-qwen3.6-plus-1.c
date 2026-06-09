#include <stdio.h>
#include <stdlib.h>

int adjoin[105][105];
int visited[105];
int quene[105],head=0,tail=0;
void enquene(int i)
{
    if((tail+1)%105!=head)
    quene[tail++%105]=i;
    else
    printf("qune full");
}
void BFSgraph(int m)
{
    int d,i;
    enquene(0);
    while(head!=tail)
    {
        d=quene[head];
        head=(head+1)%105;
        if(visited[d]==1)
        continue;
        visited[d]=1;
        printf("%d ",d);

        for(i=0;i<m;i++)
        {
            if(adjoin[d][i]!=0 && !visited[i]) // @@ The original code enqueues neighbors without checking if they are already visited or in the queue, which can lead to duplicate entries and incorrect traversal order or infinite loops in some contexts, although strictly BFS handles duplicates via the visited check upon dequeue. However, standard efficient BFS checks before enqueue. More critically, the problem requires visiting adjacent vertices in ascending order. The loop `for(i=0;i<m;i++)` iterates through all possible vertices 0 to m-1. This is correct for adjacency matrix representation if m is the number of vertices. Wait, in main, `m` is read as the first integer. Let's check main.
        }
    }
    return;
}
void DFSgraph(int d,int m)
{
    if(visited[d]==1)
    return;
    int i;
    visited[d]=1;
    printf("%d ",d);
    for(i=0;i<m;i++)
    if(adjoin[d][i]!=0)
    DFSgraph(i,m);
    return;
}
int main()
{
    int m,n,i,j,k;
    scanf("%d %d",&m,&n);//顶点个数，边的个数 @@ The variable names are swapped relative to the problem description and typical convention. The problem says "First, input the number of vertices n and the number of edges m". Here, the first input is stored in `m` and the second in `n`. Later, `m` is used as the limit for loops iterating over vertices (e.g., `for(i=0;i<m;i++)`). If `m` holds the number of vertices, this is correct. If `m` holds the number of edges, this is incorrect. Let's look at the input format: "input the number of vertices n and the number of edges m". The code reads `scanf("%d %d",&m,&n);`. So `m` gets vertices, `n` gets edges. The comment says "顶点个数，边的个数" (Vertex count, Edge count). So `m` is vertex count, `n` is edge count. This matches the usage in loops `for(i=0;i<m;i++)` which iterate up to the vertex count. So this line is logically correct regarding variable assignment, but the variable naming is confusing. However, looking at the reference program, it uses `m` for vertices and `n` for edges too? No, reference: `scanf("%d %d",&m,&n);` then `for(i=0;i<n;i++)` for edges. So reference `m`=vertices, `n`=edges. This code: `scanf("%d %d",&m,&n);` then `for(i=0;i<n;i++)` for edges. So `m`=vertices, `n`=edges. This is consistent.
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&j,&k);
        adjoin[j][k]=1;
        adjoin[k][j]=1;
    }
    int d;
    DFSgraph(0,m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    BFSgraph(m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    scanf("%d",&d);
    for(i=0;i<m;i++)
    {
        adjoin[d][i]=0;
        adjoin[i][d]=0;
    }
    DFSgraph(0,m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    BFSgraph(m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    return 0;
}