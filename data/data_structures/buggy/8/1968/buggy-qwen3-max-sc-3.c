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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools treating it as a keyword; although standard C allows it, it's poor practice and may lead to compilation errors in strict environments. However, the main issue here is that 'delete' is a reserved word in C++, and if compiled with a C++ compiler (or certain C compilers with extensions), this causes a compilation error.]

int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition 'x - f' and 'x - delete' are used as boolean checks, but they should be 'x != f' and 'x != delete'. While 'x - f' evaluates to non-zero when x != f, which works logically, it's misleading and error-prone. However, the real critical error is using 'delete' as a variable name, which causes compilation failure in many contexts.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", which breaks the output format. The first traversal output should start immediately without a leading newline. This causes incorrect output formatting, but not a compilation error. However, the primary compilation error stems from the variable name 'delete'.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same issue: using 'y - x' instead of 'y != x' is logically equivalent but confusing; more critically, 'delete' is an invalid identifier in many compilation contexts.]
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
    dfs(-1, 0); bfs(); // @@ [The DFS prints its sequence, then BFS prints a newline followed by its sequence on the same line as the DFS output? Actually, BFS starts with "\n0 ", so the first two traversals are printed as: "<DFS> \n0 <rest of BFS>", which is two lines — acceptable. But the bigger issue remains the 'delete' variable.]
    scanf("%d", &delete); // @@ [Assigning to 'delete' — again, this variable name is problematic and likely causes the compilation error.]
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs();
    system("pause"); // @@ [This is non-standard and may cause compilation warnings or errors on non-Windows systems, but the main compilation error is due to 'delete'.]
    return 0;
}