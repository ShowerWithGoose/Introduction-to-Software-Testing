#include<stdio.h>
int a[105],t[105],lc[105],rc[105],tot=0,h[105];
void ins(int now,int x){
    if(tot==0){
        t[++tot]=x;
        h[tot]=1;
        return ;
    }
    if(x<t[now]){
        if(lc[now])ins(lc[now],x);
        else {
            t[++tot]=x;
            lc[now]=tot;
            h[tot]=h[now]+1;
        }
    }
    else if(x>t[now]){ @@ // The problem requires right child for values >= root, but this only handles >, missing equality case
        if(rc[now])ins(rc[now],x);
        else {
            t[++tot]=x;
            rc[now]=tot;
            h[tot]=h[now]+1;
        }
    }
    return ;
}
void pr(int now){
    if(lc[now])pr(lc[now]);
    if(rc[now])pr(rc[now]); @@ // This is a post-order traversal (left, right, root), but the problem requires left-to-right leaf order which should be in-order (LDR)
    if(!lc[now]&&!rc[now]) printf("%d %d\n",t[now],h[now]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ins(1,a[i]); @@ // When tot==0 (first insertion), ins(1, a[i]) passes now=1, but node 1 doesn't exist yet; should pass a valid existing node or handle differently
    }
    pr(1);
}