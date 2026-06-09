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
        p->height=fa->height+1; // @@ [When inserting the first node after root, 'fa' may be NULL (as 'head' is initialized to NULL), leading to undefined behavior when accessing 'fa->height'. Also, the insertion logic for duplicates is incorrect: it should go to the right subtree per problem description, but here '<=' sends duplicates to the left.]
    } 
    else if( item <= p->data) // @@ [According to the problem, values equal to the root should go to the RIGHT subtree, but this condition sends them to the LEFT. This causes incorrect tree structure and thus wrong leaf identification.]
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
    BTNodeptr head=root; // @@ ['head' is set to NULL here, and then passed as 'fa' when inserting the root's children. In insertBST, when creating a new node, 'fa->height' is accessed even though 'fa' (i.e., 'head') is NULL, causing undefined behavior.]
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head;
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ ['head' is always NULL, so every recursive call passes a NULL 'fa' for the root level. This breaks height calculation for all nodes beyond root. Also, passing 'head' (NULL) instead of current parent 'p' prevents correct height propagation.]
    }
    preorder(root);
    return 0;
}