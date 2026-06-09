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
    if(head==tail) // @@ The queue implementation is incorrect. 'head' and 'tail' are initialized to 0. When one element is pushed, tail becomes 0 (if pre-increment was used it would be different, but here tail++ makes it 1? No, tail starts at 0. push does tail++. So tail becomes 1. queue[1]=i. head is 0. empty checks head==tail. 0!=1. Correct. Pop does head++. head becomes 1. Returns queue[1]. Next loop: head=1, tail=1. empty returns 1. Loop ends. This logic seems okay for a simple queue IF head and tail are managed correctly. However, the standard circular queue or simple array queue usually initializes head=0, tail=-1 or head=0, tail=0 with different push/pop semantics. Let's look closer. push: tail++ then assign. If tail starts at 0, first push makes tail 1, assigns to queue[1]. pop: head++ then return. If head starts at 0, first pop makes head 1, returns queue[1]. This works. BUT, the global variables head and tail are not re-initialized in clear() properly relative to how they are used in BFS if BFS relies on specific start states. Actually, the main issue is likely simpler.
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
    printf("\n"); // @@ The expected output shows that each traversal sequence is printed on its own line. The previous BFS call does not print a newline at the end of its sequence inside the function, nor is one printed after it in main. The last BFS output is missing a trailing newline, which might cause presentation errors or mismatch in strict comparators, although typically "Wrong Answer" implies content mismatch. Looking at the buggy output vs expected: Buggy has "0 2 " (with space) and newlines. Expected has "0 2". The visit function prints "%d ". This leaves a trailing space. The reference program also prints trailing spaces. The main difference often lies in the newline handling. The provided buggy output block shows 4 lines. The expected output block shows 4 lines. The code prints \n after DFS, \n after BFS. Then \n after DFS. Then nothing after last BFS. This means the last line of output might not be terminated by a newline, or the judge expects a newline. Adding printf("\n") ensures the format matches the previous blocks.
    guilinggao();
    return 0;
}