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
        i=1; // @@ The height counter 'i' is initialized to 1 here, but it should represent the height of the current node 'r'. Since the loop increments 'i' before processing the child, and the root is at height 1, the initial value for the root's children calculation should effectively start such that the first step results in height 2. However, the logic inside the loop increments 'i' immediately. Let's trace: Root is height 1. When we go to a child, height becomes 2. The loop starts with r=root. i=1. Inside loop: i++ -> i=2. If we attach, height is 2. This seems correct for the first level. But wait, the variable 'i' is used to store the height of the *new* node being created. 
        while(r!=NULL)
        { i++;
          if(x>r->data) // @@ The problem states: "value of the left child is less than the value of the root, and the value of the right child is greater than or equal to the value of the root". This condition uses strict greater than for right, implying equal goes to left? No, if x > r->data, it goes right. If x <= r->data, it goes left. The reference code uses `if(data < q->num) left else right`. This means if data >= num, it goes right. The buggy code uses `if(x > r->data) right else left`. This means if x <= r->data, it goes left. This matches the reference logic (Left < Root, Right >= Root). So this comparison is actually correct based on the reference. Wait, let's re-read carefully. Reference: `if(data<q->num) t=q; q=q->left; else t=q; q=q->right;`. So if data < num, go left. If data >= num, go right. Buggy: `if(x>r->data) { ... right ... } else { ... left ... }`. So if x > data, go right. If x <= data, go left. This is consistent. 
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