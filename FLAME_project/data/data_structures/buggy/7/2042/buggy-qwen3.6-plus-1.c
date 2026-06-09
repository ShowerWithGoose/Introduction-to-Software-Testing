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
        leaveFind(t->left,l+1);
        if(t->left==NULL&&t->right==NULL)
            printf("%d:%d\n",t->value,l); // @@ The output format uses a colon ':' instead of a space ' ' as required by the problem description ("separated by a space").
        leaveFind(t->right,l+1);
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