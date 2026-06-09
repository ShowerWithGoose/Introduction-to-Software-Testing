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
    if(p->lchild!=NULL) printleaves(p->lchild,high++); // @@ [The post-increment operator high++ passes the current value of high to the recursive call, then increments high. This means the right child call will use the incremented value, but the left child call should use the same high value. Use high+1 instead to pass the correct depth.]
    if(p->rchild!=NULL) printleaves(p->rchild,high++); // @@ [Same issue: high++ passes the current value (which may have been incremented by the previous line) and then increments again. This causes incorrect depth for the right child. Use high+1 to pass the correct depth.]
    return;
}