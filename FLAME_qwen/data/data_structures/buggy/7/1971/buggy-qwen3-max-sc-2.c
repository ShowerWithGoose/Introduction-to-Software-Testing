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
        if(b->left==NULL&&b->right==NULL) // @@ [This condition is repeated, causing leaf nodes to be printed twice. The second print should be removed to avoid duplicate output.]
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
                        q->deep++; // @@ [The depth is being incremented on the new node 'q' as we traverse, but it should reflect the depth of the parent + 1. However, since 'q' starts at 1 and increments per level traversed, this actually works. But logically clearer to set depth after finding parent. Not a critical error.]
                        p=p->left;
                    }
                    else{
                        q->deep++; // @@ [Same as above: depth logic works but is unconventional. However, the real issue is that depth is updated during traversal rather than assigned as parent's depth + 1. This can lead to correct values only because initial depth is 1 and each step adds 1. Still acceptable but fragile. Not the main bug.]
                        p->left=q;
                        break;
                    }
                }
                else
                {
                    if(p->right!=NULL)
                    {
                        q->deep++; // @@ [Same depth increment issue as left branch. Again, not the primary cause of failure in output order or duplication.]
                        p=p->right;
                    }
                    else{
                        q->deep++; // @@ [Same as above.]
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