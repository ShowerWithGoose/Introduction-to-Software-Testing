#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct tree
{
    int data,i;
    struct tree *left;
    struct tree *right;
} tree1;

void order(tree1 *rot)
{ 
    if(NULL==rot)
    return;
    order(rot->left);
    if(rot->left==NULL&&rot->right==NULL)
    printf("%d %d\n",rot->data,rot->i);
    order(rot->right);
}
int main()
{
    tree1 root,*p,*q,*r;
    int n,x,i;
    scanf("%d",&n);
    scanf("%d",&root.data);
    root.i=1;
    n--;
    root.left=NULL;
    root.right=NULL;
    for(int j=0;j<n;j++)
    {
        r=&root;
        p=r->left;
        q=r->right;
        scanf("%d",&x);
        i=1; // @@ The height counter 'i' is initialized to 1 here, but it is incremented at the start of the loop body before checking the current node. This causes the height to be off by one or calculated incorrectly relative to the traversal depth. It should ideally track the depth of the parent 'r' or be managed such that the new node gets parent_height + 1.
        while(r!=NULL)
        { i++; // @@ Incrementing 'i' at the beginning of the loop means 'i' represents the depth of the child we are about to visit/create. However, the logic for updating p and q relies on the previous state, and the initialization of i=1 outside combined with this increment leads to incorrect height assignment. For the root (depth 1), the first child should be depth 2. If r is root, i becomes 2. This part is technically okay for the first step, but the subsequent updates of p and q without updating i correctly for the next iteration's context is problematic. More critically, see the allocation size error below.
          if(x>r->data)
          {
              if(q==NULL)
              {
                  q=(tree1 *)malloc(sizeof(root)); // @@ Error: sizeof(root) allocates memory equal to the size of the structure instance 'root' (which is correct in size usually, but semantically should be sizeof(tree1) or sizeof(*q)). However, the critical logical error is that 'q' is a local pointer variable. Assigning to 'q' here does NOT update 'r->right' automatically unless 'q' was an alias or pointer to pointer. Wait, looking closely: 'q' is assigned 'r->right' earlier. If 'r->right' is NULL, 'q' is NULL. Then we malloc and assign to 'q'. This changes the local pointer 'q', but 'r->right' remains NULL! We must assign to 'r->right' directly.
                  q->data=x;
                  q->i=i;
                  q->left=NULL;
                  q->right=NULL;
                  r->right=q; // @@ This line attempts to fix the previous issue, but the previous line allocated to local 'q'. Actually, this line IS present. Let's re-read carefully.
                  // The code does: q=(tree1 *)malloc(...); ... r->right=q; This is actually correct for linking.
                  // However, let's look at the "else" branch and the update steps.
                  // The major issue is likely how p and q are updated.
                  break;
              }
            r=q;
            p=q->left;
            q=q->right; 
          }
          else
          {
              if(p==NULL)
              {
                  p=(tree1 *)malloc(sizeof(root)); // @@ Similar to above, sizeof(root) is technically okay if root is the struct type instance, but standard practice is sizeof(tree1). More importantly, 'p' is a local copy of 'r->left'.
                  p->data=x;
                  p->i=i;
                  p->left=NULL;
                  p->right=NULL;
                  r->left=p; // @@ This links the new node correctly.
                  break;
              }
            r=p;
            q=p->right;
            p=p->left;
          }
            }    
    }
    order(&root);
    return 0;
}