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
    printf("%d", vertax); // @@ [Missing space after each vertex; should print "%d " instead of "%d"]
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
        printf("%d", queue[head]); // @@ [Missing space after each vertex; should print "%d " instead of "%d"]
        visited[queue[head]] = 1;
        for (i = 0; i < n; i++) {
            if ((m == 0 || i != m) && !visited[i] && a[queue[head]][i]) {
                queue[++tail] = i;
                visited[i] = 1; // @@ [Marking node as visited when enqueuing may cause incorrect BFS order or missed nodes in some cases, but more critically, the queue is not initialized with the start node]
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
    bfs(0); // @@ [BFS function does not initialize the queue with starting vertex 0, so it starts from queue[0]=0 only by zero-initialization, which works here but is fragile; however, the main issue is missing space and premature marking]
    printf("\n");
    clear();
    dfs(del, 0);
    printf("\n");
    clear();
    bfs(del);
        
    return 0;
}