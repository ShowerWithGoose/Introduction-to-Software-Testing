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
    h++; // @@ [The global variable 'h' is incremented before checking if 'p' is NULL, leading to incorrect height tracking during recursive calls. Height should be passed as a parameter or managed differently to reflect the actual depth of each node.]
    if(p==NULL){
        h--; // @@ [This decrement may not correctly balance the increment because the function returns immediately after, but the logic of using a global 'h' fails in complex tree traversals where left and right subtrees interfere with each other's height counts.]
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Output format uses space instead of newline; problem requires each leaf on a separate line. Also, 'h' is globally shared and thus gives wrong height due to interference from other recursive paths.]
    printLeaf(p->right);
    h--;
}