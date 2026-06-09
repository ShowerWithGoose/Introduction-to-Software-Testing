#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
 struct tree
{
    int data;
    int high;
    struct tree *left, *right;
} ;
struct tree *first;
struct tree *New(struct tree *root, int tmp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (struct tree *)malloc(sizeof(struct tree));
		root->left = root->right = NULL;
		root->data = tmp;
        first = root;
        root->high= len;
    }
    else if (tmp < root->data)
        root->left = New(root->left, tmp, len);
    else if (tmp >= root->data)
        root->right = New(root->right, tmp, len);
    return root;
}
//新建节点
void print(struct tree *root)
{
    if (root!=NULL)
    {
        print(root->left);
        print(root->right);
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
    }
}                //打印叶节点
int main()
{
    int n,tmp;
    struct tree *root = NULL;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) //创建树
    {
    	int len = 0;
        scanf("%d", &tmp);  
        root = New(root, tmp, len);
    }
    print(root);
    return 0;
}



