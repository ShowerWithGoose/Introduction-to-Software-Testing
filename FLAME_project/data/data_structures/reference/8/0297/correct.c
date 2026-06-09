#include<stdio.h>
#include<string.h>
int n,m,po,L,R;
int M[105][105],q[105],v[105];
void dfs(int x){
    if(!v[x]) printf("%d ",x-1);
    v[x]=1;
    for(int i=1;i<=n;i++){
        if(i==x||!M[x][i]||v[i]) continue;
        dfs(i);
    }
}
void bfs(){
    L=1;R=0;q[++R]=1;
    while(L<=R){
        int x=q[L++];
        if(v[x]) continue;
        v[x]=1;printf("%d ",x-1);
        for(int i=1;i<=n;i++){
            if(i==x||!M[x][i]||v[i]) continue;
            q[++R]=i;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int xx,yy;scanf("%d%d",&xx,&yy);
        M[xx+1][yy+1]=M[yy+1][xx+1]=1;
    }
    scanf("%d",&po);po++;
    dfs(1);memset(v,0,sizeof(v));puts("");
    bfs();memset(v,0,sizeof(v));puts("");
    v[po]=1;
    dfs(1);memset(v,0,sizeof(v));puts("");
    v[po]=1;
    bfs();memset(v,0,sizeof(v));puts("");
    return 0;
}
