#include <stdio.h>
#include <stdlib.h>

int adjoin[105][105];
int visited[105];
int quene[105],head=0,tail=0;
void enquene(int i)
{
    if((tail+1)%105!=head) // @@ Incorrect queue full condition: tail is not modulo 105 but head is, causing mismatch.
    quene[tail++%105]=i; // @@ tail is never reduced modulo 105, causing it to grow indefinitely and making the circular queue ineffective.
    else
    printf("qune full");
}
void BFSgraph(int m)
{
    int d,i;
    enquene(0);
    while(head!=tail) // @@ Since head is modulo 105 and tail is not, the loop may never exit when tail exceeds 105.
    {
        d=quene[head];
        head=(head+1)%105; // @@ head is modulo 105, but tail is not, so head cannot catch up with tail when tail > 104.
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