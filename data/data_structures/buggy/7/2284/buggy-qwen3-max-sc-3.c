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
    else if(x>t[now]){ // @@ [The problem requires right child for values >= root, but this code only inserts into right subtree when x > t[now], ignoring equality. This causes equal values to be dropped instead of inserted into the right subtree.]
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
    if(rc[now])pr(rc[now]);
    if(!lc[now]&&!rc[now]) printf("%d %d\n",t[now],h[now]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ins(1,a[i]); // @@ [When inserting the first node (tot==0), it's correctly handled inside ins(). However, for subsequent insertions, the initial call always uses 'now=1', which assumes the root exists. But if tot==0, the root is created. The logic is mostly okay, but the real issue is in handling duplicates as noted above. Also, if n==0, this would call ins(1,...) with uninitialized t[1], but n>=1 per test cases likely. The main bug is the missing '=' in comparison.]
    }
    pr(1);
}