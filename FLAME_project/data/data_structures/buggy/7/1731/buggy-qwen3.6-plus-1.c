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
      if(j>=s->data) // @@ The condition for traversing right should be strictly greater than (>) because the problem states left child < root and right child >= root. If j == s->data, it should have gone right at that node, but since we are searching for a specific node p, if j == s->data and s != p, it implies p is in the right subtree. However, the standard BST property here is Left < Root <= Right. When searching, if target >= current, go right. If target < current, go left. The logic `j>=s->data` sends equal values to the right. This matches the insertion logic. Wait, let's re-read carefully. Insertion: `item < p->data` -> left, `item >= p->data` -> right. Search: `j >= s->data` -> right, `j < s->data` -> left. This seems consistent. Let's look closer at the failure.
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
    return p;
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