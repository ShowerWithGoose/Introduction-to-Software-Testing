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
            if(adjoin[d][i]!=0)
            enquene(i);
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
    scanf("%d %d",&m,&n);//顶点个数，边的个数
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&j,&k);
        adjoin[j][k]=1;
        adjoin[k][j]=1;
    }
    int d; // @@ Declaring a variable in the middle of a block violates C89 standards and may cause a compilation error on strict compilers.
    DFSgraph(0,m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    BFSgraph(m);
    printf("\n");
    for(i=0;i<m;i++) // @@ Global queue pointers head and tail are not reset to 0 before the second BFS, causing incorrect queue operations and potential infinite loops or garbage reads.
    visited[i]=0;
    scanf("%d",&d);
    for(i=0;i<m;i++)
    {
        adjoin[d][i]=0;
        adjoin[i][d]=0;
    }
    DFSgraph(0,m); // @@ visited[del] is not marked as 1 before traversal, which may cause the deleted vertex to be visited if it becomes reachable through other paths.
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    BFSgraph(m); // @@ visited[del] is not marked as 1 and head/tail are not reset to 0, leading to incorrect BFS traversal and output after deletion.
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    return 0;
}