#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int map[1000][1000];
int visit[1000];
int n;
int m;
void DFS(int k){
    printf("%d ", k);
    for(int i = 1; i < n; i++){
        if(map[k][i] && !visit[i]){
            visit[i] = 1;
            DFS(i);
        }
    }
}
int queue[1000];
int tail = -1;
int head;
void BFS(){
    queue[++tail] = 0;
    printf("0 ");
    visit[0] = 1;
    while(tail >= head){
        for(int i = 1; i < n; i++){
            if(map[queue[head]][i] && !visit[i]){
                visit[i] = 1;
                printf("%d ", i);
                queue[++tail] = i;
            }
        }
        head++;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    while(m--){
        int a;
        int b;
        scanf("%d%d", &a, &b);
        map[a][b] = map[b][a] = 1;
    }
    visit[0] = 1;
    DFS(0);
    putchar('\n');
    memset(visit, 0, sizeof(visit));
    BFS();
    putchar('\n');
    memset(visit, 0, sizeof(visit));
    int x;
    scanf("%d", &x);
    for(int i = 0; i < n; i++) map[i][x] = map[x][i] = 0;
    visit[0] = 1;
    DFS(0);
    putchar('\n');
    memset(visit, 0, sizeof(visit));
    BFS();
    putchar('\n');
    memset(visit, 0, sizeof(visit));
    return 0;
}
