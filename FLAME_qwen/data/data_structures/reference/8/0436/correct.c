#include<stdio.h>

int m[105][105]={{0}};

void bfs(){
    int i,j,flag=0;
    int q[105], front=-1, rear=-1;
    int visit[105]={0};
    for(i=0; i<100; i++){
        for(j=0; j<100 && !visit[i]; j++){
            if(m[i][j]){
                flag = 1;
                q[++rear] = j;
                // printf("get i,j : ( %d , %d)\n", i, j);
            }
        }
        if(flag){
            visit[i] = 1;
            printf("%d ", i);
            flag = 0;
        }
        if(front<rear)
            i = q[++front]-1;
    }
    printf("\n");
}

void dfs(){
    int i,j,flag=0;
    int stack[105], top=-1;
    int visit[105]={0};
    for(i=0; i<100; i++){
        for(j=100; j>=0 && !visit[i]; j--){
            if(m[i][j]){
                flag = 1;
                stack[++top] = j;
                // printf("get i,j : ( %d , %d)\n", i, j);
            }
        }
        if(flag){
            printf("%d ", i);
            visit[i] = 1;
            flag = 0;
        }
        if(top>-1)
            i = stack[top--]-1;
    }
    printf("\n");
}

void delete(int del){
    int i;
    for(i=0; i<100; i++){
        m[i][del] = m[del][i] = 0;
    }
}

int main(){
    int i, ver, edg, a, b, del;
    scanf("%d %d", &ver, &edg);
    for(i=0; i<edg; i++){
        scanf("%d %d", &a, &b);
        m[a][b] = m[b][a] = 1;
    }
    scanf("%d", &del);
    dfs();
    bfs();
    delete(del);
    dfs();
    bfs();
    return 0;
}
