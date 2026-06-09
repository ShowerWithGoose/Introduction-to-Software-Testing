#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct bstnode{
    int data,h;
    struct bstnode *l,*r;
}node;
void insert(int x,node *cur){
    if(x<cur->data){
        if(cur->l!=NULL) insert(x,cur->l);
        else {
            cur->l=(node *)malloc(sizeof(node));
            memset(cur->l,0,sizeof(node));
            cur->l->data=x;
            cur->l->h=cur->h+1;
            return;
        }
    }
    else if(x>=cur->data){
        if(cur->r!=NULL) insert(x,cur->r);
        else {
            cur->r=(node *)malloc(sizeof(node));
            memset(cur->r,0,sizeof(node));
            cur->r->data=x;
            cur->r->h=cur->h+1;
            return;
        }
    }
}
void visit(node *cur){
    if(cur==NULL) return;
    
    visit(cur->l);
    if(cur->l==NULL&&cur->r==NULL) 
        printf("%d %d\n",cur->data,cur->h);
    visit(cur->r);
}
int main(int argc,char *argv[]){
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);

    node *root=(node *)malloc(sizeof(node));
    memset(root,0,sizeof(node));
    root->data=x;
    root->h=1;
    
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        insert(x,root);
    }
    visit(root);
    system("pause");
    return 0;
}
