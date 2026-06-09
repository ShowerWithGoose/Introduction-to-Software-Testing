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
void print_leaf(struct tree *c)
{
    if(c==NULL) return; // @@ [Missing null check causes Runtime Error when accessing c->left or c->right on a NULL node, which happens if a leaf's child is traversed]
    if((c->left==NULL)&&(c->right==NULL))
        printf("%d %d\n",c->num,c->height);
    else
    {
        print_leaf(c->left);
        print_leaf(c->right);
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