#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
typedef long long ll;
typedef struct node{
    int data;
    struct node *left,*right;
} BSTNode,*BSTNodeptr;
BSTNodeptr root = NULL;
BSTNodeptr insert(int tmp,BSTNodeptr root)
{
    if(root == NULL)
    {
        root = (BSTNodeptr)malloc(sizeof(BSTNode));
        root->data = tmp;
        root->left = root->right = NULL;
        return root;
    }
    if(tmp >= root->data)
    {
        root->right = insert(tmp,root->right);
    }
    else
    {
        root->left = insert(tmp,root->left);
    }
    return root;
}
bool judge(BSTNodeptr root)
{
    return (root->left == NULL && root->right == NULL);
}
int searchheight(int data)
{
    int height = 0;
    BSTNodeptr tmp = root;
    while(!judge(tmp))
    {
        if(data >= tmp->data) tmp = tmp->right;
        else tmp = tmp->left;
        height++;
    }
    return height+1;
}
void traversal(BSTNodeptr root)
{
    if(root!=NULL)
    {
        traversal(root->left);
        if(judge(root) == true)
        {
            int height = searchheight(root->data);
            printf("%d %d\n",root->data,height);
        }
        traversal(root->right);
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        root = insert(tmp,root);
    }
	traversal(root);
	return 0;
} 


