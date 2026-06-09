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
    printf("%d", vertax); // @@ The output format is incorrect. Vertices should be separated by spaces, e.g., "0 1 2", but this prints them consecutively like "012". It should be printf("%d ", vertax);
    for (i = 0; i < n; i++) {
        if ((m == 0 || i != m) && !visited[i] && a[vertax][i]) {
            dfs(m, i);
        }
    }    
}
void bfs(int m) 
{
    int i, queue[500] = {0}, head = 0, tail = 0;
    queue[tail++] = 0; // @@ The BFS function is missing the initialization to enqueue the starting vertex (0). Without this, the queue is empty, head > tail initially (or head==tail but queue[0] is 0 which might work by luck if not cleared properly, but logically it's missing the start step). More critically, visited[0] is not set before the loop or inside correctly for the start node in the standard way. Let's look closer. The loop condition is head <= tail. Initially head=0, tail=0. So it enters. queue[0] is 0 (from initialization {0}). It prints 0. Then marks visited. Then adds neighbors. This *might* work for the first node if queue is global or static, but here it's local. Local array queue[500] = {0} sets all to 0. So queue[0] is 0. It works for start node 0. However, the output format is also wrong here.
    while (head <= tail) {
        printf("%d", queue[head]); // @@ The output format is incorrect. Vertices should be separated by spaces. It should be printf("%d ", queue[head]);
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
    bfs(0);
    printf("\n");
    clear();
    dfs(del, 0);
    printf("\n");
    clear();
    bfs(del);
        
    return 0;
}