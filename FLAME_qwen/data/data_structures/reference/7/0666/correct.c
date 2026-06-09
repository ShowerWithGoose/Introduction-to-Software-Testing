#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *lchild,*rchild;
}*root;
int x=0;
struct node* insertBST(struct node* t,int item){
    if(t==NULL){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=item;
        t->lchild=t->rchild=NULL;
    }
    else if(item<t->data){
        t->lchild=insertBST(t->lchild,item);
    }
    else if(item>=t->data){
        t->rchild=insertBST(t->rchild,item);
    }
    return t;
}
void mid(struct node* t){
    if(t==NULL){
        return;
    }
    else{
        x++;
        mid(t->lchild);
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,x);
        }
        mid(t->rchild);
        x--;
    }
}

int main(){
    int n,i,item;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
           scanf("%d",&item);
           root=insertBST(root,item);
        }
      mid(root);
      return 0;
}





