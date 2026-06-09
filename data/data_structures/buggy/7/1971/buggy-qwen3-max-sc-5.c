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
        if(b->left==NULL&&b->right==NULL) // @@ [This condition duplicates the leaf check, causing each leaf to be printed twice]
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
                        q->deep++; // @@ [The depth is incremented on every traversal step, but it should reflect the depth of the node being inserted, not the traversed path count from root incorrectly accumulated]
                        p=p->left;
                    }
                    else{
                        q->deep++; // @@ [Same issue: depth is incremented one extra time when attaching as child, leading to incorrect height calculation]
                        p->left=q;
                        break;
                    }
                }
                else
                {
                    if(p->right!=NULL)
                    {
                        q->deep++; // @@ [Same depth calculation error for right subtree]
                        p=p->right;
                    }
                    else{
                        q->deep++; // @@ [Same depth calculation error for right subtree]
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