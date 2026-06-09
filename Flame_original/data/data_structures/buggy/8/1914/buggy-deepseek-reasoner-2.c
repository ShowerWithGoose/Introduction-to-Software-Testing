#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

int visited[110];
int graph[110][110];
int queue[110];
int head;
int tail;
void visit(int i)
{
    printf("%d ",i);
}


void DFS(int i,int n)//深度
{
    int k=0;
  
    if(visited[i]==1)
    {
        return;
    }
    else if(visited[i]==0)
    {
        visited[i]=1;
        visit(i);
        for(k=0;k<n;k++)
        {
            if(graph[i][k]!=0)
            {
                DFS(k,n);
            }
        }
    }
}
void push(int i)
{
    tail++;
    queue[tail]=i;
}
int empty()
{
    if(head==tail)
    {
        return 1;
    }
    else return 0;
}
int pop()
{
    head++;
    return queue[head];
}
void BFS(int i,int n)//广度
{
    int k=0;
    int tem=0;

    push(i);
    while (!empty())
    {
        tem=pop();
        
        if(visited[tem]==1)
        {
            continue;
        }
        visited[tem]=1;
        visit(tem);
        for(k=0;k<n;k++)
        {
            if(graph[tem][k]==1) // @@ [Should check visited[k]==0 to avoid duplicate pushes and prevent queue overflow]
            {
                push(k);
            }
        }
    }
}
void clear()
{
    head=0;
    tail=0;
    int i=0;
    for(i=0;i<110;i++)
    {
        queue[i]=0;
    }
}
void guilinggao()
{
    int i,j;
    for(i=0;i<110;i++)
    {
       visited[i]=0;
    }
}
void delete(int i,int n)
{
    int k=0;
    for(k=0;k<110;k++)
    {
        graph[i][k]=0;
        graph[k][i]=0;
    }
}
int main ()
{
    int n=0,line=0;
    scanf("%d %d",&n,&line);
    int i=0,k=0;
    int x=0,y=0;
    for(i=0;i<line;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x][y]=1;
        graph[y][x]=1;
    }
    int number=0;
    scanf("%d",&number);
    DFS(0,n);
    printf("\n");
    guilinggao();
    BFS(0,n);
    printf("\n");
    guilinggao();
    delete(number,n);
    DFS(0,n);
    printf("\n");
    guilinggao(); // @@ [Queue head/tail should be reset before second BFS to avoid out-of-bounds indices; also missing newline after second BFS]
    BFS(0,n); // @@ [Missing newline after this traversal; should print "\n" after this call]
    guilinggao();
    return 0;
}