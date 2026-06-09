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
            if((i==del)||(j==del)) matrix[i][j]=0;
        }
    }
    memset(visited,0,sizeof(visited));
    dfs(0,Vnum);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0,Vnum);
    printf("\n"); // @@ [The problem expects no extra newline at the end of output, but this adds a final newline. However, the actual error is not compilation but logic/output format. But since the reported error type is "Compilation Error" and the test shows "/bin/sh: 1: gcc: not found", there is actually NO compilation error in the code. The real issue is likely environment-related. However, per instructions, we must find logical/semantic errors causing wrong output.]

    // BUT WAIT: The true logical error is in BFS implementation: it initializes tail=1 and sets que[head]=v with head=0, but never marks v as visited before the loop, and relies on checking visited[tmp] inside. This causes potential re-enqueueing of nodes and incorrect order because adjacent nodes may be enqueued multiple times before being marked visited.

    // Also, DFS and BFS must visit neighbors in ascending order — current DFS does, but BFS loops from 0 to vnum-1, which is ascending, so that's OK.

    // However, the critical error is in BFS: the starting node 'v' is placed in queue but not marked visited. Then, when popped, it's marked visited and printed. That’s acceptable. BUT: during expansion, unvisited neighbors are enqueued without marking them visited immediately, which can cause duplicates in queue.

    // Example: A-B-C. Start at A. Queue: [A]. Pop A → mark visited, enqueue B. Queue: [B]. Then pop B → mark visited, enqueue A (already visited, skipped) and C. OK. But consider triangle A-B, A-C, B-C. Start A. Queue=[A]. Pop A → print A, enqueue B, C. Queue=[B,C]. Pop B → print B, check A (visited), C (not visited) → enqueue C again! Now queue=[C,C]. Then pop first C → print C, enqueue A,B (both visited). Then pop second C → already visited → skip. So output: A B C C → WRONG.

    // Therefore, BFS must mark nodes as visited WHEN ENQUEUED, not when dequeued.

    // So error is in BFS: visited[tmp] is set only after dequeue, allowing duplicates.

    // Fix: mark visited when enqueuing.

    // Thus, the line:
    //     que[tail++]=i;
    // should be preceded by visited[i]=1;

    // But according to instruction, we must annotate the line where error occurs.

    // The problematic section is inside bfs function:

    // Specifically, the line:
    //     que[tail++]=i;
    // is missing a visited[i]=1; before or with it.

    // However, per instruction, we add @@ after the line that is erroneous.

    // But note: the line itself isn't syntactically wrong, but the logic is flawed due to missing visited marking at enqueue time.

    // Since the error manifests in BFS producing duplicate visits or wrong order, and the root cause is not marking visited upon enqueue, the line that enqueues without marking is the culprit.

    // But the instruction says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

    // So we annotate the line: que[tail++]=i;

    // However, looking back, the user said "Error type: Compilation Error", but the test output shows "gcc: not found", which is not a code error. But the actual program has logical errors causing wrong output.

    // Given the discrepancy, but following the task: identify location of errors that cause failure on test cases.

    // The BFS implementation is flawed.

    // Therefore, in the bfs function, the line:
    //     que[tail++]=i;
    // is where the error occurs because it fails to mark the node as visited upon enqueue, leading to possible duplicate entries.

    // So we annotate that line.

    // Also, note: the initial call to bfs(0,Vnum) uses global visited array, which was zeroed before, so that's fine.

    // Another issue: in main(), after deleting vertex 'del', the code zeros entire row and column for 'del'. That is correct.

    // But what if Vnum is 5 and del=3? It zeros matrix[i][3] and matrix[3][j] for all i,j in [0, Vnum). Correct.

    // So only BFS logic is flawed.

    // Annotate the enqueue line in bfs.
    return 0;
}