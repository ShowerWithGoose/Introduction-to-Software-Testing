//
// Created by  on 2022/6/15.
//
#include "stdio.h"
#include "string.h"
typedef struct{
    int  weight;
}edge; //定义边节点类型

int G[100][100]; //邻接矩阵
int size;
char visited[100];
void DFS(int x); //深度优先算法
void BFS(int x); //广度优先算法
void visit(int x); //访问函数
int verLen, edgeLen, max;
int stack[100], stackSize, stackNow;
int main(){

    scanf("%d %d", &verLen, &edgeLen);
    int tmp1, tmp2;
    for(int i = 0; i < edgeLen; i++){
        scanf("%d %d", &tmp1, &tmp2);
        if(tmp1 > max) max = tmp1;
        if(tmp2 > max) max = tmp2;
        G[tmp1][tmp2] = 1; G[tmp2][tmp1] = 1;
    }
    DFS(0); putchar('\n');
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    BFS(0); putchar('\n');
    memset(visited, 0, sizeof(visited));
    memset(stack, 0, sizeof(stack)); stackSize = 0;
    scanf("%d", &tmp1);
    for(int i = 0; i < verLen; i++){
        if(G[tmp1][i]){
            G[tmp1][i] = 0;
            G[i][tmp1] = 0;
            edgeLen--;
        }
    }
    verLen--;
    //printf("删除第%d个结点\n", tmp1);
    //printf("verLen = %d, edgeLen = %d\n", verLen, edgeLen);
    DFS(0); putchar('\n');
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    BFS(0); putchar('\n');
    return 0;
}

void DFS(int x){
    visit(x);
    visited[x] = 1;
    for(int i = 0; i <= max; i++){
        if(G[x][i]){
            if(visited[i] == 0){
                DFS(i);
            }
        }
    }
}

void BFS(int x){
    if(x >= verLen) return;
    for(int i = 0; i <= max; i++){
        if(G[stack[x]][i]){
            if(visited[i] == 0){
                stack[++stackSize] = i;
                visited[i] = 1;
            }
        }
    }
    visit(stack[x]);
    BFS(x+1);
}

void visit(int x){
    printf("%d ", x);
}
