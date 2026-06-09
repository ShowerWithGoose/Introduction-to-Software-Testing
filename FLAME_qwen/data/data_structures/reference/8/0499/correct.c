#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define M 1000

int vis[M];
int matrix[M][M];
int n;

void dfs(int s)
{
    vis[s]=1;
    printf("%d ",s);
    int i=0;
    for(;i<n;i++){
        if(matrix[s][i]&&!vis[i]) dfs(i);
    }
    return;
}

void bfs(int s)
{
    vis[s]=1;
    int i;
    int stk[M];
    memset(stk,0,sizeof(stk));
    int top=-1,tail=0;
    stk[++top]=s;
    while(top<=tail){
        for(i=0;i<n;++i){
            if(matrix[stk[top]][i]&&!vis[i]){
                stk[++tail]=i;
                vis[i]=1;
            }
        }
        printf("%d ",stk[top++]);
    }
    return;
}

int main(){
	memset(vis,0,sizeof(vis));
	memset(matrix,0,sizeof(matrix));
    int l;
    scanf("%d%d",&n,&l);
    int i,x,y;
    for(i=0;i<l;++i){
        scanf("%d%d",&x,&y);
        matrix[x][y]=1;
        matrix[y][x]=1;
        }
    scanf("%d",&l);
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    bfs(0);
    printf("\n");
    for(i=0;i<n;i++){
        matrix[l][i]=0;
        matrix[i][l]=0;
    }
    memset(vis,0,sizeof(vis));
    vis[l]=1;
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    vis[l]=1;
    bfs(0);
    printf("\n");
	return 0;
}





