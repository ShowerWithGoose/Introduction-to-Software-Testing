//5.1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node BSTnode;
typedef struct node *BSTnodeptr;
BSTnode bstno;
BSTnodeptr root=NULL;
int h=0;
BSTnodeptr insertBST(BSTnodeptr p,int item)
{
    if(p==NULL){
        p=(BSTnodeptr)malloc(sizeof(BSTnode));
        p->data=item;
        p->left=p->right=NULL;
    } 
    else if(item<p->data)
        p->left=insertBST(p->left,item);
    else if(item>=p->data)
        p->right=insertBST(p->right,item);
    return p;
} 
void preorder(BSTnodeptr t)
{
    h++;
      if(t!=NULL){
            if(t->left==NULL&&t->right==NULL)
                printf("%d %d\n",t->data,h);       /* 访问t指向结点  */
            preorder(t->left);
            preorder(t->right);
       }
    h--;
}

int main()
{
    int i,n,item;
    scanf("%d",&n);
    for(i=0;i<n;i++)//建立二叉查找树
    {
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    preorder(root);
    return 0;
}
