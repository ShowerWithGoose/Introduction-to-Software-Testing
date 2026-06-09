#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    int height;
    struct node *left, *right,*father;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,BTNodeptr fa, int item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->father=fa;
        p->data = item;
        p->left = p->right = NULL;
        p->height=fa->height+1; // @@ [Error: When fa is NULL (head), accessing fa->height causes a segmentation fault or undefined behavior. The root node's height should be set to 1 in main, but for subsequent insertions, fa should be the parent node. However, the initial call with head (which is NULL) will crash. Additionally, the logic for setting height is flawed because the tree structure is not correctly maintained due to the way root is reassigned.]
    } 
    else if( item <= p->data)
        p->left = insertBST(p->left,p, item);
    else 
       p->right = insertBST(p->right,p,item);
    return p;
}
void  preorder(BTNodeptr t)
{
      if(t!=NULL){
            if(t->left==NULL&&t->right==NULL)
            {
                printf("%d %d\n",t->data,t->height);
            }
             preorder(t->left);
             preorder(t->right);
       }
}

int main()
{
    int n,item;
    scanf("%d",&n); 
    BTNodeptr root=NULL;
    BTNodeptr head=root; // @@ [Error: head is set to NULL (since root is NULL), and later used as the father for the root node, causing issues in insertBST when accessing fa->height.]
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head; // @@ [Error: head is NULL, so root->father is NULL, which is incorrect. The root should have no father or be set to NULL, but then insertBST will crash when trying to access fa->height for the first insertion.]
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ [Error: The root is reassigned each iteration, losing the original tree structure. The insertBST function should return the updated tree, but the root should remain the same overall root. Additionally, passing head (NULL) as fa causes crashes.]
    }
    preorder(root);
    return 0;
}