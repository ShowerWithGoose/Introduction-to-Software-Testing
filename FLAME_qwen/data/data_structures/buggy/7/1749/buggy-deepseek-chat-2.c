#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
#define Nodenum 1000

typedef struct DATA{
    DataType num;
    DataType height;
} DATA;

typedef struct node{
    DATA data;
    struct node *left, *right;
} BTNode, *BTNodePtr;

void VISIT(BTNodePtr t)
{
    printf("%d %d\n", t->data.num, t->data.height);
    return;
}

/*--------------------------二叉搜索树（排序树）的插入算法------------------------------*/
/*递归算法：将一个数据元素item插入到根指针为root的二叉排序树中*/
BTNodePtr insertBST(BTNodePtr p, DataType item)
{
    if(p == NULL){
        p = (BTNodePtr)malloc(sizeof(BTNode));
        p->data.num = item;
        p->data.height = 1; // @@ Error: The height of every new node is set to 1, but the problem requires the root height to be 1 and child heights to be parent height + 1. This should be set based on the parent's height, not always 1.
        p->left = p->right = NULL;
    }
    else if(item < p->data.num)
        p->left = insertBST(p->left, item);
    else if(item > p->data.num)
        p->right = insertBST(p->right, item);
    /*else
        do-something  树中存在该元素*/
    return p;
}

/*--------------------------二叉树的中序遍历算法------------------------------*/
void inorder(BTNodePtr t)
{
    if(t != NULL){
        
        if(t->left != NULL)
            t->left->data.height = t->data.height + 1;

        if(t->right != NULL)
            t->right->data.height = t->data.height + 1;

        inorder(t->left);
        
        if(t->left == NULL && t->right == NULL) VISIT(t);  /*访问t指向结点*/
        
        inorder(t->right);
        
    }
}

int main()
{
    int i, n, item;
    BTNodePtr root = NULL;
    
    scanf("%d",&n);
    
    for(i = 1; i <= n; i++){
        scanf("%d",&item);
        root = insertBST(root, item);
    }
    
    inorder(root);
    
    return 0;
}