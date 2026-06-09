/*
 * @Author:
 * @Date: 2022-03-24 19:15:09
 * @LastEditors:
 * @LastEditTime: 2022-03-24 19:28:09
 * @FilePath: line.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 1010
int n;
int father[MAXN], G[MAXN];

typedef struct Line
{
    int x_1,y_1,x_2,y_2;
}Line;
Line A[MAXN];

int find(int x) { return father[x] = father[x] == x ? x : find(father[x]); }

int pd(int x_1, int y_1, int x_2, int y_2) { return x_1 == x_2 && y_1 == y_2; }

int cmp(Line x, Line y)
{
    if(pd(x.x_1,x.y_1,y.x_1,y.y_1)) return 1;
    if(pd(x.x_1,x.y_1,y.x_2,y.y_2)) return 1;
    if(pd(x.x_2,x.y_2,y.x_1,y.y_1)) return 1;
    if(pd(x.x_2,x.y_2,y.x_2,y.y_2)) return 1;
    return 0;
}

void Union(int x, int y)
{
    x = find(x); y = find(y);
    if(x == y) return;
    if(A[x].x_1 < A[y].x_1)
    {
        father[y] = x;
        G[x] += G[y];
    }
    else
    {
        father[x] = y;
        G[y] += G[x];
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) father[i] = i, G[i] = 1;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d%d",&A[i].x_1,&A[i].y_1,&A[i].x_2,&A[i].y_2);
        for(int j=1;j<i;++j)
        {
            if(cmp(A[i],A[j]))
                Union(i,j);
        }
    }
    int Max = 0,pos;
    for(int i=1;i<=n;++i)
    if(G[find(i)] > Max)
    {
        Max = G[find(i)];
        pos = find(i);
    }
    printf("%d %d %d",G[pos],A[pos].x_1,A[pos].y_1);
    return 0;
}


