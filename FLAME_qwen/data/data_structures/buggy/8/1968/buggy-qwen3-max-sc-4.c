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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although standard C allows it, some environments or strict compilers might flag it. However, the actual critical error is elsewhere.]

int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` and `x - delete` is incorrect. It should be `x != f` and `x != delete`. Using subtraction as a boolean condition fails when the result is non-zero but the intent is inequality. Specifically, `x - f` is always true unless x == f, but the logic is obfuscated and error-prone. More critically, during the first traversal (before deletion), `delete` is -1, so `x - delete` becomes `x - (-1) = x+1`, which is never zero for valid vertices (0 to n-1), so it doesn't block anything — which is okay. But the real bug is in BFS.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", but the expected output format requires all four traversals each on their own line without extra newlines. The first DFS already printed its line without a trailing newline (only space-separated), then this BFS prints "\n0 ", causing misalignment. Also, the first BFS should not start with a newline. This breaks output format.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same issue: `y - x` is always non-zero since graph has no self-loops, but it's misleading. However, the bigger problem is that in BFS, after deletion, we must skip the deleted vertex. But the condition `y - delete` is equivalent to `y != delete` only if we interpret non-zero as true, which works numerically but is poor style. However, the critical flaw is that the BFS function reinitializes `visited` and prints inside the function, making it impossible to control output format consistently. Moreover, the first call to bfs() happens before reading `delete`, so `delete` is -1, which is fine, but the output starts with a newline, which is wrong.]
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
    dfs(-1, 0); bfs(); // @@ [After dfs(-1,0), the output is like "0 1 2 " (with trailing space), then bfs() prints "\n0 1 2 ", resulting in two lines: first line ends with space, second starts with newline. But expected output should have DFS on one line, BFS on next — however, the bfs() function itself prints a newline at the beginning, causing an extra blank line or misformatted output. Also, the first BFS should not have a leading newline.]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Same formatting issue: dfs prints "0 1 " (no newline), then bfs prints "\n0 1 ", so the third line starts with newline, breaking sequence. Expected output is four clean lines.]
    system("pause"); // @@ [This causes runtime issues on non-Windows systems (like Linux), where 'pause' command doesn't exist, leading to error messages or hanging. In competitive programming environments, this often causes runtime errors or unexpected output. The test environment likely runs on Linux, hence the "/bin/sh: 1: gcc: not found" might be a red herring, but actually the real issue is that the program tries to execute 'pause', which fails. However, the initial error message says "gcc: not found", which suggests compilation failed — but the actual code has no syntax error. Wait: the variable name 'delete' is a reserved word in C++ but not in C. However, some online judges use .cpp extension by default, causing compilation as C++, where 'delete' is a keyword. That would cause a compilation error. So the primary error is using 'delete' as identifier.]
    return 0;
}