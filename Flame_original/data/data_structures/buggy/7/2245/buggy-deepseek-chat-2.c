#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct BTREE
{
    int num;
    struct BTREE *left,*right;
}*root=NULL;
int h=0;

struct BTREE *insertBST(struct BTREE *,int);
void printLeaf(struct BTREE *);

int main()
{
    int t,item;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    printLeaf(root);
    return 0;
}

struct BTREE *insertBST(struct BTREE *p,int item){
    if(p==NULL){
        p=(struct BTREE *)malloc(sizeof(struct BTREE));
        p->num=item;
        p->left=p->right=NULL;
    }
    else if(item<p->num)
        p->left=insertBST(p->left,item);
    else
        p->right=insertBST(p->right,item);
    return p;
}

void printLeaf(struct BTREE *p){
    h++; // @@ [Error: The height is incremented before checking if p is NULL, causing incorrect height values for leaf nodes. The height should be passed as a parameter or tracked differently to match the root height of 1.]
    if(p==NULL){
        h--;
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Error: Output format uses spaces instead of newlines between value and height, and does not print each leaf on a separate line as required.]
    printLeaf(p->right);
    h--;
}