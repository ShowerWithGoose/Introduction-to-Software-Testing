#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
int matrix[200][200];
int visited[200];
void creatmatrix(int matrix[][200],int Vnum,int Enum){
    int i,j,k,weight;
    for(i=0;i<Vnum;i++){
        for(j=0;j<Vnum;j++){
            matrix[i][j]=0;
        }
    }
    for(int k=0;k<Enum;k++){
        scanf("%d%d",&i,&j);
        matrix[i][j]=1;
        matrix[j][i]=1;
    }

}
void dfs(int v,int Vnum){
    printf("%d ",v);
    visited[v]=1;
    for(int w=0;w<Vnum;w++){
        if((matrix[v][w]!=0)&&(!visited[w])) dfs(w,Vnum);
    }
}
void bfs(int v,int vnum)
{
    int que[200];
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
            for(i=0;i<vnum;i++)
                if (matrix[tmp][i]==1&& !visited[i])    //如果矩阵元素为 1 且未访问过 
                    que[tail++]=i;        //入队 
        }
    }
}

int main(){
    int Vnum,Enum;
    scanf("%d%d",&Vnum,&Enum);
    creatmatrix(matrix,Vnum,Enum);
    int del;
    scanf("%d",&del);
    dfs(0,Vnum);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0,Vnum);
    printf("\n");
    for(int i=0;i<Vnum;i++){
        for(int j=0;j<Vnum;j++){
            if((i==del)||(j==del)) matrix[i][j]=0; @@ [This deletion approach zeroes out entire row and column, but does not remove the vertex from traversal logic. However, the real issue is that BFS uses a queue that may enqueue the deleted vertex before it's marked as deleted, but more critically: in BFS, when head > tail initially (e.g., after deletion), the loop condition `head <= tail` may never run. But the main error is that BFS implementation allows revisiting or skipping due to incorrect queue handling. However, the critical runtime error comes from BFS queue bounds: `tail` can exceed array size because there's no bound check on `tail++`. For Vnum up to 100, worst-case BFS enqueues all vertices, but `tail` starts at 1 and increments without bound — for 100 vertices, `tail` reaches 100 which is within 200, so maybe not. But the actual bug causing wrong output is that BFS marks node as visited only when dequeued, not when enqueued, leading to duplicate enqueues. This causes potential out-of-bound writes if many duplicates are enqueued. In the test case, after deletion, graph has vertices 0 and 2. BFS starts at 0, enqueues 2. Then dequeues 0 (prints 0), then dequeues 2 (prints 2). That seems okay. But before deletion: graph is triangle. BFS(0): enqueue 0. Dequeue 0 → print 0, enqueue 1 and 2. Then dequeue 1 → print 1, enqueue 0 (already visited later) and 2 (not visited yet → enqueue again). Then dequeue 2 → print 2, enqueue 0 and 1 (both will be skipped when dequeued). So output is "0 1 2", which matches. After deletion: matrix[0][1]=0, matrix[1][0]=0, etc. So from 0, only neighbor is 2. BFS: enqueue 0. Dequeue 0 → print 0, enqueue 2. Dequeue 2 → print 2. Output "0 2". So why runtime error? Actually, the problem says "Runtime Error", but the given test case produces output (empty?), meaning maybe infinite loop or crash. Looking closer: in BFS, `tail` starts at 1, and `que[head]=v` with head=0. Then in loop, when processing tmp=0, it enqueues neighbors at `que[tail++]`. But if a node has many neighbors, `tail` could go beyond 199. However, max vertices is 100, so max enqueues is 100, tail goes to 100 — safe. But the real issue: the BFS implementation does not prevent enqueueing the same node multiple times. For example, in a triangle, node 2 is neighbor of both 0 and 1. When processing 0, 2 is enqueued. When processing 1, 2 is enqueued again because it's not visited yet (visited only set when dequeued). So que might have [0,1,2,2]. Then when dequeuing the second 2, it's already visited (from first dequeue), so it skips. But this doesn't cause crash. However, the problem states "Runtime Error", and the buggy output is empty — meaning perhaps stack overflow in DFS? No, graph is small. Wait: the actual bug is in the deletion step. The code sets `matrix[i][j] = 0` if i==del or j==del. But note: when i==del and j==del, it's fine. However, the bigger issue is that in the traversals after deletion, the code still iterates over all vertices from 0 to Vnum-1, including the deleted vertex. But since the adjacency matrix entries involving `del` are zeroed, the deleted vertex won't be reached from others. However, what if the BFS or DFS starts at 0 (which is not deleted), so it's okay. But the real critical error is in BFS: the queue index `tail` is incremented without bound, but more importantly, the initial setting: `tail=1`, and `que[head]=v` with head=0. Then in the loop, when we dequeue (head++), and enqueue, tail increases. But the condition is `while(head <= tail)`. Initially, head=0, tail=1 → runs. After dequeuing 0, head=1, tail=1 → runs. Then if no new nodes, head becomes 2, tail=1 → stops. That's correct. So why runtime error? Let's simulate the test case:

Input: 3 3; edges (0,1),(1,2),(0,2); del=1.

Before deletion:
DFS(0): prints 0, visits 0. Then checks w=0: skip. w=1: matrix[0][1]=1, not visited → dfs(1). In dfs(1): prints 1, visits 1. Then checks w=0: visited. w=1: skip. w=2: matrix[1][2]=1, not visited → dfs(2). Prints 2. So "0 1 2" — correct.

BFS(0): 
que[0]=0; head=0, tail=1.
Loop: head(0)<=tail(1) → true.
tmp=que[0]=0; head=1.
visited[0] is 0 → print 0, mark visited[0]=1.
Then for i=0 to 2: 
i=0: matrix[0][0]=0 → skip.
i=1: matrix[0][1]=1 and !visited[1] → que[tail=1]=1; tail=2.
i=2: matrix[0][2]=1 and !visited[2] → que[2]=2; tail=3.
Now head=1, tail=3 → loop continues.
tmp=que[1]=1; head=2.
visited[1]=0 → print 1, mark visited[1]=1.
For i=0: matrix[1][0]=1 but visited[0]=1 → skip.
i=1: skip.
i=2: matrix[1][2]=1 and !visited[2] → que[3]=2; tail=4.
Now head=2, tail=4.
tmp=que[2]=2; head=3.
visited[2]=0 → print 2, mark visited[2]=1.
For i=0: visited. i=1: visited. i=2: skip.
Now head=3, tail=4 → loop continues.
tmp=que[3]=2; head=4.
visited[2]=1 → continue.
Now head=4, tail=4 → loop continues.
tmp=que[4]=? → uninitialized! Because que[4] was never set. We only set que[0]=0, que[1]=1, que[2]=2, que[3]=2. que[4] is garbage. Then we check visited[tmp] where tmp is garbage → likely segfault or undefined behavior. This is the runtime error.

The root cause: BFS enqueues the same node multiple times (because visited is only set on dequeue, not enqueue), leading to reading uninitialized memory in the queue when head exceeds the number of actually enqueued elements.

Thus, the error is in the BFS function: nodes should be marked as visited when enqueued, not when dequeued, to prevent duplicate enqueues.

But the question asks to mark the line with @@ where the error occurs. The problematic logic is in the BFS function where it checks `if(visited[tmp]) continue;` after dequeueing, instead of marking visited at enqueue time. However, the immediate cause of the runtime error is that the queue contains garbage because `tail` went beyond initialized values. But the line that causes the duplicate enqueue is:

                    que[tail++]=i;        //入队 

But the real fix is to mark visited when enqueuing. However, the error location per instruction is the line that leads to the problem. Since the duplicate enqueue happens here, and that causes the queue to have more elements than actual, leading to reading uninitialized memory, this line is part of the issue. But the core flaw is the placement of `visited[tmp]=1`.

Looking at the BFS code:

        if(visited[tmp])    continue;    //如果访问过 
        else
        {
            printf("%d ",tmp);        //打印出队元素 
            visited[tmp]=1;            //已访问 
            for(i=0;i<vnum;i++)
                if (matrix[tmp][i]==1&& !visited[i])    //如果矩阵元素为 1 且未访问过 
                    que[tail++]=i;        //入队 
        }

The error is that `visited[tmp]` is set only after dequeue, so multiple copies of the same node can be enqueued. The line that enqueues without marking visited is the issue. But the standard fix is to mark visited at enqueue time. So the error is in the logic of when visited is set. However, the question says: "If you think an error may occur on a particular line, add @@ symbol directly after that line".

The line that causes the duplicate enqueue is the condition `!visited[i]` in the enqueue check — but that condition is correct only if visited is set at enqueue. Since it's not, the condition passes for nodes that are already in the queue but not yet visited. So the real error is that visited is set too late. But the line where visited should be set is missing.

However, the immediate line that leads to the runtime error (reading uninitialized queue memory) is when `tmp=que[head]` for head beyond valid enqueues. But that's a consequence.

Given the instructions, the most precise error location is in the BFS function where the node is enqueued without marking it as visited, leading to duplicates. But the line that enqueues is:

                    que[tail++]=i;        //入队 

But the problem is that before this line, we don't set visited[i]=1. So the error is the absence of setting visited at enqueue. However, the question wants us to mark a line that exists. The line that checks `!visited[i]` is correct in intent but flawed in practice because visited isn't set on enqueue. But the actual bug manifests when we dequeue a node that was enqueued multiple times, and then later dequeue a garbage value.

But in the test case, after deletion, let's see:

After deletion, matrix:
row0: [0,0,1]
row1: [0,0,0]
row2: [1,0,0]

BFS(0):
que[0]=0; head=0, tail=1.
Loop: head(0)<=tail(1) → tmp=0, head=1.
visited[0]=0 → print 0, set visited[0]=1.
Then i=0: skip. i=1: matrix[0][1]=0. i=2: matrix[0][2]=1 and !visited[2] → que[1]=2, tail=2.
Now head=1, tail=2.
tmp=que[1]=2, head=2.
visited[2]=0 → print 2, set visited[2]=1.
Then for i=0: matrix[2][0]=1 but visited[0]=1 → skip. i=1: 0. i=2: skip.
Now head=2, tail=2 → loop continues.
tmp=que[2]=? → uninitialized! Because we only set que[0] and que[1]. que[2] is garbage.

So yes, the BFS function reads uninitialized memory because `tail` was incremented to 2, but the queue element at index 2 was never written (only indices 0 and 1 were written). Wait, no: when we did `que[tail++]=i`, with tail initially 1, we set que[1]=2, then tail becomes 2. So que[0]=0, que[1]=2. Then when head=1, we read que[1]=2. Then head becomes 2. Now head=2, tail=2 → condition head<=tail is true, so we read que[2], which was never assigned → garbage.

Why was tail=2? Because after enqueuing 2, tail became 2. The queue has valid elements from head=0 to tail-1=1. But the loop condition is `head <= tail`, which includes tail index, which is one past the last valid element.

The standard queue implementation uses head and tail such that elements are in [head, tail-1]. So the condition should be `head < tail`, not `head <= tail`.

Ah! That's the critical error. The loop condition should be `while(head < tail)`, not `<=`. Because tail points to the next available slot, so valid elements are while head < tail.

In the initial setup: que[0]=v, head=0, tail=1. Valid elements: head=0 < tail=1 → one element. After dequeue, head=1, then head(1) < tail(1) is false → stops. But in the current code, it's `head<=tail`, so when head=1 and tail=1, it runs, trying to read que[1] which is invalid.

So the error is in the BFS loop condition.

Therefore, the line with the error is:

    while(head<=tail)    //队列访问完毕 

This should be `head < tail`.

So we mark that line.
@@ [The loop condition should be 'head < tail' because 'tail' points to the next available slot, so valid elements are in [head, tail-1]. Using 'head <= tail' causes reading beyond the last enqueued element, leading to uninitialized memory access and runtime error.]