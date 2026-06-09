#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef int Datatype;
struct node
 {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr root=NULL;
int  heightTree(BTNodeptr s,BTNodeptr p)
{   int d=1;
    int j=p->data;
    if (s== NULL) 
    return 0; 
    else
    {while(s!=p&&s!=NULL)
    { d++; 
      if(j>=s->data)
      s=s->right;     
      else if(j<s->data) 
      s=s->left;           
    }   
    return d; 
   }
 } // @@ [The height calculation is incorrect because it assumes the path from root to node `p` can be reconstructed by comparing `j` (value of `p`) with nodes along the way. However, duplicate values or structural changes due to insertion order may cause this search to fail or take a wrong path, leading to incorrect height. Also, height should be computed during tree traversal, not via a separate search.]

void  inorder(BTNodeptr t)
{
      if(t!=NULL)
      {
             inorder(t->left);
             if(t->left==NULL&&t->right==NULL)
             printf("%d %d\n",t->data,heightTree(root,t));   
             inorder(t->right);
    }
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL)
    {
        p =(BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left =p->right=NULL;
    } 
    else if( item<p->data)
        p->left=insertBST(p->left, item);
    else if( item>=p->data)
        p->right=insertBST(p->right,item);
    else
    return p; // @@ [This `else` block is unreachable because all cases (`<`, `>=`) are already handled above. Moreover, it returns `p` without doing anything, but since the condition is never met, it's dead code. However, the real issue is that the function lacks a final `return p;` in all paths — specifically, after the `else` block, there's no return, which leads to undefined behavior when the `else` is entered (though it shouldn't be). But more critically, the function must always return `p` at the end.]
} 

int main()
{ 
    int i,n,item;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    { 
        scanf("%d",&item);
        root = insertBST(root,item);
     }
    inorder(root); 
    return 0;
}