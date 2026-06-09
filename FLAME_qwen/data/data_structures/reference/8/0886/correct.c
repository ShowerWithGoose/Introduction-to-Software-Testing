//
//  main.c
//  图遍历（基本题）
//
//  Created by  on 2022/5/17.
//

#include <stdio.h>
#include <string.h>
int visited[105]={0}, judge=1, a[105][105]={0}, queue[105]={0};
void DFS(int num, int d){
    int i;
    if(judge<num){
        printf("%d ", d);
        judge++;
    }
    else
        printf("%d\n", d);
    visited[d]=1;
    for(i=1;i<=num;i++){
        if(a[d][i]==1&&visited[i]==0)
            DFS(num,i);
    }
}
void BFS(int num, int d){
    int i, j, k, v;
    queue[1] = d;
    for(j=1,k=1;j<=k;){
        v=queue[j++];
        if(visited[v] == 1)
            continue;
        if(judge < num){
            printf("%d ", v);
            judge++;
        }
        else
            printf("%d\n", v);
        visited[v] = 1;
        for(i=1;i<=num;i++){
            if(a[v][i]==1&&visited[i]==0)
                queue[++k] = i;
        }
    }
}
int main(){
    int i, ding_num, bian_num, x, y, delete;
    scanf("%d %d", &ding_num, &bian_num);
    for(i=1;i<=bian_num;i++){
        scanf("%d %d", &x, &y);
        a[x][y]=1;
        a[y][x]=1;
    }
    scanf("%d", &delete);
    DFS(ding_num,0);
    memset(visited,0,sizeof(visited));
    judge=1;
    BFS(ding_num,0);
    memset(visited,0,sizeof(visited));
    judge=1;
    visited[delete]=1;
    DFS(ding_num-1,0);
    memset(visited,0,sizeof(visited));
    judge=1;
    visited[delete]=1;
    BFS(ding_num-1,0);
    return 0;
}

