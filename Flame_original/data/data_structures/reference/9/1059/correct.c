#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x1, y1, x2, y2;
} Line;

int n, connect[120], cnt[120];
Line line[120];

int dfs(int s)
{
    if(cnt[s]) return cnt[s];
    if(!~connect[s]) return cnt[s] = 1;
    return cnt[s] = dfs(connect[s]) + 1;
}

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    memset(connect, -1, sizeof connect);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(line[i].x2 == line[j].x1 && line[i].y2 == line[j].y1)
            {
                connect[i] = j;
                break;
            }
        }
    for(int i = 0; i < n; i++)
        dfs(i);
        // printf("%d->%d: %d\n", i, connect[i], cnt[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(cnt[i] > cnt[ans])
            ans = i;
    printf("%d %d %d\n", cnt[ans], line[ans].x1, line[ans].y1);
    return 0;
}
