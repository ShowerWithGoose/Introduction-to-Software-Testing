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

int delete = -1; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools that treat it as a keyword; although standard C allows it, it's poor practice and may lead to compilation errors in strict environments. However, the actual critical error is elsewhere.]

int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x - f && x - delete) { // @@ [The condition `x - f` and `x - delete` is incorrect. It should be `x != f` and `x != delete`. Using subtraction in a boolean context checks if the result is non-zero, which accidentally works when f or delete equals x only if they are equal, but this is logically wrong and fragile. More critically, during the first traversal (before deletion), `delete` is -1, so `x - delete` becomes `x - (-1) = x+1`, which is always non-zero for valid vertices (0 to n-1), so it doesn't block anything — which is okay for first run. But the real issue is in BFS.]
            dfs(a, x);
            end = 0;
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ [This prints a newline before "0", but the expected output format requires all four lines to each contain one sequence without extra newlines at the start. The first DFS already printed its line without a trailing newline (only space-separated), then this prints "\n0 ", causing misalignment. Also, the first BFS call happens right after first DFS without resetting visited properly? Actually, visited is reset here, but the bigger issue is output formatting and logic in traversal conditions.]
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) { // @@ [Same logical error as in DFS: `y - x` should be `y != x` (though y == x shouldn't happen in simple graph), but more importantly, `y - delete` is again using subtraction instead of inequality. However, the critical flaw is that in BFS, the condition `y - x` is always true since there are no self-loops, so it's redundant but not harmful. The real problem is that during the second traversal (after deletion), `delete` holds the vertex to remove, and this condition correctly skips it. But the main bug is in output format and traversal order handling.]
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
    dfs(-1, 0); bfs(); // @@ [This outputs DFS on one line (e.g., "0 1 2 ") and then BFS starts with "\n0 ...", so overall output becomes "0 1 2 \n0 ...", which is two lines — correct so far. But the problem requires: first line DFS before, second BFS before, third DFS after, fourth BFS after. However, note that `bfs()` itself prints a leading newline, so the first two traversals are: Line1: "0 1 2 ", Line2: "\n0 1 2 " → which actually makes Line2 start with newline, so visually it's okay? But wait: the first `dfs` does NOT print a newline, only spaces, then `bfs` prints "\n0 ...", so the first line ends with space and no newline, then second line starts correctly. However, the bigger issue is that after reading `delete`, the second `dfs` also doesn't print a newline, and then `bfs` again prints "\n...", so the third line has no newline at end, and fourth starts with newline — acceptable? But the test environment expects exact spacing. However, the compilation error reported was "/bin/sh: 1: gcc: not found", which suggests the code didn't even compile — but that's likely a red herring from the test runner. The real issue is logical. But wait: the variable name `delete` is a reserved word in C++ and some compilers might flag it even in C mode. However, standard C allows it. But the actual critical error causing wrong output is in BFS: it prints a newline at the beginning, which causes the first BFS output to be on a new line — that's correct. But look at the sequence: 
    // Expected: 
    // DFS_before
    // BFS_before
    // DFS_after
    // BFS_after
    // But current code:
    // dfs() -> prints "0 1 2 " (no newline)
    // bfs() -> prints "\n0 1 2 " → so now we have "0 1 2 \n0 1 2 "
    // Then after reading delete:
    // dfs() -> prints "0 2 " (no newline)
    // bfs() -> prints "\n0 2 "
    // So final output: "0 1 2 \n0 1 2 0 2 \n0 2 "
    // Which is 3 lines? Because the third part (DFS after) is appended to the second line.
    // That's the bug! The first BFS ends with a space and no newline. Then the second DFS prints on the same line.
    // So the output becomes:
    // Line1: 0 1 2 
    // Line2: 0 1 2 0 2 
    // Line3: 0 2 
    // Which is wrong.
    // Therefore, each traversal must end with a newline.
    // The `dfs` function does not print a newline, and `bfs` prints a newline at the beginning, not the end.
    // So after first dfs: no newline.
    // Then bfs: prints \n then content → so first line is dfs output, second line is bfs output — good.
    // But then second dfs: prints on the same line as bfs output (because bfs didn't end with newline).
    // So the fix is: each write() equivalent must end with newline.
    // In this code, `dfs` should end with newline, and `bfs` should not start with newline but end with one.
    // Hence, the error is in output formatting in both dfs and bfs functions.
    ]
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ [Same issue: dfs prints without newline, then bfs prints newline at start, so the third sequence (DFS after) gets appended to the second line (BFS before). This causes incorrect line breaks.]
    system("pause"); // @@ [This is non-standard and may cause compilation or runtime issues on non-Windows systems, but not the primary logical error. However, in competitive programming environments, this can cause presentation error or runtime failure, but the problem states the error is Compilation Error. But the initial error message was "gcc: not found", which is environmental. However, the logical errors in output format will cause wrong answer, not compilation error. But note: the variable name `delete` might actually cause a compilation error in some strict C compilers or when compiled as C++ by mistake. Since the problem says "Compilation Error", and `delete` is a keyword in C++, if the judge uses a C++ compiler for C code, this would fail. So this line is problematic.]
    return 0;
}