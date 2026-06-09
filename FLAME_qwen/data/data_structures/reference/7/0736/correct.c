#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

typedef struct TREENODE{
    int dat;
    // int hig;
    int l,r;
}node;

node bst[10086];

int n, tl = 1;

int ins(int x,int h,int c) {
    if(x==0) {
        bst[++tl].dat=c;
        // bst[tl].hig=h;
        return tl;
    }
    int r = 0;
    if(c<bst[x].dat) {
        r = ins(bst[x].l, h+1, c);
        if(r) bst[x].l=r;
    }
    else if(c>=bst[x].dat) {
        r = ins(bst[x].r, h+1, c);
        if(r) bst[x].r=r;
    }
    return 0;
}

int dfs(int x,int h) {
    if(x==0) return 0;
    int l = dfs(bst[x].l, h+1);
    int r = dfs(bst[x].r, h+1);
    if(l==r&&l==0) {
        printf("%d %d\n", bst[x].dat, h);
    }
    return x;
}

int main() {
    scanf("%d", &n);
    for(int T=0;T<n;T++) {
        if(T==0) {
            scanf("%d", &bst[1].dat);
        }else {
            int i;
            scanf("%d", &i);
            ins(1,1,i);
        }
    }
    dfs(1,1);

    return 0;
}



