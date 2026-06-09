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
             printf("%d %d\n",t->data,heightTree(root,t));   // @@ [The height calculation is incorrect because it assumes the path from root to node always follows BST search logic based on the node's value, but duplicate values or structural changes may cause mismatches. Also, the height should be computed during traversal, not by re-searching.]
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
    return p;  // @@ [This 'else' block is unreachable because all cases (item < p->data and item >= p->data) are already handled above. It should be removed or replaced with a proper duplicate handling if needed, but more critically, the function must always return a value; in this case, it does return p in all paths, but the redundant else may confuse logic. However, the main bug is in heightTree, not here.]
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