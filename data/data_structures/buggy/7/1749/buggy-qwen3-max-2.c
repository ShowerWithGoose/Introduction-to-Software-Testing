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
        p->data.height = 1;
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
            t->left->data.height = t->data.height + 1; // @@ [The height of child nodes is updated during traversal, but this update happens before visiting left subtree. However, if a node has both left and right children, the right child's height may be set correctly, but if the tree is built with duplicate values (>= goes right), and duplicates exist, they are ignored in insertion (only > inserts right), which contradicts problem statement requiring >= to go right. Also, more critically: height propagation during inorder traversal is flawed because when recursing into left subtree, the left child's height is set, but when that left child itself has children, their heights are not updated until their parent is processed in inorder, leading to incorrect heights for deeper nodes.]

        if(t->right != NULL)
            t->right->data.height = t->data.height + 1; // @@ [Same issue as above: height assignment during inorder traversal does not guarantee that all descendants have correct heights because the traversal order doesn't propagate height from root downward before processing subtrees. Height should be assigned during insertion, not during traversal.]

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