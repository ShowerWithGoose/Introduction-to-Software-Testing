#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int num;
    int height;
    struct tree *left;
    struct tree *right;
};
void ins(int a,struct tree *b)
{
    if(a>=b->num)
    {
        if(b->right==NULL)
        {
            struct tree *r=(struct tree*)malloc(sizeof(struct tree));
            b->right=r;
            r->num=a;
            r->height=b->height+1;
            r->left=NULL;
            r->right=NULL;
        }
        else
            ins(a,b->right);
    }
    else
    {
        if(b->left==NULL)
        {
            struct tree *r=(struct tree*)malloc(sizeof(struct tree));
            b->left=r;
            r->num=a;
            r->height=b->height+1;
            r->left=NULL;
            r->right=NULL;
        }
        else
            ins(a,b->left);
    }
}
void print_leaf(struct tree *c) @@ // Missing null-pointer check; accessing c->left/right when c is NULL causes undefined behavior.
{
    if((c->left==NULL)&&(c->right==NULL))
        printf("%d %d\n",c->num,c->height);
    else
    {
        print_leaf(c->left); @@ // Potential null pointer passed without check, leading to crash in next call.
        print_leaf(c->right); @@ // Same issue as above.
    }
}
struct tree *gen=NULL;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        if(gen==NULL)
        {
            gen=(struct tree*)malloc(sizeof(struct tree));
            gen->num=m;
            gen->height=1;
            gen->left=NULL;
            gen->right=NULL;
        }
        else
            ins(m,gen);
    }
    print_leaf(gen);
}