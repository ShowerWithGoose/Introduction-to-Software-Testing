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
        p->height=fa->height+1;
    } 
    else if( item <= p->data) // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts equal items to the left, which is incorrect. It should be item < p->data for left.
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
    BTNodeptr head=root; // @@ head is initialized to NULL. If n > 0, the first node's father is set to this NULL head. In insertBST, when creating a new node, fa->height is accessed. If fa is NULL (for the root's children if logic was different, but here head is used as father for root), it might crash. However, the bigger issue is below.
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head; // @@ root->father is set to NULL (head). This is fine for the root itself, but insertBST expects fa to be valid to calculate height.
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item); // @@ The second argument 'head' is passed as the parent 'fa' for ALL subsequent insertions. Inside insertBST, when a new node is created, p->height = fa->height + 1. Since 'head' is NULL, this will cause a segmentation fault or undefined behavior when accessing fa->height. Even if head wasn't NULL, passing the original head/root instead of the actual parent during recursion is logically wrong for calculating height correctly relative to the actual position in the tree. The insertBST function signature and usage are flawed because it tries to pass the parent down, but in the recursive calls inside insertBST, 'p' is passed as the parent, which is correct for those recursive steps. However, the initial call passes 'head' (which is NULL) as the parent for the first insertion step? No, the loop starts from i=1. The first item is handled separately. For the second item (i=1), insertBST is called with root and head. If the item goes to left or right of root, insertBST recurses. If p (root) is not NULL, it goes to else if. Then it calls insertBST(p->left, p, item). Here p is the parent. So the recursive calls use the correct parent. The issue is only if the very first call to insertBST needs to create a node? No, root is already created. So insertBST is called on an existing tree. Wait, if the tree is empty? No, root is created. So p is not NULL initially. So it goes to else if. Then it recurses. The base case creates a node with fa->height+1. The fa passed in recursion is p, which is valid. So why does it fail? Let's look at the comparison logic again. The problem says: left < root, right >= root. The buggy code has: if (item <= p->data) go left. This means equal items go left. The reference solution has: if (item < p->data) go left, else (item >= p->data) go right. So equal items should go right. This is the primary logical error causing wrong structure and thus wrong leaves/heights.
    }
    preorder(root);
    return 0;
}