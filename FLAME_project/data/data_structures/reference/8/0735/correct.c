#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int n, e;
int tmp[102][102];
int visited[102], visited0[102];
int flag=0;
void DFS(int p){
	int i;
    if (flag == 0){
        printf("%d", p);
        flag = 1;
    }
    else
        printf(" %d", p);
    visited[p] = 1;
    for (i = 1; i <= n; i++)
        if (tmp[p][i] == 1 && visited[i] == 0)
            DFS(i);
}
void BFS(int p)
{
    int t,i,j,r;
    visited0[1] = p;
    for (j = 1, r = 1; j <= r;){
        t = visited0[j++];
        if (visited[t] == 1){
            continue;
		}
        if (flag == 0){
            printf("%d", t);
            flag = 1;
        }
        else
            printf(" %d", t);
        visited[t] = 1;
        for (i = 1; i <= n; i++)
            if (tmp[t][i] == 1 && visited[i] == 0)
                visited0[++r] = i;
    }
}
int main(){
    int x, y;
    int i,j,k;
    scanf("%d%d", &n, &e);
    for (i = 1; i <= e; i++){
        scanf("%d%d", &x, &y);
        tmp[x][y] = 1;
        tmp[y][x] = 1;
    }
    DFS(0);
    printf("\n");
    flag = 0;
    for (k = 0; k < 102; k++)
        visited[k] = 0;
    BFS(0);
    printf("\n");
    flag = 0;
    for (k = 0; k < 102; k++)
        visited[k] = 0;
    scanf("%d",&x);
    visited[x] = 1;
    DFS(0);
    printf("\n");
    flag = 0;
    for (k = 0; k < 102; k++)
        visited[k] = 0;
    visited[x] = 1;
    BFS(0);
    printf("\n");
    flag = 0;
    for (k = 0; k < 102; k++)
        visited[k] = 0;
    return 0;
}


