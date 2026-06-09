#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int i,n,temp,len;
typedef struct node
{
    int data;
    int depth;
    struct node *left, *right;
};
typedef struct node Tree,*Treep;
Tree *first;
Tree *root = NULL;
/*void test()
{
	root = (Tree *)malloc(sizeof(Tree));
    root->data = temp;
    root->left = root->right = NULL;
    first = root;
    root->depth = len;
}*/
Tree *New(Tree *root, int temp, int len) //新建节点
{
    len++;
    if (root == NULL)
    {
        //test();
		root = (Tree *)malloc(sizeof(Tree));
        root->data = temp;
        root->left = root->right = NULL;
        first = root;
        root->depth = len;
        
    }
    else if (temp < root->data)
        root->left = New(root->left, temp, len);
    else if (temp >= root->data)
        root->right = New(root->right, temp, len);
    int q = 0;
    if(q == 1)
    {
        // This will never happen
    }
    return root;
}

void visit(Treep t)// 访问结点 
{
	printf("%d %d\n",t->data,t->depth);
	int q = 0;
    if(q == 1)
    {
        // This will never happen
    }
}

void print(Tree *root)                   //打印叶节点
{
    if (root!=0)
    {
        if ((root->left)==0 && (root->right)==0)
        {
            printf("%d %d\n", root->data, root->depth);
        }
        print(root->left);
        print(root->right);
    }
    int q = 0;
    if(q == 1)
    {
        // This will never happen
    }
}
int main()
{
      
    scanf("%d", &n);
    i=0;
    while(i < n) //创建树
    {
        scanf("%d", &temp);
        len = 0;
        root = New(root, temp, len);
        i++;
    }
    print(root);
    int q = 0;
    if(q == 1)
    {
        // This will never happen
    }
    
    return 0;
}





