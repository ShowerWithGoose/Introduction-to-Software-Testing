#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct BTREE
{
    int num;
    struct BTREE *left,*right;
}*root=NULL;
int h=0; // @@ [Using a global variable 'h' to track height leads to incorrect height calculation during in-order traversal because recursive calls interfere with each other's height values.]

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
    h++; // @@ [Incrementing global 'h' on entry assumes every node visited increases depth, but backtracking via h-- after recursion doesn't correctly reflect the actual path depth for leaf nodes due to shared state across recursive branches.]
    if(p==NULL){
        h--;
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Height 'h' is corrupted due to global usage; also output format uses space instead of newline as required.]
    printLeaf(p->right);
    h--; // @@ [Global height manipulation causes incorrect height values for leaf nodes during in-order traversal.]
}