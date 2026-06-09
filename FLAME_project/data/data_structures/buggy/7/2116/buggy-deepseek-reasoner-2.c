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
        printf("ERROR\n"); // @@ [Inappropriate error message; a null pointer is not an error condition and should not produce output. This line could be removed.]
        return;
    }
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->data,high);
    }
    if(p->lchild!=NULL) printleaves(p->lchild,high++); // @@ [Incorrect depth propagation: post-increment passes current high to left child, then increments local high, causing left child to receive one less than the correct depth. Should be high+1.]
    if(p->rchild!=NULL) printleaves(p->rchild,high++); // @@ [Incorrect depth propagation: because high was already incremented by the previous call, the right child receives high+1 (which is parent's depth+2). Both children should receive parent's depth+1, i.e., high+1 for both.]
    return;
}