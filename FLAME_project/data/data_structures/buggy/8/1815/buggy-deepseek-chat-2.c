#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a,b,dV=-1;
int list[103][103],visited[103];
void DFS(int i)
{
    visited[i]=1;
    printf("%d ",i);
    for(int j=0;j<a;j++)
    {
        if((list[i][j]) && (!visited[j]))
        {
            DFS(j);
        }
    }
    return ;
}
void travelDFS()
{
    int i;
    for(i=0;i<a;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<a;i++)
    {
        if(i==dV)
        {
            continue;
        }
        if(!visited[i])
        {
            DFS(i);
        }
    }
    return ;
}
int q[103],start,end;
int empty()
{
    return start == end ? 1:0;
}
void enq(int x)
{
    q[end++]=x;
}
int deleteq()
{
    return q[start++];
}
void BFS(int i)
{
    visited[i]=1;
    printf("%d ",i);
    enq(i);
    while(!empty())
    {
        i=deleteq();
        for(int j=0;j<a;j++)
        {
            if( list[i][j] && (!visited[j]))
            {
                visited[j]=1;
                printf("%d ",j);
                enq(j);
            }
        }
    }
    return ;
}
void travelBFS()
{
    int i;
    for(i=0;i<a;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<a;i++)
    {
        if(i==dV)
        {
            continue;
        }
        if(!visited[i])
        {
            BFS(i);
        }
    }
    return ;
    
}
int main() {
    scanf("%d%d",&a,&b);
    int a,b,deleteVertex; // @@ [Error: Variable 'a' and 'b' are redeclared locally, shadowing the global variables 'a' and 'b'. This causes the global 'a' (number of vertices) to be overwritten, leading to incorrect traversal behavior.]
    while(scanf("%d",&a)!=EOF)
    {
        if(scanf("%d",&b)!=EOF)
        {
            list[a][b]=list[b][a]=1;
        }
        else
        {
            deleteVertex=a;
        }
    }
    travelDFS();
    puts(" ");
    travelBFS();
    puts(" ");
    dV=deleteVertex;
    for(int i=0;i<a;i++)
    {
        list[dV][i]=list[i][dV]=0;
    }
    travelDFS();
    puts(" ");
    travelBFS();
    return 0;
}