#include <stdio.h>
int graph[100][100],graph_del[100][100],visit[100];
int vet,line,i=0,type,temp,temp1,start,del=0;
void dfs(int a,int type)
{
    int i=0,flag=0;
    if(visit[a]!=0)
    return;
    printf("%d ",a);
    visit[a]=1;
    while(i<vet)
    {
        
        if(graph[a][i]==1&&type==1)
        dfs(i,type);
        else if(graph_del[a][i]==1&&type==2)
        dfs(i,type);
        i++;
    }
}
void wfs(int a,int type) // @@ The function name suggests BFS (Breadth-First Search), but the implementation uses a stack-like structure (LIFO) or incorrect queue logic, and crucially, it prints vertices after processing rather than when they are enqueued/visited in BFS order. Also, the variable 'stack' is used for BFS which should use a queue. The logic `while(i<vet)` inside the outer loop resets `i` but the queue/stack management is flawed for standard BFS. More importantly, the problem requires BFS to print nodes as they are visited (enqueued). This implementation prints them at the end from the `stack` array, which might not preserve BFS order if not managed as a strict queue. However, the primary error causing WA here is likely that `wfs` is implementing DFS or a broken traversal because it doesn't clear `visit` correctly or manage the queue head/tail properly for BFS. Let's look closer. Actually, the main issue in many student submissions for this specific problem is that BFS must print nodes when they are *added* to the queue (visited), not when they are popped. This code prints at the end. But wait, looking at the reference program, BFS prints when dequeued? No, standard BFS prints when visited/enqueued to ensure order. Let's look at the `wfs` logic again. It iterates neighbors, adds to `stack`, then increments `finger`. This is actually a BFS-like level order if `stack` is treated as a queue (FIFO). `stack[finger]` is the current node. Neighbors are added to `stack[point]`. `finger` increases. This IS a queue implementation (head=`finger`, tail=`point`). So the traversal order is correct for BFS. The issue is `visit[stack[finger]]=1;` is set *after* checking neighbors? No, `visit` is checked in the `if` condition: `visit[i]==0`. But `visit` for the current node `stack[finger]` is set to 1 only after processing its neighbors. This means if a node is reached via another path before it's processed, it might be added multiple times if `visit` isn't set when enqueued. In BFS, `visit` should be set when the node is *enqueued* (added to `stack`), not when it is *dequeued* (processed). Here, `visit` is set at line `visit[stack[finger]]=1;`. This allows a node to be added to the `stack` multiple times if it's a neighbor of multiple nodes processed before it is itself processed. This leads to duplicate entries in the output or incorrect order.
{
    int i=0,i1=0,stack[100],point=1,finger=0,tep;
    stack[0]=a;
    if(type==2)
    tep=del;
    while(finger<vet-tep)
    {
    while(i<vet)
    {
        if(graph[stack[finger]][i]==1&&visit[i]==0&&type==1)
        {
        stack[point]=i;
        point++;
        }
        else if(graph_del[stack[finger]][i]==1&&visit[i]==0&&type==2)
        {
        stack[point]=i;
        point++;
        }
        i++;
    }
    visit[stack[finger]]=1; // @@ Error: In BFS, the 'visited' status should be marked when the node is enqueued (added to the queue/stack array), not when it is dequeued (processed). Marking it here allows the same node to be added to the queue multiple times by different parents before it is processed, leading to duplicates in the 'stack' array and thus incorrect output.
    finger++;i=0;
    }
    while(i<vet-tep)
    {
    printf("%d ",stack[i]);
    i++;
    }
}

int main()
{
scanf("%d %d",&vet,&line);
while(i<line)
{
    scanf("%d %d",&temp,&temp1);
    graph[temp][temp1]=1;
    graph_del[temp][temp1]=1;
    graph[temp1][temp]=1;
    graph_del[temp1][temp]=1;
    i++;
}
while(~scanf("%d",&type)) // @@ The problem specifies a single vertex to delete. Using `while(~scanf(...))` implies multiple test cases or reading until EOF. While this might handle single input correctly, the logic inside `del++` and the global state `del` accumulates if there were multiple inputs, but more importantly, the problem description implies a single run. However, the critical error is that `del` is incremented globally. If the input is just one number, `del` becomes 1. This part is technically okay for a single case but bad practice. The real issue is likely elsewhere.
{
    i=0;del++;
    while(i<vet)
    {
        graph_del[i][type]=0;
        graph_del[type][i]=0;
        i++;
    }
}
dfs(0,1); 
memset(visit,0,100);printf("\n");
wfs(0,1);
memset(visit,0,100);printf("\n");
dfs(0,2);
memset(visit,0,100);printf("\n");
wfs(0,2);



}