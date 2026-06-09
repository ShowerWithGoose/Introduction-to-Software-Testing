# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} *Tree;

Tree root;

Tree insert(Tree t, int x);

void traversal(Tree t, int h);

int height(Tree t);

int main() {
    int n;
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    traversal(root, 0);
    return 0;
}

void traversal(Tree t, int h) {
    if (t != NULL) {
        if(!t->left && !t->right)
            printf("%d %d\n", t->val, h + 1);
        traversal(t->left, h + 1);
        traversal(t->right, h + 1);
    }
}

Tree insert(Tree t, int x) {
    if (t == NULL) {
        t = (Tree) malloc(sizeof(struct Node));
        t->val = x;
        t->left = t->right = NULL;
        return t;
    }
    if (x < t->val)
        t->left = insert(t->left, x);
    else
        t->right = insert(t->right, x);
    return t;
}
