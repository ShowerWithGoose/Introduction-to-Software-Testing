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
        i=1;
        while(r!=NULL)
        { i++;
          if(x>r->data) // @@ Error: The condition should be x >= r->data to match the problem's requirement that right child values are greater than or equal to the root. Using > causes equal values to go left instead of right, leading to incorrect tree structure and missing leaf node 87.
          {
              if(q==NULL)
              {
                  q=(tree1 *)malloc(sizeof(root));
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