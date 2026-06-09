#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} tree;
tree *first;

tree *create(tree *root, int in, int len); //新建节点
void print(tree *root);                   //打印叶节点
int is_leaf(tree *root);
int main()
{
    tree *root = NULL;
    int n, in;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) //创建树
    {
        scanf("%d", &in);

        int len = 0;
        root = create(root, in, len);
    }
    print(root);
    return 0;
}
tree *create(tree *root, int in, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = in;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (in < root->data)
        root->left = create(root->left, in, len);
    else if (in >= root->data)
        root->right = create(root->right, in, len);
    return root;
}

void print(tree *root)
{
    if (root)
    {
        if(is_leaf(root)){
			printf("%d %d\n", root->data, root->high);
		}
		print(root->left);
        print(root->right);
    }
}
int is_leaf(tree *root)
{
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
        return 0;
    }
}    

