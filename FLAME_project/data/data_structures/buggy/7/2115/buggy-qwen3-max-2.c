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
        p->height=fa->height+1; // @@ [When inserting the first node after root, 'fa' may be NULL (as passed from main), leading to undefined behavior when accessing 'fa->height'. Also, the BST insertion logic uses 'item <= p->data' for left, but problem requires left child < root and right >= root. This condition reverses the correct comparison.]
    } 
    else if( item <= p->data) // @@ [Incorrect BST condition: should be 'item < p->data' for left subtree per problem description. Using '<=' causes equal values to go left, but they should go right.]
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
    BTNodeptr head=root; // @@ ['head' is set to NULL here, and then passed as 'fa' (father) when inserting subsequent nodes. When inserting the second node, 'fa' is NULL, so in insertBST, 'fa->height' dereferences a NULL pointer, causing undefined behavior. Additionally, the first node is handled separately but the loop starts from i=1, which is okay, but the initial 'head' should not be NULL when used as parent of root's children.]
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head;
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ ['head' is always NULL, so every recursive call to insertBST passes a NULL 'fa' for the root level, but deeper levels pass correct parent. However, the real issue is that 'head' should not be used; instead, when calling insertBST for the first time in the loop, the 'fa' should be NULL only for the root, but the function expects non-NULL 'fa' when creating new nodes (due to 'fa->height'). Also, the root is already created, so insertBST should be called with 'root' and its actual parent (which for root is NULL), but the current design mishandles this.]
    }
    preorder(root);
    return 0;
}