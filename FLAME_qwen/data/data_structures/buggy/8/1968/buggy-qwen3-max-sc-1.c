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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although standard C allows it, some environments or strict compilers might flag it. However, the actual compilation error here is likely due to the use of 'system("pause");' without including <stdlib.h> properly or running in an environment without gcc. But more critically, the BFS function prints a newline before "0 ", which breaks output format, and DFS/BFS logic incorrectly uses 'x - f' and 'x - delete' instead of 'x != f' and 'x != delete'. However, the immediate cause of the reported error "/bin/sh: 1: gcc: not found" is environmental, but since we must find code errors causing logical/output mismatches, the real bugs are logical. Yet the instruction says "Compilation Error", so the only plausible code-related compilation issue is the variable name 'delete' if compiled as C++ or under strict settings. But given the context, the main logical errors are in traversal conditions. However, per instructions, we mark lines with potential errors.]

void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [This condition 'x - f' and 'x - delete' is incorrect. It should be 'x != f' and 'x != delete'. Using subtraction as a boolean condition fails when the difference is non-zero but the intent is inequality. For example, if f=2 and x=3, x-f=1 (true), which is okay, but if f=0 and x=0, x-f=0 (false), which is correct. However, the bigger issue is that 'f' is the parent to avoid going back, but the condition should be 'x != f', not 'x - f'. Similarly, 'x - delete' should be 'x != delete'. This causes wrong traversal when the deleted vertex is adjacent.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before the BFS sequence, which breaks the output format. The problem expects each traversal on its own line, but this adds an extra newline at the start of BFS output, causing misalignment with expected output. Also, BFS should not print anything before the first number.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same error as in DFS: 'y - x' and 'y - delete' should be 'y != x' and 'y != delete'. Also, 'y != x' is always true in an undirected graph without self-loops, but the real check needed is just 'y != delete'. The 'y - x' part is redundant and incorrect logic.]
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
    dfs(-1, 0); bfs();
    scanf("%d", &delete); // @@ [Assigning to 'delete' variable which may be problematic as noted earlier, but more importantly, after reading 'delete', the visited array is reset, but the BFS function itself resets visited again, causing inconsistency. Also, the initial traversals (before deletion) are printed without proper separation: DFS prints its line, then BFS prints "\n0 ...", so together they look like "0 1 2 \n0 1 2", which is two lines, but the problem expects four lines total (DFS before, BFS before, DFS after, BFS after). However, the current code prints DFS (no newline at end due to space), then BFS prints a newline then "0 ...", so output becomes: "0 1 2 \n0 1 2\n...", which is three lines for first two traversals? Actually, dfs() doesn't end with newline, then bfs() starts with "\n0 ", so combined: "0 1 2 \n0 1 2 ...", which is two lines, but then after deletion, same pattern. So total output is two lines? But expected is four lines. So missing newlines after DFS and improper newline in BFS.]
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs();
    system("pause"); // @@ [This line may cause compilation or runtime issues in environments without 'system' support or when not linking properly, but more critically, it's unnecessary and may cause the program to hang waiting for input, which breaks automated judging. Also, the problem doesn't require pausing.]
    return 0;
}