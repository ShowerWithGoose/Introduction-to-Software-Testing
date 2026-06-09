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
    tree1 root,*p,*q,*r; // @@ [root is a local variable of type tree1, but it's used as if it were dynamically allocated; when passing &root to order(), its children may be overwritten incorrectly during insertion logic]
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
        { i++; // @@ [i is incremented at the start of the loop, which causes height to be overcounted; height should only increase when moving to a child, not before checking]
          if(x>r->data)
          {
              if(q==NULL)
              {
                  q=(tree1 *)malloc(sizeof(root)); // @@ [sizeof(root) is sizeof(tree1), which is correct, but style-wise sizeof(*q) is safer; however, this is not the main bug]
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
                  p=(tree1 *)malloc(sizeof(root)); // @@ [same as above, not critical]
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