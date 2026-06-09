#include <stdio.h>
#define Max 11
int mark[Max];
int seq[Max];
int N;
void dfs(int n)
{
    if (n == N + 1)
    {
        for (int i = 1; i <= N; i++)
            printf("%d ", seq[i]);
        puts("");
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            seq[n] = i;
            dfs(n + 1);
            mark[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &N);
    dfs(1);
    return 0;
}


