#include <stdio.h>
#include <stdlib.h>
//#define INT_MAX 2147483647
//#define INT_MIN (-2147483648)

int a[111] = {0};
int q[111][111] = {0};
int N, M;

//int temp[111] = {0}, t1 = 0;
int over[111] = {0};
int num = 0;
void dfs(int t){
    over[t] = 1;
    printf("%d", t); num++;
    if(num < M) printf(" ");
    for(int i = 0; i < N; i++){
        if(q[t][i] == 1 && over[i] == 0){
            dfs(i);
        }
    }
    if(num == N){return;}
}

int que[555] = {0};
int q1 = 0, q2 = 0;
void bfs(int start){
    num = 0;
    int t = start;
    que[q2++] = t;
    over[t] = 1;
    while(q1 < q2){
        for(int i = 0; i < N; i++){
            if(q[t][i] == 1 && over[i] == 0){
                que[q2++] = i;
                over[i] = 1;
            }
        }
        num++;
        printf("%d", t);
        if(num < M) printf(" ");
        t = que[++q1];
    }
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    N = n, M = n;
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(a != b) q[a][b] = 1, q[b][a] = 1;
    }
    dfs(0); printf("\n"); memset(over, 0, sizeof(over));
    bfs(0); printf("\n"); memset(over, 0, sizeof(over));
    M--;
    {
        int a; scanf("%d", &a);
//        if(a == n-1) M--;
        for(int i = 0; i < n; i++){
            q[a][i] = 0;
            q[i][a] = 0;
        }
    }
    num = 0;
    dfs(0); printf("\n"); memset(over, 0, sizeof(over));
    bfs(0); printf("\n"); memset(over, 0, sizeof(over));
    return 0;
}

