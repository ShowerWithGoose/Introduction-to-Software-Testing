#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int data;
    int h;
    struct node* left;
    struct node* right;
};
typedef struct node Bst;
typedef struct node* Bstptr;
Bstptr search(int, Bstptr);
void perorder(Bstptr);

int main() {
    Bstptr head, ptr;
    head = ptr = (Bstptr)malloc(sizeof(Bst));
    ptr->left = NULL;
    ptr->right = NULL;

    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf(" %d", &data);
        if (i >= 1) {
            ptr = search(data, head);
            ptr->data = data;
        } else {
            ptr->h = 1;
            ptr->data = data;
        }
    }

    perorder(head);

    return 0;
}

Bstptr search(int n, Bstptr first) {
    Bstptr cur = first;
    while (1) {
        if (n < cur->data) {
            if (cur->left != NULL)
                cur = cur->left;
            else {
                cur->left = (Bstptr)malloc(sizeof(Bst));
                cur->left->h = cur->h + 1;
                cur = cur->left;
                cur->left = NULL;
                cur->right = NULL;
                return cur;
            }
        } else {
            if (cur->right != NULL)
                cur = cur->right;
            else {
                cur->right = (Bstptr)malloc(sizeof(Bst));
                cur->right->h = cur->h + 1;
                cur = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                return cur;
            }
        }
    }
}

void perorder(Bstptr t) {
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            printf("%d %d\n", t->data, t->h);
        perorder(t->left);
        perorder(t->right);
    }
}

