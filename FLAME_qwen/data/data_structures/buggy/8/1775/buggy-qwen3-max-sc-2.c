#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200],que[200];
// weights图的邻接矩阵， visited访问数组， que BFS用的访问队列 
int n,m;    //顶点数和边数 
void travelDFS(int v)
{
    int i;
    printf("%d ",v);    //输出 
    visited[v]=1;        //已访问 
    for(i = 0; i < n; i++)
        if (weights[v][i]!=0 && !visited[i])    //如果矩阵元素为 1 且未访问过 
        {
            travelDFS(i);        //DFS访问 
        }
}
void travelBFS(int v)
{
    int i,head=0,tail=1,tmp;    //队头，队尾，出列的元素 
    que[head]=v;    //入队 
    while(head<=tail)    //队列访问完毕 
    {
        tmp=que[head];    //出队 
        head++;            //出队
        if(visited[tmp])    continue;    //如果访问过 
        else
        {
            printf("%d ",tmp);        //打印出队元素 
            visited[tmp]=1;            //已访问 
            for(i=0;i<n;i++)
                if (weights[tmp][i]!=0 && !visited[i])    //如果矩阵元素为 1 且未访问过 
                    que[tail++]=i;        //入队 
        }
    }
}
int main()
{    
    int u,v,i,del;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v); //录入矩阵 
        weights[u][v]=1;
        weights[v][u]=1;
    }
    
    travelBFS(0);
    puts("");    //BFS
    memset(visited,0,sizeof(visited));
    memset(que,0,sizeof(que));
    travelDFS(0);
    puts("");    //DFS @@ [The order of output is incorrect: the problem requires DFS first, then BFS before deletion, but this code outputs BFS first then DFS.]
    memset(visited,0,sizeof(visited));
    scanf("%d",&del);
    
    visited[del]=1;        //    要删除的元素设置为已访问 
    travelBFS(0);
    puts("");    //BFS @@ [The order of output after deletion is also incorrect: it should be DFS first then BFS, but this code outputs BFS first then DFS.]
    memset(visited,0,sizeof(visited));
    visited[del]=1;        //    要删除的元素设置为已访问 
    travelDFS(0);
    puts("");    //DFS
    
    return 0;
}