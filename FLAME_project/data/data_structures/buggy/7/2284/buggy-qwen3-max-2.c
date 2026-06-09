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
    else if(x>t[now]){  // @@ [The condition excludes equal values (x == t[now]), so duplicate values like the second 100 are ignored and not inserted into the BST. According to the problem, right child should be >= root, so duplicates should go to the right subtree.]
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
        ins(1,a[i]);  // @@ [When tot == 0 (first insertion), the root is set correctly. But on subsequent calls, 'now' is always passed as 1, which assumes node 1 is always the root. However, if the first element is not inserted at index 1 due to some logic error or reordering, this would break. More critically, after the first insertion, 'now' should be the root (which is node 1), but the real issue is that duplicate values are skipped entirely, so the second 100 is never inserted, causing it to be missing from the leaf output.]
    }
    pr(1);
}