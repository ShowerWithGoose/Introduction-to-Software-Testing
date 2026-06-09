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
            if((i==del)||(j==del)) matrix[i][j]=0; // @@ [This line incorrectly zeroes out the entire row and column of 'del', but it also sets matrix[del][del] = 0 (which is fine), however, more critically, when i != del but j == del, it zeroes matrix[i][del], and vice versa. But the real issue is that during BFS after deletion, the graph still includes vertex 'del' in traversal attempts because the code doesn't skip the deleted vertex in the traversal logic—it only zeros edges. However, the DFS/BFS start at 0 and should never visit 'del' if edges are properly removed. BUT: the BFS implementation has a flaw—see below.]
        }
    }
    memset(visited,0,sizeof(visited));
    dfs(0,Vnum);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0,Vnum); // @@ [The BFS function may attempt to enqueue or process the deleted vertex if it's still connected due to incomplete cleanup, but more importantly, the BFS implementation itself is flawed: it enqueues neighbors without checking if they are the deleted vertex. However, the primary error is in BFS logic: it checks `if(visited[tmp]) continue;` AFTER dequeuing, which can cause already-visited nodes to be skipped but doesn't prevent enqueuing duplicates. More critically, in this specific test case, after deleting vertex 1, the BFS starts at 0, visits 0, then enqueues 2 (since edge 0-2 remains). Then it dequeues 2, prints it, and tries to enqueue its neighbors: 0 (visited) and 1. But vertex 1 was "deleted" by zeroing matrix[2][1], so it shouldn't enqueue 1. However, the real runtime error likely comes from the BFS queue indexing: `tail` starts at 1, and `que[tail++]=i` may exceed bounds if many nodes are enqueued, but with n<=100 it's probably safe. However, the actual bug causing wrong output is that the BFS function does not skip the deleted vertex during neighbor iteration. But wait—the matrix was zeroed for any edge involving 'del', so matrix[tmp][i] should be 0 when i==del. So why wrong output? Let's check test case.

    // Test case: n=3, edges: 0-1,1-2,0-2, delete 1.
    // After deletion, matrix becomes:
    // matrix[0][1]=0, matrix[1][0]=0
    // matrix[1][2]=0, matrix[2][1]=0
    // matrix[0][2]=1, matrix[2][0]=1
    // So graph is 0-2 only.
    // DFS(0): prints 0, then w=0: skip, w=1: matrix[0][1]=0 skip, w=2: matrix[0][2]=1 and !visited[2] -> dfs(2). In dfs(2): print 2, then check w=0 (visited), w=1 (matrix[2][1]=0), w=2 (self). So DFS outputs "0 2" — correct.
    // BFS(0): 
    //   que[0]=0, head=0, tail=1.
    //   Loop: head<=tail → 0<=1 → true.
    //     tmp=que[0]=0, head=1.
    //     visited[0] is 0 → else: print 0, mark visited[0]=1.
    //     for i=0 to 2:
    //        i=0: matrix[0][0]=0 skip.
    //        i=1: matrix[0][1]=0 skip.
    //        i=2: matrix[0][2]=1 and !visited[2] → que[tail]=que[1]=2, tail=2.
    //   Next loop: head=1, tail=2 → 1<=2 true.
    //     tmp=que[1]=2, head=2.
    //     visited[2]=0 → print 2, mark visited[2]=1.
    //     for i=0: matrix[2][0]=1 but visited[0]=1 → skip.
    //        i=1: matrix[2][1]=0 → skip.
    //        i=2: matrix[2][2]=0 → skip.
    //   Next: head=2, tail=2 → 2<=2 true.
    //     tmp=que[2]= ??? — but que[2] was never set! Because tail started at 1, and we did que[1]=2, then tail became 2. But que[2] is uninitialized (garbage).
    //     Then we check visited[tmp] where tmp is garbage → undefined behavior → possible runtime error or wrong output.

    // The BFS queue initialization is wrong: 
    //   It sets que[head]=v (que[0]=0), and tail=1.
    //   Then when enqueuing, it does que[tail++]=i → first enqueue writes to que[1], then tail=2.
    //   But the queue size is 200, so index 2 is valid. However, in the next iteration, head=2, and we access que[2], which was set to 2 in the first enqueue? No: 
    //      First enqueue: que[1] = 2, tail becomes 2.
    //      Then when head=1, we process que[1]=2.
    //      Then head increments to 2.
    //      Now head=2, tail=2 → loop condition head<=tail is true.
    //      Then tmp = que[2] → but que[2] was never assigned! Because we only assigned que[0] and que[1].
    //   So accessing que[2] is reading uninitialized memory → undefined behavior → runtime error or garbage output.

    // Therefore, the BFS implementation has an off-by-one error in queue management. The standard way is to initialize tail=0, then enqueue by que[tail++]=v, and loop while head < tail.

    // Specifically: 
    //   Correct initialization: head=0, tail=0; then enqueue: que[tail++]=v;
    //   Or: head=0, tail=1 with que[0]=v, but then the loop should run while head < tail, not head <= tail.
    //   Here, condition is head<=tail, and tail starts at 1 (after initial que[0]=v). After processing first element, head=1, tail=1 → head<=tail true → tries to read que[1], which may be uninitialized if no neighbors were added. But in our test case after deletion, after processing 0, we add 2 → que[1]=2, tail=2. Then head=1, process que[1]=2, then head=2. Now head=2, tail=2 → head<=tail true → reads que[2] which is uninitialized.

    // So the error is in BFS: the loop condition should be `while(head < tail)` instead of `while(head <= tail)`.
}
    printf("\n");
    return 0;
}