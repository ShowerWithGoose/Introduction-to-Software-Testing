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
    else if(x>t[now]){ // @@ [The problem requires right child for values >= root, but this code only inserts right when x > t[now], ignoring equal values. Equal values should go to the right subtree per problem description.]
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
    if(rc[now])pr(rc[now]); // @@ [This traversal is post-order (left, right, root), but the problem requires left-to-right order of leaf nodes, which corresponds to in-order traversal (left, root, right). This will output leaves in incorrect order.]
    if(!lc[now]&&!rc[now]) printf("%d %d\n",t[now],h[now]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ins(1,a[i]); // @@ [When inserting the first element, tot is 0 so it gets inserted correctly. But for subsequent insertions, the initial call always uses 'now=1', which assumes node 1 exists. However, if the first insertion didn't happen (e.g., n=0), this would be invalid. More critically, after the first insertion, node 1 exists, so this is okay for n>=1. However, the real issue is that equal elements are ignored entirely because the 'else if(x>t[now])' does not handle x == t[now], causing duplicates to be silently dropped, violating BST construction rule (>= should go right).]
    }
    pr(1);
}