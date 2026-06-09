#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *lchild,*rchild;
};
struct Node* insert(struct Node*p,int x)
{
    if(p==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=x;
        p->lchild=p->rchild=NULL;
    }else if(x<p->data)
        p->lchild=insert(p->lchild,x);
    else
        p->rchild=insert(p->rchild,x);
    return p;
}
void inorder(struct Node* p,int high)
{
    if(p!=NULL)
    {
        inorder(p->lchild,high+1);
        if(p->lchild==p->rchild)
        printf("%d %d\n",p->data,high);
        inorder(p->rchild,high+1);
    }
}
int main()
{
    int N,x;
    struct Node* root=NULL;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&x);
        root=insert(root,x);
    }
    inorder(root,1);
}

