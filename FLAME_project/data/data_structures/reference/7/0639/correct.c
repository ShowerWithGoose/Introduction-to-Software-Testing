#include<stdio.h>
#include<string.h>
typedef struct node
{
    int d;
    int h;
    struct node *l, *r;
} Tree;
Tree *f;
Tree *New(Tree *root, int t, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->d=t;
        root->l=root->r=NULL;
        f=root;
        root->h=len;
    }
    else if(t<root->d)
        root->l=New(root->l,t,len);
    else if(t>=root->d)
        root->r=New(root->r,t,len);
    return root;
}
void print(Tree *root)
{
    if (root)
    {
        if (!(root->l) && !(root->r))
        {
            printf("%d %d\n", root->d, root->h);
        }
        print(root->l);
        print(root->r);
    }
}
int main()
{
    Tree *root=NULL;
    int n,i,t;
    scanf("%d", &n);
    for(i=0;i<n;i++) 
    {
        scanf("%d", &t);
        int len=0;
        root=New(root,t,len);
    }
    print(root);
    return 0;
}

