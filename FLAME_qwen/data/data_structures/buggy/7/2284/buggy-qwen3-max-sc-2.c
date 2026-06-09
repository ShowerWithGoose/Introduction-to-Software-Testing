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
    else if(x>t[now]){ @@ // The problem requires right child for values >= root, but this only handles >. Equal values are ignored, causing missing nodes.
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
    if(rc[now])pr(rc[now]); @@ // This is a post-order traversal (left, right, root), but the problem requires left-to-right leaf order which corresponds to in-order traversal (LDR).
    if(!lc[now]&&!rc[now]) printf("%d %d\n",t[now],h[now]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ins(1,a[i]); @@ // When tot==0 (first insertion), ins(1, a[i]) is called, but node 1 doesn't exist yet; should pass tot or handle differently.
    }
    pr(1); @@ // If no nodes were inserted (n=0), pr(1) accesses uninitialized memory. Also, if first node is inserted as node 1, but subsequent equal values are dropped, tree may be incomplete.
}