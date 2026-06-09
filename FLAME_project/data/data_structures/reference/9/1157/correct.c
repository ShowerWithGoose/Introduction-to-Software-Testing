#include <stdio.h>

#define maxn 1000

struct node
{
    int x1, x2, y1, y2;
    int pre, nxt;
};

struct node line[maxn];
int tot;

int addl(int x1, int y1, int x2, int y2)
{
    line[++tot].x1 = x1;
    line[tot].y1 = y1;
    line[tot].x2 = x2;
    line[tot].y2 = y2;
    line[tot].nxt = line[tot].pre = 0;
    return tot;
}

int link(int x, int y)
{
    if(line[x].x1 == line[y].x2 && line[x].y1 == line[y].y2)
        return -1;
    if(line[x].x2 == line[y].x1 && line[x].y2 == line[y].y1)
        return 1;
    return 0;
}

void insert(int p)
{
    for(int i = 1; i < tot; ++i)
    {
        int f = link(p, i);
        int a = p, b = i;
        if(f == 0) continue;
        if(f == -1) a ^= b ^= a ^= b;
        line[a].nxt = b;
        line[b].pre = a;
    }
    return ;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        insert(addl(x1, y1, x2, y2));
    }
    int cnt = -1, p;
    for(int i = 1; i <= tot; ++i)
    {
        int tmp = 0;
        for(int j = i; j; j = line[j].nxt)
            ++tmp;
        if(tmp > cnt)
        {
            cnt = tmp;
            p = i;
        }
    }
    printf("%d %d %d", cnt, line[p].x1, line[p].y1);
}
