#include<stdio.h>
int n;
int vis[15];
int a[15];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            a[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
            a[x]=0;
        }
    }
}
int main(void){
    scanf("%d",&n);
    dfs(1);
    return 0;
}
