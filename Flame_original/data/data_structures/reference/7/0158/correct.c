#include<stdio.h>
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} tree;
tree *first; 
tree *root;
tree *newtree(tree *root,int temp,int len);
void print(tree *root)
{if(root)
{
 if(root->left ==NULL&&root->right ==NULL)
 printf("%d %d\n",root->data ,root->high );
 print(root->left );
 print(root->right );
 }
 }
 
 
 
 
 
int main()
{int n,i,j,temp,len;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {scanf("%d",&temp);
 len=0;
 root=newtree(root,temp,len) ;
 }
 print(root);
 return 0;
  }
  
  
  
  
  tree *newtree(tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = temp;
        root->left = root->right = NULL;
        root->high = len;
    }
    else if (temp < root->data)
        root->left = newtree(root->left, temp, len);
    else if (temp >= root->data)
        root->right = newtree(root->right, temp, len);
    return root;
}

