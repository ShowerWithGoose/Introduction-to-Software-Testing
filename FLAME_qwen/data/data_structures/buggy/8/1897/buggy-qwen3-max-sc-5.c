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
    printf("\n"); // @@ [The problem states that the output should have exactly four lines: DFS before, BFS before, DFS after, BFS after. This extra newline at the end produces a fifth empty line, which may cause presentation error in strict judges. However, the reported error is "Compilation Error", which contradicts this. But note: the actual compilation error in the test environment was "/bin/sh: 1: gcc: not found", which is NOT a code error—it's an environment issue. Yet the instruction says to treat it as a code error. Given the discrepancy, and since both programs compile fine locally, the real issue must be elsewhere. However, comparing with the reference program, the bug is actually in BFS logic: the queue is initialized with tail=1 but only que[0] is set, and que[1] is uninitialized. Also, the BFS visits nodes in arbitrary order because it doesn't enforce ascending order when enqueueing neighbors. The problem requires visiting adjacent vertices in ascending order. In BFS, the loop `for(i=0;i<vnum;i++)` does traverse in ascending order, so that's okay. But the bigger issue: the queue size and initialization. `tail=1` and `que[head]=v` sets index 0, then in the loop, when processing neighbors, they are added starting at `que[tail++]` which is que[1], que[2], etc. That seems okay. However, the real critical error is that in the BFS function, the initial state has `tail=1`, but the queue only has one element at index 0. The condition `while(head<=tail)` will run for head=0,1,...,tail. But when head becomes 1, tail might still be 1, so it runs again even if there's no second element. Worse: the element at que[1] was never initialized! So when head=1, tmp=que[1] is garbage. This causes undefined behavior, possibly crash or wrong output. The correct initialization should be `tail=0; que[tail++]=v;` or `head=0; tail=0; que[tail++]=v;`. So the error is in BFS initialization.]
    return 0;
}