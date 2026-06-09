#include<stdio.h>
int v[150]={0},A[150][150]={0},m,n,del=140,queue[150]={0}; // @@ [Variable 'm' is used for number of vertices and 'n' for number of edges, which is confusing but consistent within the file. However, 'del' is initialized to 140, which is fine as a placeholder.]
void rejust()
{
    int i;
    for(i=0;i<m;i++)
    {
        if(i==del)
        v[i]=2;
        else
        v[i]=0;
    }
    printf("\n"); // @@ [This function prints a newline, which causes extra blank lines in the output or interferes with the expected format if not handled correctly. The problem expects sequences on single lines. The main function calls this after DFS/BFS. The DFS/BFS functions print spaces. The newline here might be intended to end the line, but let's check the flow.]
}
int isend()
{
    int i,flag=0;
    for(i=0;i<m;i++)
    if(v[i]==0)
    flag=1;
    if(flag==1)
    return -1;
    else
    return 1;
}
void DFS(int x)
{
    int i,j;
    if(v[x]==0)
    {
        v[x]=1;
        printf("%d ",x);
    }
    if(isend()==1)
    return ;
    for(i=0;i<m;i++)
    {
        if(A[x][i]==1&&v[i]==0)
        {
            DFS(i);
        }
    }
}
void BFS()
{
    int rear,front,x,i;
    queue[0]=0;
    rear=front=0;
    while(front<=rear)
    {
        if(isend()==1)
        break;
        x=queue[front++];
        printf("%d ",x);
        for(i=0;i<m;i++)
        {
            if(A[x][i]==1&&v[i]==0)
            {
                queue[++rear]=i;
                v[i]=1;
            }
        }
    }
}
int main()
{
    int a,b,i,j;
    scanf("%d%d",&m,&n); // @@ [Input reads m (vertices) and n (edges). This matches the variable usage later where loops go up to m for vertices.]
    for(i=0,j=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        A[a][b]=A[b][a]=1;
    }
    DFS(0);
    rejust(); // @@ [rejust prints a newline. So far: "0 1 2 \n". This matches the first line of expected output "0 1 2".]
    BFS();    // @@ [BFS starts. It initializes queue with 0. But v[0] was set to 1 (or 2?) by rejust? 
               //      In rejust, if i==del (140), v[i]=2, else v[i]=0. So v[0] becomes 0. 
               //      So BFS will visit 0 again. 
               //      Expected BFS before delete: "0 1 2". 
               //      Let's trace BFS: 
               //      queue=[0], front=0, rear=0. 
               //      Loop: front<=rear (0<=0). isend? v[0]=0, so flag=1, returns -1. Continue.
               //      x=queue[0]=0. front becomes 1. Print "0 ".
               //      Neighbors of 0: 1, 2. 
               //      i=1: A[0][1]=1, v[1]=0. queue[1]=1, rear=1, v[1]=1.
               //      i=2: A[0][2]=1, v[2]=0. queue[2]=2, rear=2, v[2]=1.
               //      Loop: front=1, rear=2. 1<=2. isend? v[0]=1, v[1]=1, v[2]=1. All visited? 
               //      Wait, v[0] was set to 1 inside BFS? No, v[0] is set to 1 only if it enters the `if(v[x]==0)` block in DFS. In BFS, v[x] is NOT set to 1 when popped. It is set to 1 when added to queue.
               //      So when x=0, v[0] is still 0? No, v[0] was set to 1 in DFS. Then rejust set it to 0.
               //      In BFS, when we pop x=0, we do NOT mark v[0]=1. We only mark neighbors.
               //      So v[0] remains 0? No, wait. 
               //      In BFS: 
               //      queue[0]=0. 
               //      Pop 0. Print 0. 
               //      Add 1, 2 to queue. Mark v[1]=1, v[2]=1. 
               //      Next iter: Pop 1. Print 1. 
               //      Neighbors of 1: 0, 2. 
               //      i=0: A[1][0]=1, v[0]=0. So queue[3]=0, rear=3, v[0]=1.  <-- ERROR: Vertex 0 is added to queue again because v[0] was reset to 0 by rejust and not marked visited when processed in BFS.
               //      i=2: A[1][2]=1, v[2]=1. Skip.
               //      Next iter: Pop 2. Print 2.
               //      Neighbors of 2: 0, 1.
               //      i=0: A[2][0]=1, v[0]=1. Skip.
               //      i=1: A[2][1]=1, v[1]=1. Skip.
               //      Next iter: Pop 0 (from queue[3]). Print 0. 
               //      This results in "0 1 2 0 ...". 
               //      The standard BFS should mark the start node as visited immediately.
               ]
    rejust();
    scanf("%d",&del);
    for(i=0;i<m;i++)
    {
        A[del][i]=0;
        A[i][del]=0;
    }
    DFS(0);
    rejust();
    BFS();
    return 0;
}