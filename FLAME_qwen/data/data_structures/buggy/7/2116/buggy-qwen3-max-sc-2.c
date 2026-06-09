#include<stdio.h>
#include<stdlib.h>
int n;

typedef struct leaf
{
    int data;
    struct leaf* lchild;
    struct leaf* rchild;
}leaf;
typedef leaf* bst;

bst insert(bst p,int data_p);
void printleaves(bst p,int high);
int main()
{
    bst root;
    root=NULL;
    scanf("%d",&n);//读入整数数量
    for(int i=0;i<n;i++)
    {
        int data_s;
        scanf("%d",&data_s);
        root=insert(root,data_s);
    }
    printleaves(root,1);
    return 0;
}

bst insert(bst p,int data_p)
{
    if(p==NULL)
    {
        p=(bst) malloc(sizeof(leaf));
        if(p==NULL)
        {
            printf("Faild to new p\n");
            return NULL;
        }
        p->data=data_p;
        p->lchild=p->rchild=NULL;
        return p;
    }else{
        if(data_p<p->data)
        {
            p->lchild=insert(p->lchild,data_p);
        }else{
            p->rchild=insert(p->rchild,data_p);
        }
    }
    return p;
}

void printleaves(bst p,int high)
{
    if(p==NULL)
    {
        printf("ERROR\n");
        return;
    }
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->data,high);
    }
    if(p->lchild!=NULL) printleaves(p->lchild,high++); // @@ [Using post-increment (high++) passes the original value of 'high' to the left subtree and then increments it locally, but the incremented value is not used for the right subtree. This leads to incorrect height calculation. Should pass 'high + 1' instead.]
    if(p->rchild!=NULL) printleaves(p->rchild,high++); // @@ [Same issue as above: post-increment does not correctly propagate increased height to the right subtree. Also, after the first call, 'high' is modified, which affects the second call incorrectly.]
    return;
}