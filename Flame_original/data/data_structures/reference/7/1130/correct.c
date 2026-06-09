#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10000

typedef struct Node{
    int l,r;
    int val;
}Nd;
Nd nds[N];
int idx = 1;
int rt = 0;
void insert(int v){
    if(rt == 0){
        rt = idx;
        nds[idx++].val = v;
        return;
    }
    int cur = rt;
    while(1){
        if(nds[cur].val<=v){
            //右边
            if(nds[cur].r){
                cur = nds[cur].r;
            }else{
                nds[idx].val = v;
                nds[cur].r = idx++;
                break;
            }
        }else{
            if(nds[cur].l){
                cur = nds[cur].l;
            }else{
                nds[idx].val = v;
                nds[cur].l = idx++;
                break;
            }
        }
    }
}
void dfs(int cur,int dep){
    if(!nds[cur].l && !nds[cur].r){
        printf("%d %d\n",nds[cur].val, dep);
        return;
    }
    if(nds[cur].l){
        dfs(nds[cur].l, dep+1);
    }
    if(nds[cur].r){
        dfs(nds[cur].r,dep+1);
    }
}
int main() {
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif

    memset(nds,0,sizeof(nds));
    int n;
    scanf("%d", &n);
    for(int i = 0;i<n;i++) {
        int j;
        scanf("%d", &j);
        insert(j);
    }

    dfs(rt, 1);
}

