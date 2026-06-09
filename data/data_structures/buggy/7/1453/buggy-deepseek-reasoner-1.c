#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义二叉树的结构
typedef struct binary_tree
{
    int data;                  // 节点保存的数据
    struct binary_tree *left;  // 定义左节点指针
    struct binary_tree *right; // 定义右节点指针
} node;

void insert(node **tree, int gain);//初始化二叉树
void deltree(node* tree);//释放节点内存
void leader(node* tree);//前序遍历
void inorder(node* tree);//中序遍历
void lastder(node* tree);//后序遍历
void print(node* tree,int shen);//只遍历叶节点

int main(){
    node* root;
    root = NULL;
    int n,gain;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&gain);
        insert(&root,gain);
    }
    print(root,1);
    return 0;
}

//初始化二叉树
void insert(node **tree, int gain){
    node *temp = NULL;
    if (!(*tree)) //判断根节点是否存在
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL; //左右节点制空
        temp->data = gain;
        *tree = temp;
        return;
    }
    if (gain < (*tree)->data) //判断是左子树
    {
        insert(&(*tree)->left, gain); //等价于 &((*tree)->left)，创建左子树
    }
    else if (gain > (*tree)->data) //判断是右子树 // @@ [Error: Duplicate values (gain == data) are not inserted, but the problem requires right child to be >= root. Should be 'else' to include equal case.]
    {
        insert(&(*tree)->right, gain); //等价于 &((*tree)->right)，创建右子树
    }
}

//释放节点内存
void deltree(node* tree){
    if (tree){
        deltree(tree->left);//先往左子树一直寻找
        deltree(tree->right);//再往右子树一直寻找
        free(tree); //找不到了free返回上一级
    } 
}

//前序遍历
void leader(node* tree)
{
    if (tree){
        printf("%d\n", tree->data);
        leader(tree->left);
        leader(tree->right);
    }
}
 
//中序遍历
void inorder(node* tree){
    if (tree) {
        inorder(tree->left);
        printf("%d\n", tree->data);
        inorder(tree->right);
    } 
}
 
//后序遍历
void lastder(node* tree){
    if (tree) {
        lastder(tree->left);
        lastder(tree->right);
        printf("%d\n", tree->data); 
    }
}

void print(node* tree,int shen){
    if(tree&&tree->left==NULL&&tree->right==NULL){
        printf("%d %d\n",tree->data,shen);
    }
    if(tree){
        print(tree->left,shen+1);
        print(tree->right,shen+1);
    }
}