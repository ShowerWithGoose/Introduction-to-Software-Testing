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
    return p; // @@ [Unreachable code: The 'else' block is unnecessary because all cases (item < p->data and item >= p->data) are already handled above. This causes no compilation error but is logically redundant. However, the actual compilation error in the test environment ("gcc: not found") is external and not due to this code. But since the problem states there's a compilation error and we must find code-level issues, note that the function lacks a return statement in all paths — specifically, if none of the conditions match (which shouldn't happen), it would fall through without returning. However, more critically, the function does return in all logical paths, so this may not be the issue. Yet, some compilers may warn or error if control reaches end of non-void function. But the real issue causing "gcc not found" is environmental. However, per instructions, we must annotate code errors. The true semantic error is that heightTree assumes the node `p` exists in the tree rooted at `s`, but during traversal, `p` is always in the tree, so that's okay. The main logical flaw is inefficiency and potential infinite loop if tree structure changes, but not compilation. Given the constraints, the only plausible code-related issue that could cause unexpected behavior (though not compilation error) is the missing return in one path — but actually, all paths do return. Wait: the last `else` is unreachable, but the function ends without a return after the if-else chain? No: the first if handles p==NULL and returns via assignment, then two else ifs, then an else that returns p. But what if none of the else ifs trigger? They cover all cases: item < data, item >= data. So the final else is dead code. However, the compiler might not know that and may think there's a path without return. In C, falling off a non-void function is undefined behavior and may cause compilation error with strict settings. So the function should return p at the end unconditionally.]
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