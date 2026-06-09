#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include <ctype.h>
#define eps 1e-6 
#define maxsize 200
struct tree{
    int data;
    int depth;
    struct tree *left,*right;
}; 

struct tree* atree(int x,int d,struct tree*p)
{
    if(p==NULL) 
    {
        p=(struct tree*)malloc(sizeof(struct tree));
        p->data=x;
        p->depth=d; 
        p->left=NULL;
        p->right=NULL;
        return(p);
    }
    else
    {
        if(x<p->data) p->left=atree(x,d+1,p->left);
        else p->right=atree(x,d+1,p->right); // @@ The problem states that values greater than or equal to the root go to the right child. While this logic (else implies >=) is technically correct for the split, the recursive call structure here is valid. However, looking at the reference program and the error, let's re-evaluate. The reference program uses iterative insertion. This recursive one looks logically sound for BST construction. Let's look closer at the output.
    }
}

void treeprint(struct tree *p)
{
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n",p->data,p->depth);
    else
    {
        if(p->left!=NULL) treeprint(p->left);
        if(p->right!=NULL) treeprint(p->right);    
    }    
}


int main() {   
    int n,x;
    scanf("%d",&n);
    struct tree* root;
    root=NULL;
    while(n--)
    {
        scanf("%d",&x);
        root=atree(x,1,root);
    } 
        treeprint(root);
return 0;
}