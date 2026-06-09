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
        p->height=fa->height+1; // @@ [Error: When inserting the first node after root, fa is head (NULL), causing a segmentation fault because fa->height dereferences a NULL pointer. The height should be set based on the parent node's height, but fa is not the parent in this context.]
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
    BTNodeptr head=root; // @@ [Error: head is initialized to NULL, and later used as the father for the root node, but root->father=head sets father to NULL, which is fine. However, head is never updated to point to the actual root, so when insertBST is called with head as fa, it passes NULL, causing the crash in insertBST.]
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head; // @@ [Error: head is NULL, so root->father is set to NULL, which is acceptable, but the logic is flawed because head is not the actual parent.]
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ [Error: After the first insertion, root is reassigned to the result of insertBST, which returns the new root of the subtree, but this overwrites the original root pointer, causing the tree structure to be lost. Also, head is still NULL, causing the crash in insertBST.]
    }
    preorder(root);
    return 0;
}