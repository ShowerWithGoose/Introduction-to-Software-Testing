#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
	int d;
	int high;
	struct node *left, *right;
} Tree;
void print(Tree *root);
Tree *first;
Tree *New(Tree *root, int temp, int len);
int main(){
	Tree *root = NULL;
	int n,t,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		int len=0;
		len++;
		root = New(root, t, len);
	}
	print(root);
	return 0;
}
Tree *New(Tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->d = temp;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (temp < root->d)
        root->left = New(root->left, temp, len);
    else if (temp >= root->d)
        root->right = New(root->right, temp, len);
    return root;
}
void print(Tree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->d, root->high-1);
        }
        print(root->left);
        print(root->right);
    }
}




