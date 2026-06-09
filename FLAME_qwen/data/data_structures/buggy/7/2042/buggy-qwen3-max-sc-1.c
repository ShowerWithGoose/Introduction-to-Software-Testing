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
        leaveFind(t->left,l+1); // @@ [The height passed to left child should be l+1 only when recursing, but the current node's height is l. However, the real issue is that the traversal order is in-order, not left-to-right leaf order as required. But more critically, when t is NULL, l+1 is still computed unnecessarily. However, the main logical error is in traversal order and height tracking.]
        if(t->left==NULL&&t->right==NULL)
            printf("%d:%d\n",t->value,l); // @@ [Output format uses colon ':' but problem requires space ' '. Also, height of root is 1, but due to in-order traversal and incorrect height propagation, leaf heights may be wrong.]
        leaveFind(t->right,l+1); // @@ [Same issue as left recursion: unnecessary l+1 when t might be NULL, but more importantly, in-order traversal does not guarantee left-to-right leaf order in terms of tree structure (though for BST it might coincidentally), but the bigger issue is height calculation.]
    }
}

int main() {
    int a,tmp;

    scanf("%5d",&a); // @@ [Using %5d limits input to 5 digits, which is unnecessary and may cause issues if n has more than 5 digits. Should be just %d.]
    scanf("%d",&tmp);
    tree* Tree = treeInit(tmp);
    for(int i=0; i<a-1; i++){
        scanf("%d",&tmp);
        treeInsert(Tree,tmp);
    }
    leaveFind(Tree,1);

    return 0;
}