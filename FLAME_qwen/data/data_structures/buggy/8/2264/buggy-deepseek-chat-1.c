#include<stdio.h>

int a[101][101], n, visited[101];
void clear()
{
    int i;
    for (i = 0; i < n; i++) 
        visited[i] = 0;
}

void dfs(int m, int vertax)
{
    int i, j = 0, ans[101];
    visited[vertax] = 1;
    printf("%d", vertax);
    for (i = 0; i < n; i++) {
        if ((m == 0 || i != m) && !visited[i] && a[vertax][i]) {
            dfs(m, i);
        }
    }    
}
void bfs(int m) 
{
    int i, queue[500] = {0}, head = 0, tail = 0;
    while (head <= tail) {
        printf("%d", queue[head]);
        visited[queue[head]] = 1;
        for (i = 0; i < n; i++) {
            if ((m == 0 || i != m) && !visited[i] && a[queue[head]][i]) {
                queue[++tail] = i;
                visited[i] = 1;
            }
        }
        head += 1;
    }    
}

int main()
{
    int t, v1, v2, del;
    scanf("%d%d", &n, &t);
    while (t--) {
        scanf("%d%d", &v1, &v2);
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
    scanf("%d", &del);

    clear();    
    dfs(0, 0); // @@ The function dfs is called with m=0, but the condition (m == 0 || i != m) in the loop will always be true when m==0, so it does not skip any vertex. However, the problem requires deleting a vertex, but here m is used incorrectly: m should represent the deleted vertex, but when m=0, the condition (m == 0 || i != m) is always true, so no vertex is skipped. This is correct for the first traversal (before deletion), but the logic is flawed because m is used as both a flag and the deleted vertex, leading to incorrect behavior when m is the actual deleted vertex (e.g., when m=del, the condition (m == 0 || i != m) will skip vertex i only if i != m, but it also skips when m==0, which is not intended for deletion). The correct approach should treat m as the vertex to delete, and the condition should be (i != m) without the m==0 check.
    printf("\n");
    clear();
    bfs(0); // @@ Similar issue: bfs(0) uses m=0, and the condition (m == 0 || i != m) always true, so no vertex is skipped. This is correct for before deletion, but the logic is inconsistent.
    printf("\n");
    clear();
    dfs(del, 0); // @@ Here m=del, the condition (m == 0 || i != m) will skip vertex i only if i != del, but it also incorrectly includes the case m==0. Since del is not 0, the condition works for this specific case, but the overall design is flawed because the condition should simply be (i != m) without the m==0 check.
    printf("\n");
    clear();
    bfs(del); // @@ Same issue as above: the condition (m == 0 || i != m) is unnecessary and incorrect for general use.
        
    return 0;
}