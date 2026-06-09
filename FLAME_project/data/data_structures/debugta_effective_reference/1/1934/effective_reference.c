/*
 * @Author:
 * @Date: 2022-03-03 23:41:05
 * 
 */
#pragma GCC optimize(2)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxN 25

int n;

struct Node{
    int val;
    struct Node *pre,*nex;
}list[MaxN];
typedef struct Node nn;

bool mark[MaxN];
int ans[MaxN];
void dfs(int i){
    if(i==n+1){
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    // for(nn *it=list[0].nex;it->val!=n+1;it=it->nex){
    //     ans[i]=it->val;
    //     it->pre->nex=it->nex;
    //     it->nex->pre=it->pre;
    //     dfs(i+1);
    //     it->pre->nex=it;
    //     it->nex->pre=it;
    //     ans[i]=0;
    // }
    for(int j=1;j<=n;j++){
        if(mark[j]) continue;
        mark[j]=true;
        ans[i]=j;
        dfs(i+1);
        ans[i]=0;
        mark[j]=false;
    }
}

int main(int argc, char const *argv[]){
    //freopen("p.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n+1;i++){
        list[i].val=i;
        list[i].nex = i==n+1?NULL:&list[i+1];
        list[i].pre = i==0?NULL:&list[i-1];
    }
    dfs(1);
    return 0;
}


