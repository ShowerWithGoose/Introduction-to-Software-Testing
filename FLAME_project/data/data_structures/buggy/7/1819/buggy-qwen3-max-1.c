#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree{
    struct tree* left;
    int n;
    struct tree* right;
}T;
struct tree* put_tree(struct tree*a,int m)
{
    if(a==NULL)
    {
        a=(struct tree*)malloc(sizeof(struct tree));
        a->n=m;
        a->left=NULL;
        a->right=NULL;    
    }    
    else
    {
        if(a->n>m)
            {
                if(a->left==NULL)
                a->left=put_tree(a->left,m);
                else
                put_tree(a->left,m); // @@ [Recursive call result is not assigned when a->left is not NULL, causing insertion to be lost]
            }
        else
            {
                if(a->right==NULL)
                a->right=put_tree(a->right,m);    
                else
                put_tree(a->right,m); // @@ [Recursive call result is not assigned when a->right is not NULL, causing insertion to be lost]
            }
        
    }
} // @@ [Function does not return a value in all paths; missing 'return a;' at the end]
void check_tree(struct tree *a,int b)
{
    if(a==NULL)
    {
        return;
    }
    if(a->left==NULL&&a->right==NULL)
    {
        printf("%d %d\n",a->n,b);
    }
    check_tree(a->left,b+1);
    check_tree(a->right,b+1);
}
int main()
{
//    char c;
//    while(scanf("%c",&c)!=EOF)
//    printf("%c",c);
    int num,h;
    T *root=NULL;        
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&h);
        if(i==0)
        root=put_tree(root,h);
        else      
        put_tree(root,h); // @@ [Return value of put_tree is ignored for i > 0, so root may not reflect changes made deep in the tree]
    }
    check_tree(root,1);
     return 0;
}