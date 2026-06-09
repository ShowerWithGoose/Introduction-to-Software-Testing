#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define maxn 10000

int son[maxn][2];
int t[maxn], tot;
int root;

int readInt()
{
    static char c;
    int f = 1;
    while(!isdigit(c = getchar()))
        if(c == '-') f = -1;
    int res = 0;
    while(isdigit(c))
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * f;
}

int insert(int now, int x)
{
    if(!now)
    {
        t[++tot] = x;
        return tot;
    }
    int to = t[now] <= x;
    son[now][to] = insert(son[now][to], x);
    return now;
}

void dfs(int now, int deep)
{
    if(!now) return;
    if(!son[now][0] && !son[now][1])
    {
        printf("%d %d\n", t[now], deep);
        return ;
    }
    dfs(son[now][0], deep + 1);
    dfs(son[now][1], deep + 1);
    return ;
}

int main()
{
    int n = readInt();
    for(int i = 0; i < n; ++i)
        root = insert(root, readInt());
    dfs(root, 1);
    return 0;
}
