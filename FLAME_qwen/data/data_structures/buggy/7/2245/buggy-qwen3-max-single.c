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
    h++; // @@ [The global variable 'h' is used to track height, but it's modified during recursive traversal in a way that doesn't correctly represent the current node's height. When backtracking from left subtree, 'h' is decremented, but then incremented again before visiting right subtree, leading to incorrect height values for leaf nodes.]
    if(p==NULL){
        h--; // @@ [Decrementing 'h' on NULL node may cause negative or inconsistent height tracking because the increment happened before checking for NULL. This disrupts the correct height calculation for actual nodes.]
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Height 'h' is not correctly maintained due to flawed global state management during recursion, causing wrong height output for leaf nodes. Also, output format uses space instead of newline as required.]
    printLeaf(p->right);
    h--;
}