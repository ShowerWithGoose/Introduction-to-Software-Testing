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
    dfs(0, 0);
    printf("\n");
    clear();
    bfs(0); // @@ [The BFS function starts with an empty queue; queue[0] is 0 but not explicitly set, and vertex 0 may not be enqueued properly. Also, the condition `(m == 0 || i != m)` fails to exclude the deleted vertex when m != 0 because it allows all vertices when m == 0, but when m != 0, it excludes only vertex `m`, yet the starting vertex might be incorrectly handled. Additionally, in BFS, the initial queue should start with vertex 0, but it's never added to the queue.]
    printf("\n");
    clear();
    dfs(del, 0);
    printf("\n");
    clear();
    bfs(del); // @@ [Same issue as above: the BFS queue is initialized to all zeros, but vertex 0 is never enqueued at the start, so traversal doesn't begin. Also, the logic `(m == 0 || i != m)` is flawed—it should always skip vertex `m` (the deleted one), regardless of whether m is 0 or not, but since m is never 0 per problem constraints, this condition effectively becomes `i != m`, which is correct, but the bigger issue is missing initialization of queue with start vertex 0.]
        
    return 0;
}