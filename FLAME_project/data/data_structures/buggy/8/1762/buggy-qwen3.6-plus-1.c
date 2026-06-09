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
    printf("\n"); // @@ [This function prints a newline every time it is called. The problem requires vertex sequences in a single line. The newlines are printed after DFS/BFS calls in main, but this extra newline inside rejust might cause formatting issues or empty lines if not handled carefully. More critically, rejust resets visited array 'v'. Setting v[i]=2 for deleted node is correct logic to mark it as unavailable/visited.]
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
        if(v[x] != 1) { // @@ [The node dequeued might have been marked visited when enqueued, but if the start node 0 is enqueued, it hasn't been marked visited in 'v' yet in this BFS implementation. In the current code, v[i]=1 is set when enqueueing neighbors. But for the start node 0, v[0] is 0 initially. So we must print and mark it here if it hasn't been processed. However, looking at the loop: queue[0]=0. Then x=0. v[0] is 0. It prints 0. Then marks neighbors. This seems okay for the first node. BUT, if a node is enqueued, v[i] is set to 1. So when it is dequeued, v[x] will be 1. The check if(v[x]==0) is missing in the original BFS code before printing. Wait, in the provided buggy code: printf("%d ",x); is called unconditionally. If v[x] was set to 1 when enqueued, this is fine. But for the start node 0, v[0] is 0. It prints 0. Then neighbors are enqueued and marked 1. When they are dequeued, they are printed again? No, because v[i]=1 is set when enqueuing. So when dequeued, they are just printed. The issue is: does the standard BFS mark visited when enqueuing or dequeuing? Standard is enqueuing to avoid duplicates. Here, v[i]=1 is set at enqueue. So when dequeued, v[x] is 1. The code prints x regardless. This is logically correct for traversal order IF we assume every enqueued node is printed exactly once when dequeued. HOWEVER, there is a subtle bug: if the graph is disconnected or nodes are unreachable, isend() breaks. But the main issue is likely the DFS recursion depth or stack overflow? No, n<=100. Let's look at the output difference.
        // Expected BFS: 0 1 2. Buggy BFS: 0 1.
        // Why did 2 not appear in BFS?
        // Input: 3 vertices, edges (0,1), (1,2), (0,2). Delete 1.
        // Before delete:
        // DFS: 0 -> 1 -> 2. Output: 0 1 2. Correct.
        // BFS: Queue: [0]. Pop 0, print 0. Neighbors of 0: 1, 2. Enqueue 1, mark v[1]=1. Enqueue 2, mark v[2]=1. Queue: [1, 2].
        // Pop 1, print 1. Neighbors of 1: 0 (visited), 2 (visited). Queue: [2].
        // Pop 2, print 2. Neighbors of 2: 0 (visited), 1 (visited). Queue: [].
        // Output: 0 1 2.
        // The buggy output says "0 1". This implies 2 was not printed.
        // Why? Look at isend(). isend() checks if any v[i]==0.
        // After processing 0: v[0]=0 (never set to 1 in BFS for start node?!).
        // In BFS(): queue[0]=0. front=0, rear=0.
        // Loop 1: front<=rear (0<=0). isend()? v[0]=0, v[1]=0, v[2]=0. Returns -1.
        // x=queue[0++]=0. printf("0 ").
        // Neighbors of 0: 1 and 2.
        // i=1: A[0][1]=1, v[1]=0. queue[++rear]=queue[1]=1. v[1]=1.
        // i=2: A[0][2]=1, v[2]=0. queue[++rear]=queue[2]=2. v[2]=1.
        // Loop 2: front=1, rear=2. 1<=2. isend()? v[0]=0. Returns -1.
        // x=queue[1++]=1. printf("1 ").
        // Neighbors of 1: 0 (A[1][0]=1, v[0]=0??).
        // Wait, v[0] is still 0!
        // i=0: A[1][0]=1, v[0]=0. queue[++rear]=queue[3]=0. v[0]=1.
        // i=2: A[1][2]=1, v[2]=1. Skip.
        // Loop 3: front=2, rear=3. 2<=3. isend()? All v[i] are 1 now? v[0]=1, v[1]=1, v[2]=1. Returns 1.
        // Break!
        // So 2 is never popped and printed.
        // The error is that isend() terminates the BFS prematurely if all nodes are *visited* (marked in v), even if they are still in the queue waiting to be *printed*.
        // BFS should continue until the queue is empty, not until all nodes are visited. The visited array prevents re-enqueueing, but the printing happens on dequeue.
        // Therefore, the check `if(isend()==1) break;` is incorrect for BFS. It should only break when the queue is empty.
        }
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
    scanf("%d%d",&m,&n);
    for(i=0,j=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        A[a][b]=A[b][a]=1;
    }
    DFS(0);
    rejust();
    BFS();
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