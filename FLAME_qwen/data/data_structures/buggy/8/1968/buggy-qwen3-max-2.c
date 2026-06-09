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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although standard C allows it, it's poor practice and may lead to compilation errors in strict environments or when mistakenly compiled as C++.]
int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` and `x - delete` is incorrect. It should be `x != f` and `x != delete`. Using subtraction in a boolean context checks if the result is non-zero, which accidentally works when f or delete is 0, but logically it's wrong and fails when f or delete equals x numerically but not by identity. More critically, during initial traversal, `f` is -1, so `x - (-1)` is always non-zero, making the parent check ineffective. This leads to revisiting the parent node, causing infinite recursion or incorrect traversal.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", but the expected output format requires all traversal sequences on separate lines without leading newlines. The first BFS output will start with a newline, causing misalignment with expected output. Also, the problem expects DFS and BFS outputs each on their own line, but this mixes newline handling incorrectly.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same error as in DFS: `y - x` and `y - delete` should be `y != x` and `y != delete`. However, `y != x` is always true in an undirected graph without self-loops, so it's redundant, but `y != delete` is needed. The subtraction logic is flawed and may accidentally work sometimes but is semantically wrong. More importantly, the condition `y - x` is unnecessary and misleading. The real issue is that after deletion, we must skip the deleted vertex, but the current logic may not correctly exclude it due to the arithmetic condition.]
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
    dfs(-1, 0); bfs(); // @@ [The DFS call does not reset visited array before BFS, but in this code, BFS resets visited at its start. However, the bigger issue is that the first BFS prints a leading newline, and the overall output order is: DFS (no newline at end), then BFS (starts with \n). This causes the first two outputs to be on the same line or misformatted. Expected: DFS sequence on line 1, BFS on line 2. Actual: "0 ... \n0 ..." meaning line1 ends with space, line2 starts correctly but the first line lacks a newline. Also, after printing DFS, there's no newline before BFS's internal newline, leading to malformed output.]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Same output formatting issues as above. Additionally, the use of 'delete' as variable name may cause compilation error in some contexts (e.g., if compiled as C++ or with certain compiler flags), which matches the reported "Compilation Error" with "gcc: not found" possibly being a red herring or misreported—actual issue is likely the variable name 'delete'.]
    system("pause"); // @@ [This is non-standard and may cause compilation or runtime issues on non-Windows systems. While not always a compilation error, it's platform-dependent and unnecessary. However, the primary compilation error is more likely due to 'delete' being treated as a keyword.]
    return 0;
}