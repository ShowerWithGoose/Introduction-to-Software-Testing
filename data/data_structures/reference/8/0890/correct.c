#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int m, n, s[102][102], tmp[102], tem[102], help;
void dfs(int p)
{
    int i;
    if (help == 0){
        printf("%d", p);
        help = 1;
    }
    else{
        printf(" %d", p);
    }
    tmp[p] = 1;
    for (i = 1; i <= m; i++){
        if (s[p][i] == 1 && tmp[i] == 0){
            dfs(i);
        }
    }
}

void bfs(int p)
{
    int t,i,j,r;
    tem[1] = p;
    for (j = 1, r = 1; j <= r;){
        t = tem[j++];
        if (tmp[t] == 1){
            continue;
        }
        if (help == 0){
            printf("%d", t);
            help = 1;
        }
        else{
            printf(" %d", t);
        }

        tmp[t] = 1;
        for (i = 1; i <= m; i++){
            if (s[t][i] == 1 && tmp[i] == 0){
                tem[++r] = i;
            }
        }
    }
}

int main()
{
    int x,y,i,k;
    scanf("%d%d", &m, &n);
    for ( i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        s[x][y] = 1;
        s[y][x] = 1;
    }
    dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++){
        tmp[k] = 0;
        help = 0;
    }
    bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++){
        tmp[k] = 0;
        help = 0;
    }
    scanf("%d",&x);
    tmp[x] = 1;
    dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++){
        tmp[k] = 0;
        help = 0;
    }
    tmp[x] = 1;
    bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++){
        tmp[k] = 0;
        help = 0;
    }
}

