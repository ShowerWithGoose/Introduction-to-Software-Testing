#include<stdio.h>
#include<math.h>
#include <ctype.h>
#define sf scanf
#define pf printf
#define ll long long
#define eps 1e-8
#include<string.h>
#include<stdlib.h>
#define ui unsigned int
#define max(a,b) ((a)>(b))?(a):(b)
typedef int datatype;
typedef struct node{
    datatype data;
    struct node*left;
    struct node*right;
    int deep;   
}tree,*Tree;
Tree head=NULL;
void out(Tree b)
{
    if(b!=NULL)
    {
        out(b->left);
        if(b->left==NULL&&b->right==NULL)
            printf("%d %d\n",b->data,b->deep);
        out(b->right);
        if(b->left==NULL&&b->right==NULL) // @@ [This condition duplicates the leaf node output. The same leaf is printed again during the right traversal, causing duplicate lines in the output.]
            printf("%d %d\n",b->data,b->deep);
    }
}
int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Tree q=NULL,p=NULL;
        scanf("%d",&num);
        q=(Tree)malloc(sizeof(tree));
        q->data=num;
        q->left=NULL;
        q->right=NULL;
        q->deep=1;
        if(head==NULL)
            head=q;
        else
        {
              p=head;
              while(1)
              {
                if(num<p->data)
                {
                    if(p->left!=NULL)
                    {
                        q->deep++; // @@ [The depth of the new node `q` is being incremented as we traverse down the existing tree, but this incorrectly modifies `q->deep` multiple times during traversal. The depth should be computed based on the parent's depth + 1 when inserting, not by incrementing during traversal.]
                        p=p->left;
                    }
                    else{
                        q->deep++; // @@ [Same issue: `q->deep` was initialized to 1, and then incremented once more here, making it 2 even though it should be parent's depth + 1. For example, inserting into an empty tree gives depth 1, but inserting a child would make it 2 correctly only if parent's depth is known. However, this approach fails because `q->deep` starts at 1 and gets incremented per level traversed, which overcounts.]
                        p->left=q;
                        break;
                    }
                }
                else
                {
                    if(p->right!=NULL)
                    {
                        q->deep++; // @@ [Same error as above: modifying `q->deep` during traversal leads to incorrect depth calculation.]
                        p=p->right;
                    }
                    else{
                        q->deep++; // @@ [Same error: over-incrementing depth of the new node.]
                        p->right=q;
                        break;
                    }
                }
              }
        }
    }
    out(head);
    return 0;
}