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
        printf("ERROR\n"); // @@ Incorrect: should not print ERROR for NULL; simply return is enough.
        return;
    }
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->data,high);
    }
    if(p->lchild!=NULL) printleaves(p->lchild,high++); // @@ Incorrect: passes current high, then increments; left subtree gets wrong height. Should be high+1.
    if(p->rchild!=NULL) printleaves(p->rchild,high++); // @@ Incorrect: due to previous increment, right subtree gets high+1, but both should be high+1. Also post-increment affects subsequent calls.
    return;
}