#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* treeroot;
void insert(int data,struct Node**tree) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (*tree == NULL) {
         *tree = temp;
         (*(tree))-> left = NULL;
         (*tree)->right = NULL;
    }
    else {
        struct Node* p = *tree;
        if (data >= (*tree)->data)
            insert(data, &(p->right));
        else insert(data, &(p->left));
    }
        
        
}
void find(struct Node*root,int depth) {
    if (root!=NULL&&root->left == NULL && root->right == NULL&&) { // @@ [Syntax error: trailing '&&' operator with no following condition]
        printf("%d %d\n", root->data, depth);
        return;
    }else if (root!=NULL) {
        find(root->left, depth + 1);
        find(root->right, depth + 1);
    }
}
int main() {
    treeroot = NULL;
    int N;
    scanf("%d", &N);
    int number;
    for (int i = 0; i < N; i++) {
        scanf("%d", &number);
        insert(number, &treeroot);
    }
    int high = 1;
    
    find(treeroot,1);
}