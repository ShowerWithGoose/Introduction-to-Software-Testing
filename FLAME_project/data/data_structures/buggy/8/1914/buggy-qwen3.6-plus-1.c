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
    if(head==tail) // @@ The queue implementation is incorrect. In the reference code, head starts at 0 and tail at -1, and elements are added via ++tail. Here, head and tail both start at 0 (due to global initialization or clear()). If head==tail, it implies empty only if we haven't pushed anything or popped everything. However, the standard circular or linear queue logic usually distinguishes empty/full differently. More critically, the `pop` function increments head *before* returning, which means the first element pushed at index 0 will be returned when head becomes 1. Let's trace: push(0) -> tail=0, queue[0]=0. empty() (head=0, tail=0) returns 1 (true). This is wrong. The queue is not empty. The condition for empty should likely be head > tail or similar depending on initialization. In the reference, head<=tail is used for while loop. Here, if we initialize head=0, tail=-1 like reference, push increments tail to 0. empty checks head==tail (0==0) -> true? No, reference uses head<=tail for processing. The logic here is flawed. Specifically, `empty` returns 1 when head==tail. After push(0), head=0, tail=0. empty returns 1. The while loop doesn't run. BFS fails to print anything or prints incorrectly. 
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
            if(graph[tem][k]==1)
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
    guilinggao();
    BFS(0,n);
    guilinggao();
    return 0;
}