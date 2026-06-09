#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    int depth;
}node,*ptr;

void DLRtraversal(ptr root){
    if (root->lchild==NULL && root->rchild==NULL)
    {
        printf("%d %d\n",root->data,root->depth);
    }else{
        if(root->lchild!=NULL) DLRtraversal(root->lchild);
        if(root->rchild!=NULL) DLRtraversal(root->rchild);
    }
}

int main(){
    int num,temp;
    scanf("%d",&num);
    ptr root,p,tempnode;
    tempnode=p=root=NULL;
    while (num--)
    {
        scanf("%d",&temp);
        if (root==NULL)
        {
            p=(ptr)(malloc(sizeof(node)));
            memset(p,0,sizeof(node));
            p->data=temp;
            p->depth=1;
            root=p;
        }else{
            p=root;
            while (1)
            {
                tempnode=(ptr)(malloc(sizeof(node)));
                memset(tempnode,0,sizeof(node));
                tempnode->data=temp;                
                if (temp<p->data)
                {
                    if (p->lchild==NULL)
                    {
                        tempnode->depth=p->depth+1;
                        p->lchild=tempnode;
                        break;
                    }else{
                        p=p->lchild;
                    }
                }else{
                    if (p->rchild==NULL)
                    {
                        tempnode->depth=p->depth+1;
                        p->rchild=tempnode;
                        break;                       
                    }else{
                        p=p->rchild;
                    }
                }
            }
        }
    }
    DLRtraversal(root);
    return 0;
}
