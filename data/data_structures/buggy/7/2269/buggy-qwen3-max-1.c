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
    tree1 root,*p,*q,*r; // @@ [The variable 'root' is a local stack-allocated struct, but the code later uses pointers like 'r = &root' and inserts dynamically allocated nodes as children. However, when inserting the first child, it assigns to 'r->left' or 'r->right', which is valid. The real issue is in the loop logic and pointer updates.]
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
        { i++;
          if(x>r->data)
          {
              if(q==NULL)
              {
                  q=(tree1 *)malloc(sizeof(root)); // @@ [Using 'sizeof(root)' is incorrect; should be 'sizeof(tree1)' or 'sizeof(*q)'. 'root' is a struct instance, not a type, but this may still compile. However, more critically, after allocating 'q', it's assigned to 'r->right', but in subsequent iterations, 'q' is not updated correctly relative to the current 'r'.]
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
                  p=(tree1 *)malloc(sizeof(root)); // @@ [Same issue: 'sizeof(root)' should be 'sizeof(tree1)'. Also, similar logic flaw in pointer tracking.]
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