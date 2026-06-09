#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10007
#define N 107
#define INF 0x3f3f3f3f
#define ll long long
#define db double
int map[N][N];
int book[N], flag[N][N];
int n, m, k;
void dfs(int step) {
    if (!book[step]) {
        book[step] = 1;
        printf("%d ", step);
    }
    for (int i = 0; i < n; i++) {
        if (map[step][i] == 1 && !book[i]) {
            // flag[step][i] = 1, flag[i][step] = 1;
            dfs(i);
            // flag[step][i] = 0, flag[i][step] = 0;
        }
    }
}
void bfs() {
    int que[N] = {0};
    int head = 0, tail = 1;
    while (head < tail) {
        for (int i = 0; i < n; i++) {
            if (map[que[head]][i] == 1 && flag[que[head]][i] == 0) {
                flag[que[head]][i] = 1, flag[i][que[head]] = 1;
                if (!book[i]) {
                    que[tail++] = i;
                    book[i] = 1;
                }
            }
        }
        printf("%d ", que[head]);
        head++;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    dfs(0);
    puts("");
    memset(flag, 0, sizeof(flag));
    memset(book, 0, sizeof(book));
    bfs();
    puts("");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        map[i][k] = 0, map[k][i] = 0;
    }
    memset(flag, 0, sizeof(flag));
    memset(book, 0, sizeof(book));
    dfs(0);
    puts("");
    memset(flag, 0, sizeof(flag));
    memset(book, 0, sizeof(book));
    bfs();
    puts("");
    return 0;
}
// 9 10
// 0 1
// 0 2
// 1 4
// 1 3
// 1 8
// 8 6
// 3 6
// 7 2
// 7 5
// 5 2
// 3

