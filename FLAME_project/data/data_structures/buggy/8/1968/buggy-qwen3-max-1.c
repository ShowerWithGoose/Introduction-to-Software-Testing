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
        if (!visited[x] && x - f && x - delete) {
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [The BFS function prints a newline and "0 " at the start, which causes incorrect formatting. It should not print anything before processing the queue properly, and the initial print breaks the expected output format.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [The condition `y - x` is always true for distinct vertices and is meaningless; it should be removed. The real issue is that this condition may accidentally filter out valid neighbors when y == x (which shouldn't happen), but more critically, the logic for skipping the deleted vertex is flawed because `y - delete` evaluates to non-zero even when y equals delete (it should be `y != delete`). However, note: in C, `y - delete` is non-zero when y != delete, so it's logically equivalent—but unconventional and error-prone. The bigger issue is in DFS similarly. But the main bug is in output formatting and traversal logic.]
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
    dfs(-1, 0); bfs(); // @@ [The first call to bfs() prints a newline at the beginning of its output, causing the first BFS line to start with '\n', which results in an extra blank line or misaligned output. Also, the DFS does not print a newline after its output, so the BFS output starts on the same line. This leads to the observed buggy output "0 1 2 \n0 1 2 0 2".]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Same issues as above: missing newline after DFS, and BFS printing its own newline and leading space, causing malformed output.]
    system("pause");
    return 0;
}