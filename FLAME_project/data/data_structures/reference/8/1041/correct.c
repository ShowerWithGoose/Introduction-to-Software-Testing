#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct SSSSSS{
    int id,cnt,alive;
    struct SSSSSS *p[100];
}NODE;

NODE *list[101];

NODE *new_r(int id){
    NODE *x = (NODE *)calloc(1, sizeof(NODE));
    x->id = id;
    x->cnt = 0;
    x->alive = 1;
    return x;
}

void link(NODE *a, NODE *b){
    a->p[a->cnt++] = b;
    b->p[b->cnt++] = a;
    return;
}

int vis[101];

void dfs(NODE *u){
    printf("%d ", u->id);
    for (int id = 0; id < 99; id++){
        for (int i = 0; i < u->cnt; i++){
            if (u->p[i]->id != id)continue;
            if (!vis[u->p[i]->id] && u->p[i]->alive){
                vis[u->p[i]->id] = 1;
                dfs(u->p[i]);
            }
        }
    }
}

void bfs(NODE *u){
    NODE *queue[101]; int s = 0, e = 0;
    queue[0] = u;
    vis[u->id] = 1;
    while (s <= e){
        u = queue[s++];
        printf("%d ", u->id);
        for (int id = 0; id < 99; id++){
        for (int i = 0; i < u->cnt; i++){
            if (u->p[i]->id != id)continue;
            if (!vis[u->p[i]->id] && u->p[i]->alive){
                vis[u->p[i]->id] = 1;
                queue[++e] = u->p[i];
            }
        }
        }
    }
}

int main(){
#ifdef VSCODE
    freopen("input.in","r",stdin);
#endif
    int N,E;
    scanf("%d%d", &N, &E);
    for (int i = 0; i < N; i++){
        list[i] = new_r(i);
    }
    for (int i = 0; i < E; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        link(list[x], list[y]);
    }
    scanf("%d", &E);
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    dfs(list[0]);putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs(list[0]);putchar('\n');
    list[E]->alive = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    dfs(list[0]);putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs(list[0]);putchar('\n');
    return 0;
}
