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
    tree1 root,*p,*q,*r; // @@ [The variable 'root' is a local stack-allocated struct, but the code later takes its address and treats it as part of a dynamically built tree. This causes issues when inserting nodes because the root itself is not dynamically allocated, yet child pointers are assigned to heap memory. More critically, in the insertion loop, 'r' is set to '&root', but then 'r' is reassigned to point to heap-allocated nodes (like p or q), which breaks the traversal logic. Also, initial height assignment assumes root height is 1, but during insertion, height is incremented before checking children, leading to off-by-one errors.]
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
        i=1;
        while(r!=NULL)
        { i++; // @@ [The height 'i' is incremented at the start of the loop, assuming we are moving to a child. However, for the first comparison (root level), i becomes 2 immediately, which incorrectly sets the height of direct children to 2 instead of 2 being correct? Wait: root height is 1, so its children should be height 2 — that seems okay. But the real issue is that 'i' is incremented even when we haven't moved yet. Actually, the increment happens before we decide to go left/right, so when we finally insert, 'i' is one more than the parent's height, which is correct. However, the bigger problem is in pointer management.]
          if(x>r->data)
          {
              if(q==NULL)
              {
                  q=(tree1 *)malloc(sizeof(root)); // @@ [Using 'sizeof(root)' where 'root' is a struct instance is acceptable, but it's clearer to use 'sizeof(tree1)'. However, this is not the main error. The critical flaw is that 'q' is a local pointer; assigning 'r->right = q' works, but in the next iteration of the while loop, the updates to p and q are based on stale or incorrect assignments. Specifically, after setting r = q (or r = p), the code sets p = r->left and q = r->right, but if r was just updated to a new node, those may be NULL, causing early exit or incorrect traversal. Moreover, the loop condition 'while(r != NULL)' combined with immediate increment of 'i' leads to accessing NULL pointers or incorrect height calculation.]
                  q->data=x;
                  q->i=i;
                  q->left=NULL;
                  q->right=NULL;
                  r->right=q;
                  //printf("%d %d ",q->data,q->i);
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
                  p=(tree1 *)malloc(sizeof(root));
                  p->data=x;
                  p->i=i;
                  p->left=NULL;
                  p->right=NULL;
                  r->left=p;
                  //printf("%d %d ",p->data,p->i);
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