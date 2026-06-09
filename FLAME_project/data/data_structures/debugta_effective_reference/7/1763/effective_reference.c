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
    int data,high;
    struct node *lc,*rc;
}BTNode,*BTREE;
BTREE new(){
    BTREE p=(BTREE)malloc(sizeof(BTNode));
    p->lc=NULL;
    p->rc=NULL;
    p->data=p->high=0;
    return p;
}
void insert(BTREE root,int newdata){
    if(newdata>=root->data){
        if(root->rc==NULL){
            BTREE p=new();
            root->rc=p;
            p->data=newdata;
            p->high=root->high+1;
        }
        else{
            insert(root->rc,newdata);
        }
    }
    if(newdata<root->data){
        if(root->lc==NULL){
            BTREE p=new();
            root->lc=p;
            p->data=newdata;
            p->high=root->high+1;
        }
        else {
            insert(root->lc,newdata);
        }
    }
}
void dfs(BTREE root){
    if(root->lc==NULL&&root->rc==NULL){
        printf("%d %d\n",root->data,root->high);
        return ;
    }
    if(root->lc!=NULL)dfs(root->lc);
    if(root->rc!=NULL)dfs(root->rc);
}
int main(){
    int n;scanf("%d",&n);
    BTREE root=new();
    for(int newdata,i=1;i<=n;i++){
        scanf("%d",&newdata);
        if(i==1)root->data=newdata,root->high=1;
        else insert(root,newdata);
    }
    dfs(root);
    return 0;
}
