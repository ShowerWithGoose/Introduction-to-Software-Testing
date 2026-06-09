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
                put_tree(a->left,m); // @@ [The recursive call's return value is ignored when a->left is not NULL, causing the new node to be lost.]
            }
        else
            {
                if(a->right==NULL)
                a->right=put_tree(a->right,m);    
                else
                put_tree(a->right,m); // @@ [The recursive call's return value is ignored when a->right is not NULL, causing the new node to be lost.]
            }
        
    }
    return a; // @@ [Missing return statement: function must return the root of the (sub)tree in all paths.]
}
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
        put_tree(root,h); // @@ [Return value of put_tree is ignored for i > 0, so the tree may not be updated correctly if insertion requires modifying the root of a subtree.]
    }
    check_tree(root,1);
     return 0;
}