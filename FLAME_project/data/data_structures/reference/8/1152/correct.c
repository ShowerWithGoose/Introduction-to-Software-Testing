#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LL long long

int G[111][111];//1 == road;

typedef struct lists{
    struct lists *next;
    int num;
}list;

typedef struct queues{
    list *front;
    list *back;
    int size;
}queue;

void push(queue* q, int num){
    list *temp = (list*)malloc(sizeof(list));
    temp->num = num;
    temp->next = NULL;
    if(q->back != NULL){
        q->back->next = temp;
        q->back = temp;
    }else{
        q->front = temp;
        q->back = temp;
    }
    ++(q->size);
}

void pop(queue* q){
    list *hold = q->front;
    q->front = q->front->next;
    free(hold);
    --(q->size);
}

void dfs(int n, int num,int flag[]){
    if(n == 0){
        printf("0");
    }else{
        printf(" %d", n);
    }
    flag[n] = 1;
    for(int i = 0; i < num; ++i){
        if(flag[i] == 1) continue;
        if(G[n][i] == 1) {
            dfs(i, num, flag);
        }
    }
}

void bfs(int n, int num, int flag[]){
    flag[n] = 1;
    printf("%d", n);
    queue* q = (queue*)malloc(sizeof(queue));
    q->back = NULL;
    q->front = NULL;
    q->size = 0;
    push(q, n);
    while(q->size > 0){
        for(int i = 0; i < num; ++i){
            if(flag[i] == 1) continue;
            if(G[q->front->num][i] == 1){
                flag[i] = 1;
                push(q, i);
            }
        }
        if(q->front->num != 0) printf(" %d", q->front->num);
        pop(q);
    }
}


int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    int n,r;
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= r; ++i){
        int a,b;
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }
    scanf("%d", &r);
    int flag[111];
    memset(flag, 0, sizeof(flag));

    dfs(0, n, flag);
    putchar('\n');
    memset(flag, 0, sizeof(flag));

    bfs(0, n, flag);
    putchar('\n');
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i < n; ++i){
        G[i][r] = 0;
        G[r][i] = 0;
    }

    dfs(0, n, flag);
    putchar('\n');
    memset(flag, 0, sizeof(flag));

    bfs(0, n, flag);
    putchar('\n');
    memset(flag, 0, sizeof(flag));

    return 0;
}
