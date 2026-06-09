#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int data;
    struct node *left, *right;
    int depth;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, int item, int depth);
void inorder(BTNodeptr p)
{
    if(p!=NULL){
        inorder(p->left);
        if(p->left==NULL && p->right==NULL)
        {
            printf("%d %d\n",p->data,p->depth);
        }   
        inorder(p->right);
    }
}
int main()
{
    int i, item, n;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(i=0; i<n; i++)
    { 
        scanf("%d", &item);
        root = insertBST(root, item,1);
    }
    inorder(root);
    return 0;
}
BTNodeptr insertBST(BTNodeptr p, int item, int depth)
{
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->depth = depth;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item, depth+1);
    else if( item > p->data)
       p->right = insertBST(p->right,item,depth+1);
    else
        ; // @@ [When item == p->data, the function does nothing and returns the unchanged node, causing duplicate values to be ignored. According to the problem, right child should include values >= root, but this code only inserts when item > p->data, thus violating BST insertion rule for equal values.]
    
    return p;
}