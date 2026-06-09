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
    else if(x>t[now]){ // @@ [The condition excludes equal values; according to the problem, right child should include values >= root, but this code only inserts into right subtree when x > t[now], so duplicate values like the second 100 are ignored and not inserted into the tree.]
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
        ins(1,a[i]); // @@ [When tot==0 (first insertion), the root is set correctly, but for subsequent insertions, 'now' is always passed as 1, which assumes node 1 is always the root. However, after the first insertion, tot becomes 1 and node 1 exists, so this works for the root. BUT the real issue is that duplicate values (like the second 100) are not inserted at all due to the missing equality case in the insertion logic, causing the leaf node '100' to be missing in output.]
    }
    pr(1);
}