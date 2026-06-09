#include<stdio.h>
int n,hd[105],m;
struct NODE{
    int x1,x2,y1,y2;
}node[105];
/*
struct EDG{
    int to,nxt;
}edg[10000];
void add(int u,int v){
    edg[++m].to=v;
    edg[m].nxt=hd[u];
    hd[u]=m;
}
void dfs()
*/
int fa[105],sz[105];
int find(int x){
    if(fa[x]==x) return x;
    else return find(fa[x]);
}
void Union(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    else fa[x]=y,sz[y]+=sz[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) fa[i]=i,sz[i]++;
    for(int i=1;i<=n;++i) scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(node[i].x1==node[j].x2 && node[i].y1==node[j].y2){
                Union(i,j);
            }
        }
    }
    int mx=0,k; for(int i=1;i<=n;++i) if(sz[i]>mx) mx=sz[i],k=i;
    printf("%d %d %d",mx,node[k].x1,node[k].y1);

    return 0;
}
