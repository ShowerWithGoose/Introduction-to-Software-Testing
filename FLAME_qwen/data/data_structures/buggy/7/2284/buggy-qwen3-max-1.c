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
    else if(x>t[now]){ @@ // The problem requires right child for values >= root, but this only handles >, so equal values are ignored.
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
    if(rc[now])pr(rc[now]); @@ // This is a post-order traversal (LRN), but the problem requires left-to-right leaf output which corresponds to in-order (LNR) traversal.
    if(!lc[now]&&!rc[now]) printf("%d %d\n",t[now],h[now]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ins(1,a[i]); @@ // When tot==0 (first insertion), 'now' is 1 but t[1] hasn't been initialized yet; however, the first call uses now=1 before any node exists. This causes undefined behavior because lc[1], rc[1], t[1] are uninitialized when tot>0 but the tree is built incrementally. More critically, after the first insertion (tot=1), subsequent calls pass now=1 which is valid, but the initial state assumes node 1 exists only after first insertion. However, the real issue is that when inserting duplicates (x == t[now]), they are completely skipped due to missing equality handling.
    }
    pr(1);
}