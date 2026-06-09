#include <stdio.h>
void dfs(unsigned int, unsigned short int *);
void bfs(unsigned int, unsigned short int *);

short int table[111][111] = {{0}};
unsigned n; // node_count
unsigned e; // edge_count

unsigned int flag_print_time = 0; // 打印次数。第一次打印的时候没空格

int main()
{
    if (0)
        freopen("test0.txt", "r", stdin);
    scanf("%u %u", &n, &e);
    for (int i = 0; i < e; i++)
    {
        unsigned a, b;
        scanf("%u %u", &a, &b);
        table[a][b] = 1;
        table[b][a] = 1;
    }

    {
        flag_print_time = 0;
        unsigned short int visited[111] = {0};
        dfs(0, visited);
        printf("\n");
    }
    {
        flag_print_time = 0;
        unsigned short int visited[111] = {0};
        bfs(0, visited);
        printf("\n");
    }
    unsigned to_be_deleted;
    scanf("%u", &to_be_deleted);
    for (unsigned i = 0; i < n; i++)
    {
        if (table[to_be_deleted][i])
        {
            table[to_be_deleted][i] = 0;
            table[i][to_be_deleted] = 0;
        }
    }
    {
        flag_print_time = 0;
        unsigned short int visited[111] = {0};
        dfs(0, visited);
        printf("\n");
    }
    {
        flag_print_time = 0;
        unsigned short int visited[111] = {0};
        bfs(0, visited);
        printf("\n");
    }
    return 0;
}

void dfs(unsigned int start, unsigned short int *visited)
{
    if (visited[start])
        return;
    if (flag_print_time++ == 0)
        printf("%u", start);
    else
        printf(" %u", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++)
        if (table[start][i])
            dfs(i, visited);
}

void bfs(unsigned int start, unsigned short int *visited)
{
    unsigned int queue[9999] = {0};
    unsigned int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front != rear)
    {
        unsigned int cur = queue[front++];
        if (flag_print_time++ == 0)
            printf("%u", cur);
        else
            printf(" %u", cur);
        for (int i = 0; i < n; i++)
            if (table[cur][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
}
