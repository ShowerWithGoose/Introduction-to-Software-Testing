#include<stdio.h>
int n,m;
int val[1005],lc[1005],rc[1005];
void insert(int x){
    if(!m){val[++m]=x;return;}
    int p=1,q=0;
    while(p){
        if(x>=val[p]){q=p;p=rc[p];}
        else{q=p;p=lc[p];}
    }
    if(x>=val[q]) val[rc[q]=++m]=x;
    else val[lc[q]=++m]=x;
}
void dfs(int x,int d){
    if(!lc[x]&&!rc[x]) printf("%d %d\n",val[x],d);
    if(lc[x]) dfs(lc[x],d+1);
    if(rc[x]) dfs(rc[x],d+1);
}
int main(){
    scanf("%d",&n);int x;
    for(int i=1;i<=n;i++){scanf("%d",&x);insert(x);}
    dfs(1,1);
    return 0;
}
