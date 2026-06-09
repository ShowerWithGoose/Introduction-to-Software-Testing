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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although technically allowed in pure C, it's poor practice and can lead to portability or preprocessing issues. However, the actual compilation error likely stems from another issue.]

int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` and `x - delete` is incorrect. It should be `x != f` and `x != delete`. Using subtraction in a boolean context checks if the result is non-zero, which accidentally works when f or delete equals x only if they are equal, but it's logically wrong and misleading. More critically, during the first traversal (before deletion), `delete` is -1, so `x - delete` becomes `x - (-1) = x+1`, which is always non-zero for x>=0, so it doesn't block the deleted vertex properly later. But the main bug is using arithmetic instead of comparison.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", but the expected output format requires all DFS/BFS sequences on separate lines without extra newlines at the start. The first DFS already printed its line, then BFS starts with "\n0 ", causing an extra blank line or misaligned output. Also, the BFS should not print inside the queue logic like this—it breaks modularity and causes formatting errors.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same error as in DFS: using `y - x` and `y - delete` instead of `y != x` and `y != delete`. Also, `y - x` is always non-zero because there are no self-loops, so it's redundant but harmless; however, `y - delete` fails to exclude the deleted vertex correctly when `delete` is set, because it evaluates to true even when y == delete (e.g., if delete=2 and y=2, then 2-2=0 → false, so it actually works by accident here). Wait—this might work numerically, but it's still bad style. However, the real issue is that in BFS, the initial print includes a leading newline, breaking output format.]
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
    dfs(-1, 0); bfs(); // @@ [Calling bfs() immediately after dfs() causes the BFS output to start with a newline (from inside bfs()), resulting in: "0 1 2 \n\n0 1 2 " etc., which mismatches expected output format. The problem requires: DFS-before, BFS-before, DFS-after, BFS-after — each on its own line. But here, dfs() prints "0 1 2 " (no newline at end), then bfs() prints "\n0 ...", so together it's "0 1 2 \n0 ...", which may look correct, but note: dfs() does not end with newline, and bfs() starts with newline — so first line is incomplete. Actually, dfs() ends with space and no newline, then bfs() prints "\n0 ", so output becomes: "0 1 2 \n0 1 2 \n...", which is two lines — acceptable? But the bigger issue is that after deletion, same thing happens. However, the compilation error mentioned in test case ("gcc: not found") is environmental, but the actual program has logical errors causing wrong output. But the prompt says "Error type: Compilation Error", yet the given source compiles in C. So perhaps the real issue is the variable name 'delete'. In some build environments or with certain flags, 'delete' may be treated as a keyword (especially if compiled as C++), causing a compilation error. Hence, the primary error is using 'delete' as an identifier.]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs();
    system("pause"); // @@ [system("pause") is non-portable and may cause issues in non-Windows environments, but doesn't cause compilation error. However, the main compilation risk is the variable name 'delete'.]
    return 0;
}