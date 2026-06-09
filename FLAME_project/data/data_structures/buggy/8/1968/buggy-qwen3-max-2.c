#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N (105)
//#define qs (qr - ql + 1)

int cmp(const void *x, const void *y) {
    int *a = (int *)x, *b = (int *)y;
    return *a - *b;
}

typedef struct vertex {
    int n[N], nn;
} vert;
vert v[N];

int delete = -1;
int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` is incorrect. It should allow revisiting parent only to avoid immediate backtracking, but using subtraction as boolean is error-prone and wrong here. Also, `x - delete` evaluates to true even when x == delete (if delete != 0), which is not the intended logic. The correct check should be `x != delete`.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline and "0 " at the start of BFS, which causes the first BFS output to appear on a new line after DFS, but the expected output requires both DFS and BFS before deletion to be on separate lines without extra newlines at the start of BFS. Also, this hardcoded print breaks consistency with how DFS prints.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same issue as in DFS: `y - x` and `y - delete` are incorrect boolean conditions. Should be `y != delete` and no need to exclude `y == x` since graph has no self-loops. The `y - x` condition may incorrectly skip valid neighbors.]
                q[++qr] = y; printf("%d ", y); visited[y] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].n[v[x].nn++] = y;
        v[y].n[v[y].nn++] = x;
    }
    for (int i = 0; i < n; ++i)
        qsort(v[i].n, v[i].nn, sizeof(int), cmp);
    dfs(-1, 0); bfs(); // @@ [Calling bfs() immediately after dfs() without resetting visited array causes BFS to see visited nodes from DFS, leading to incorrect traversal. Also, bfs() itself resets visited, but it prints "\n0 " unconditionally, causing formatting issues.]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Same issues as above: bfs() resets visited again but prints extra newline and "0 ", and uses incorrect neighbor conditions. Additionally, after deletion, the graph structure isn't actually modified—only skipped via condition, but the condition is flawed.]
    system("pause"); // @@ [This line is non-standard and unnecessary; may cause issues in automated judging environments, though not directly causing WA in this case.]
    return 0;
}