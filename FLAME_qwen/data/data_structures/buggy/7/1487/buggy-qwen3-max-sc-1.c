#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef int Datatype;
struct node
{
    Datatype data;
    struct node *left, *right;
 };
typedef struct node BTNode; 
typedef struct node *BTNodeptr; 
int depth=1; // @@ [Using a global variable 'depth' for tracking node height is incorrect because it doesn't reflect the actual depth of each node during traversal; it gets modified globally during recursion, leading to wrong height values for leaf nodes.]

BTNodeptr insert(BTNodeptr root, Datatype num)//种树 (->
{
    if(root==NULL)//找坑 
    {
        root=(BTNodeptr)malloc(sizeof(BTNode));//开空间 
        root->data=num;
        root->left=root->right=NULL;
    }
    else if(num<root->data)//比节点小：往左建立连接 
    {
        root->left=insert(root->left, num);
    }
    else if(num>root->data)//比节点大：往右建立连接
    {
        root->right=insert(root->right, num);
    } 
    
    return root;
}

void pre_tree(BTNodeptr root)//前序遍历 
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)//找到叶 
        {
            printf("%d %d\n", root->data, depth); // @@ [Printing global 'depth' instead of the actual depth of the current node. The global 'depth' does not correctly represent the height of the current leaf node due to shared state across recursive calls.]
        }
        
        depth++; // @@ [Incorrectly incrementing a global 'depth' before recursing; this affects all recursive paths and leads to inconsistent depth tracking. Depth should be passed as a parameter.]
        
        pre_tree(root->left);//左右递归查找 
        pre_tree(root->right);

        depth--; // @@ [Decrementing global 'depth' after recursion, but this still fails to maintain correct per-path depth because multiple branches interfere with the same global variable.]
        
    }
}

int main()
{
    int n, i;
    Datatype num;
    BTNodeptr root=NULL;
    
    scanf("%d", &n);
    for(i=0;i<n;i++)//种树 
    {
        scanf("%d", &num);
        root=insert(root, num);
    }
    
    pre_tree(root);
    
    return 0;
}