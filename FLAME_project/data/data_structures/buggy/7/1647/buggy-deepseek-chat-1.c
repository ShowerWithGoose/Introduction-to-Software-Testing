#include<stdio.h>
#include<stdlib.h>
typedef struct bstTree{
    int data;
    struct bstTree *lChild,*rChild;
}node;
typedef node* bst;

bst insert(bst root , int num)//每次都从根结点往下比较递归
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = num;
        root->lChild = NULL;
        root->rChild = NULL;
        return root;//如果在if里面，就可以直接返回了
    }
    else
    {
        if(num > root->data)
        {root->rChild = insert(root->rChild,num);}
        else
        {root->lChild = insert(root->lChild,num);} // @@ [Error: The condition should be `num >= root->data` for the right child, but here `num > root->data` is used for the right child and `else` (including `num == root->data`) goes to the left child. According to the problem, values greater than or equal to the root should go to the right child, so equal values should go to the right, not the left. This causes the BST structure to differ, leading to incorrect leaf heights and missing leaf nodes like 87.]
        return root;
    }//在else里面child的值被改变为insert，需要传到上一层函数才能保证已经有了改变的值
}

void printLeaves(bst root,int height)
{
    if(root->lChild==NULL && root->rChild==NULL)
    {
        printf("%d %d\n",root->data,height);
        //printf("1");
        return ;
    }
    else
    {
        if(root->lChild!=NULL)
        {
            printLeaves(root->lChild,height+1);
        }
        if(root->rChild!=NULL)
        {
            printLeaves(root->rChild,height+1);
        }
    }
}

int main()
{
    int i,n,number;
    bst root = NULL;
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&number);
        root = insert(root , number);
    }
    printLeaves(root,1);
    return 0;
}