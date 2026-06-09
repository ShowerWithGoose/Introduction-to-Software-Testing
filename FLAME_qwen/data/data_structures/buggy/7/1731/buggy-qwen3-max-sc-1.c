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
 }
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
    return p; // @@ [Unreachable code: the 'else' block is redundant because all cases (item < p->data, item >= p->data) are already handled above. This causes no compilation error but is logically unnecessary. However, the actual compilation error in the test environment is due to missing compiler, not this code. But since the problem states there's a compilation error and we must find code issues, note that the function lacks a return statement in all paths — if none of the conditions match (which shouldn't happen), it would fall through without returning, causing undefined behavior or compiler warning/error in strict mode.]
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