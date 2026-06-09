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
    h++; // @@ [The global variable 'h' is used to track height, but it's modified during recursive traversal in a way that doesn't correctly represent the current node's height. When backtracking from left subtree, 'h' is decremented, but then incremented again before traversing right subtree, leading to incorrect height values for nodes in the right subtree.]
    if(p==NULL){
        h--; // @@ [Decrementing 'h' on NULL node may cause negative or inconsistent height values, and this approach of using a global height counter cannot correctly assign heights during in-order traversal. Height should be passed as a parameter or computed based on tree structure.]
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Height 'h' is incorrect due to flawed global tracking; also, output format requires newline ('\n') after each leaf, not space. Expected: "%d %d\n"]
    printLeaf(p->right);
    h--; // @@ [Global height 'h' is decremented after processing both subtrees, but because 'h' is shared across all recursive calls, the value becomes inconsistent during traversal, especially when switching from left to right subtrees.]
}