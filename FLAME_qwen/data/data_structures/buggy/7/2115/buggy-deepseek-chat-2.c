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
        p->height=fa->height+1; // @@ [Error: When fa is NULL (head), accessing fa->height causes a segmentation fault. The root's height should be set separately, and for other nodes, fa should be the parent node, not head.]
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
    BTNodeptr head=root; // @@ [Error: head is assigned NULL here, and later used as father for root, causing issues in insertBST when fa is NULL.]
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head; // @@ [Error: head is NULL, so root->father is NULL, which is not a valid node pointer.]
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ [Error: Passing head (NULL) as fa to insertBST, causing fa->height access to crash. Also, root is reassigned each iteration, losing the original tree structure.]
    }
    preorder(root);
    return 0;
}