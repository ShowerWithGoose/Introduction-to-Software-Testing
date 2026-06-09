#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 100050
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
typedef struct node{
    int data,depth;
    struct node *lc,*rc;
}BTNode,*BTREE;
BTREE new(){
    BTREE p=(BTREE)malloc(sizeof(BTNode));
    p->lc=NULL;
    p->rc=NULL;
    p->data=p->depth=0;
    return p;
}
void insert(BTREE now,int x){
    if(x>=now->data){
        if(now->rc==NULL){
            BTREE p=new();
            now->rc=p;
            p->data=x;
            p->depth=now->depth+1;
        }
        else{
            insert(now->rc,x);
        }
    }
    if(x<now->data){
        if(now->lc==NULL){
            BTREE p=new();
            now->lc=p;
            p->data=x;
            p->depth=now->depth+1;
        }
        else {
            insert(now->lc,x);
        }
    }
}
void dfs(BTREE now){
    if(now->lc==NULL&&now->rc==NULL){
        printf("%d %d\n",now->data,now->depth);
        return ;
    }
    if(now->lc!=NULL)dfs(now->lc);
    if(now->rc!=NULL)dfs(now->rc);
}
int main(){
    int n;scanf("%d",&n);
    BTREE root=new();
    for(int x,i=1;i<=n;i++){
        scanf("%d",&x);
        if(i==1)root->data=x,root->depth=1;
        else insert(root,x);
    }
    dfs(root);
    return 0;
}
