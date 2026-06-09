#include <stdio.h>

typedef struct treeNode{
    int val;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* Insert(treeNode* obj, int val){
    if(obj == NULL){
        obj = (treeNode*)malloc(sizeof(treeNode));
        obj->val = val;
        obj->left = NULL;
        obj->right = NULL;
        return obj;
    }
    if(val < obj->val){
        obj->left = Insert(obj->left, val);
    }
    else{
        obj->right = Insert(obj->right, val);
    }
    return obj;
}

void Print(treeNode* obj, int level){
    if(obj->left != NULL){
        Print(obj->left, level+1);
    }
    if(obj->right != NULL){
        Print(obj->right, level+1);
    }
    if(obj->left == NULL && obj->right == NULL){
        printf("%d %d\n", obj->val, level);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    treeNode *root = NULL;
    while(n--){
        int val;
        scanf("%d", &val);
        root = Insert(root, val);
    }
    Print(root, 1);
    return 0;
}
