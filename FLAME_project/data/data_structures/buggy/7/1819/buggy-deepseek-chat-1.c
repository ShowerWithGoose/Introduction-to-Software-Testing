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
                put_tree(a->left,m);
            }
        else
            {
                if(a->right==NULL)
                a->right=put_tree(a->right,m);    
                else
                put_tree(a->right,m);
            }
        
    }
} // @@ Missing return statement: The function is declared to return a struct tree*, but when a is not NULL (the else branch), no value is returned, causing undefined behavior.
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
        put_tree(root,h);
    }
    check_tree(root,1);
     return 0;
}