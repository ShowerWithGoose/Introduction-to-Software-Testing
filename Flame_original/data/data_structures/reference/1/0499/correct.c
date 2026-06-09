#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int c[11],n;
int vis[11];

void print(){
    for(int i=1;i<=n;i++)
        printf("%d ", c[i]);
    putchar('\n');
}

void dfs(int cur){
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        c[cur] = i;
        dfs(cur + 1);
        vis[i] = 0;
    }
    if(cur==n+1) {
        print();
        return;
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}



