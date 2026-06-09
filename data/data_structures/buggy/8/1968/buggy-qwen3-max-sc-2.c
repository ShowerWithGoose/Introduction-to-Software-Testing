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

int delete = -1; // @@ [Using 'delete' as an identifier is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although technically allowed in pure C, it's poor practice and can lead to portability or preprocessing issues. However, the actual compilation error here is likely due to missing headers or environment, but based on code logic and common pitfalls, this is a problematic identifier.]
int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` and `x - delete` are used as boolean checks, but they should be `x != f` and `x != delete`. Using subtraction can give non-zero values even when logically equal (though unlikely here), but more critically, when `delete` is the vertex to remove, this condition fails to exclude it properly because `x - delete` is non-zero when x != delete, which is correct—but the real issue is that during the first traversal (before deletion), `delete` is still -1, so `x - (-1)` is always non-zero, which is okay. However, the bigger problem is in BFS.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", but the expected output format requires all four traversals each on their own line without extra newlines. The first DFS already printed its line without a trailing newline (only space-separated), then BFS starts with "\n0 ", which introduces an extra newline between DFS and BFS outputs. This breaks the output format. Also, BFS should not print anything before processing the queue properly.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same issue as in DFS: using `y - x` instead of `y != x`. But since the graph has no self-loops, `y != x` is always true, so this is redundant. However, the real bug is that `y - delete` is used to skip the deleted vertex, but during the first BFS call (before reading `delete`), `delete` is -1, so it works. But the main issue is the output format and the fact that BFS prints "0 " immediately upon enqueueing, which duplicates the starting vertex handling and causes formatting issues. Also, the condition `y - x` is unnecessary and misleading.]
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
    dfs(-1, 0); bfs(); // @@ [After dfs(-1,0), there's no newline printed, but bfs() starts by printing "\n0 ", which adds a newline before the BFS output. This causes the first two outputs (DFS and BFS before deletion) to be on separate lines, which is correct, BUT the DFS output ends with a space and no newline, then BFS prints a newline then "0 ...", so overall format might be acceptable. However, the bigger issue is that after the first BFS, the program reads `delete`, then runs dfs and bfs again. But note: the first call to bfs() uses `delete = -1`, which is fine. However, the output of bfs() includes a leading newline, which means the very first output (DFS) is on line 1, then BFS starts with \n so it's on line 2 — that's okay. But the real critical error is below:]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Here, after deleting the vertex, we run dfs and bfs again. However, the bfs() function resets visited[] at the start, which is good, but the dfs() does NOT reset visited[] before being called! Wait — actually, the code does `memset(visited, 0, ...)` right before dfs(-1,0), so that's okay. But the main issue is that in both dfs and bfs, the condition to skip the deleted vertex is `x - delete` (i.e., `x != delete` implicitly), which is correct. However, the BFS function has a fundamental flaw: it prints "0 " immediately upon starting, but what if vertex 0 is connected to the deleted vertex? That's okay because 0 is never deleted (per problem statement). But the real showstopper is:]
    system("pause"); // @@ [This line causes a compilation or runtime issue in non-Windows environments, and may be the source of the "/bin/sh: 1: gcc: not found" error indirectly if the environment doesn't support it. However, the primary logical errors are in traversal logic and output format. But note: the problem says the buggy output is "/bin/sh: 1: gcc: not found", which suggests the code didn't even compile — possibly because `delete` is a reserved word in C++ and if compiled as C++, it fails. Since the file extension or compiler isn't specified, using `delete` as a variable name is dangerous and likely causes a compilation error in many setups. This is the most probable cause of the compilation error.]
    return 0;
}