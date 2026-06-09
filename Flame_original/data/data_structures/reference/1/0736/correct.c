#include<stdio.h>

int gen[19];
int vis[19];
int n;

void print() {
    for(int i=1;i<=n;i++) printf("%d ",gen[i]);
    putchar('\n');
}

void dfs(int p) {
    if(p>n) {
        print();
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            vis[i] = 1;
            gen[p] = i;
            dfs(p+1);
            vis[i] = 0;
        }
    }
}

int main() {
    // freopen("out.txt","w",stdout);
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    dfs(1);
    return 0;
}
