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
    int data,roof;
    struct node *lc,*rc;
}BTNode,*BTREE;
BTREE new(){
    BTREE p=(BTREE)malloc(sizeof(BTNode));
    p->lc=NULL;
    p->rc=NULL;
    p->data=p->roof=0;
    return p;
}
void insert(BTREE p,int i){
    if(i>=p->data){
        if(p->rc==NULL){
            BTREE p=new();
            p->rc=p;
            p->data=i;
            p->roof=p->roof+1;
        }
        else{
            insert(p->rc,i);
        }
    }
    if(i<p->data){
        if(p->lc==NULL){
            BTREE p=new();
            p->lc=p;
            p->data=i;
            p->roof=p->roof+1;
        }
        else {
            insert(p->lc,i);
        }
    }
}
void dfs(BTREE p){
    if(p->lc==NULL&&p->rc==NULL){
        printf("%d %d\n",p->data,p->roof);
        return ;
    }
    if(p->lc!=NULL)dfs(p->lc);
    if(p->rc!=NULL)dfs(p->rc);
}
int main(){
    int n;scanf("%d",&n);
    BTREE root=new();
    for(int i,j=1;j<=n;j++){
        scanf("%d",&i);
        if(j==1)root->data=i,root->roof=1;
        else insert(root,i);
    }
    dfs(root);
    return 0;
}
