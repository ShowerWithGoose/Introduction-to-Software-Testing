#include <stdio.h>
#include <stdlib.h>

typedef int treeType;
typedef struct tree{
    treeType value;
    struct tree* left;
    struct tree* right;
}tree,node;

tree* treeInit(treeType x){
    node* root = (node*)malloc(sizeof(node));
    root->value = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int treeInsert(tree* t, treeType x){
    if(t==NULL){
        return -1;
    }else if(x<t->value){
        if(t->left!=NULL)
            treeInsert(t->left,x);
        else{
            t->left = (node*)malloc(sizeof(node));
            t->left->left=NULL;
            t->left->right=NULL;
            t->left->value=x;
        }
    }else{
        if(t->right!=NULL)
            treeInsert(t->right,x);
        else{
            t->right = (node*)malloc(sizeof(node));
            t->right->left=NULL;
            t->right->right=NULL;
            t->right->value=x;
        }
    }
    return 0;
}

void leaveFind(tree* t, int l){
    if(t!=NULL){
        leaveFind(t->left,l+1); @@ [The height passed to left child should be l+1 only when recursing, but the current node's height is l. However, the main issue is that the traversal order is in-order, which does not guarantee left-to-right leaf order in terms of tree structure; but more critically, when t is a leaf, it prints with height l, but the recursion increases l even when child is NULL, leading to incorrect height calculation. Specifically, the function calls leaveFind on NULL children with l+1, which is wrong because NULL nodes don't exist and shouldn't increase depth. The correct approach is to only recurse into non-NULL children and pass l+1 then.]
        if(t->left==NULL&&t->right==NULL)
            printf("%d:%d\n",t->value,l);
        leaveFind(t->right,l+1); @@ [Same issue as above: passing l+1 to potentially NULL child leads to incorrect height tracking in deeper calls, though the immediate print uses correct l. However, the real problem causing wrong output format is the use of colon ':' instead of space ' ' as separator.]
    }
}

int main() {
    int a,tmp;

    scanf("%5d",&a);
    scanf("%d",&tmp);
    tree* Tree = treeInit(tmp);
    for(int i=0; i<a-1; i++){
        scanf("%d",&tmp);
        treeInsert(Tree,tmp);
    }
    leaveFind(Tree,1);

    return 0;
}