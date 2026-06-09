#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vertex[100][100] = {0};
int visited[100] = {0};
int n;

void delG(int m);
void bfs(int que[100],int len);
void dfs(int root);

int main()
{
    int e,temp,i;
    int que[100] = {0};
    int v1,v2;
    scanf("%d%d",&n,&e);
    for(i = 0;i < e;i++){
        scanf("%d%d",&v1,&v2);
        vertex[v1][v2] = vertex[v2][v1] = 1;
    }
    scanf("%d",&temp);
    dfs(0);
    memset(visited,0,sizeof(int) *100);
    visited[0] = 1;
    printf("\n");
    bfs(que,1);
    memset(visited,0,sizeof(int) *100);
    printf("\n");

    delG(temp);
    dfs(0);
    memset(visited,0,sizeof(int) *100);
    visited[0] = 1;
    printf("\n");
    bfs(que,1);
    memset(visited,0,sizeof(int) *100);
    printf("\n");

    return 0;
}
void bfs(int que[100],int len)
{
    int i,j = 0,k = 0;
    int num[100] = {0};
    if(len == 0)
        return;
    for(i = 0;i < len;i++)
        printf("%d ",que[i]);
    for(i = 0;i < len;i++){
        for(j = 0;j < n;j++){
            if(vertex[que[i]][j] && visited[j] == 0){
                num[k++] = j;
                visited[j] = 1;
            }
        }
    }
    bfs(num,k);
}
void dfs(int root)
{
    int i;
    printf("%d ",root);
    visited[root] = 1;
    for(i = 0;i < n;i++){
        if(vertex[root][i] && visited[i] == 0){
            dfs(i);
        }
    }
}
void delG(int m)
{
    int i;
    for(i = 0;i < n;i++)
        vertex[i][m] = vertex[m][i] = 0;
}

