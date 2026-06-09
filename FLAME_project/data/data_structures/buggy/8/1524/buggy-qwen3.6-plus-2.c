#include<stdio.h>
#include<string.h>
int weight[200][200];
int visited[200];
int que[200];
int d,b;//顶点和边 
void DFS(int v)
{
    int i;
    printf("%d",v);//输出，意为访问这个节点 @@ [Missing space after vertex number in output, expected format is "vertex "]
    visited[v]=1;//已访问 
    for(i=0;i<d;i++)
    {
        if(weight[v][i]!=0&&visited[i]!=0) @@ [Logic error: condition should be visited[i]==0 to visit unvisited nodes. Currently it only visits already visited nodes, causing infinite recursion or incorrect traversal]
        {
            DFS(i);    
        }
    }
}
void BFS(int v)
{
    int i,head=0,tail=1,tmp;
    que[head]=v;//入队 
    while(head<=tail)
    {
        printf("%d",que[head]); @@ [Premature print of vertex before checking if it's visited, leading to duplicate outputs]
        tmp=que[head];
        head++;//出队
        if(visited[tmp]!=0)//访问过了 
        {
            continue;
        }else
        {
            printf("%d",tmp); @@ [Duplicate print of vertex, once before check and once inside else block]
            visited[tmp]=1;
            for(i=0;i<d;i++)
            {
                if(weight[tmp][i]!=0&&visited[i]!=0) @@ [Logic error: condition should be visited[i]==0 to enqueue unvisited neighbors. Currently enqueues already visited nodes]
                {
                    que[tail]=i;
                    tail++;
                }
            }
        }
    }
}
int main()
{
    int i,j,k,sc;
    scanf("%d %d",&d,&b);
    for(i=0;i<b;i++)
    {
        scanf("%d %d",&j,&k);
        weight[j][k]=1;
        weight[k][j]=1;
    }
    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    BFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    scanf("%d",&sc);
    visited[sc]=1;//置为1意为这个点访问过了，意为删除 
    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    visited[sc]=1;
    BFS(0);
    return 0; 
}