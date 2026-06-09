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
    tree1 root,*p,*q,*r; // @@ [Using 'tree1 root' as a local variable on the stack leads to undefined behavior when taking its address and treating it as a dynamically allocated node; also, 'root' is not initialized properly before use in pointer assignments]
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
                  q=(tree1 *)malloc(sizeof(root)); // @@ [sizeof(root) is sizeof(tree1), which is correct, but using 'root' (a stack variable) in sizeof is misleading; better to use sizeof(tree1) or sizeof(*q). However, this is not the main error.]
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
                  p=(tree1 *)malloc(sizeof(root)); // @@ [Same as above: sizeof(root) is acceptable but confusing; however, the real issue is logic and initialization]
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