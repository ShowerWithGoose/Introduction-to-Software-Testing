#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree {
    int val;
    int time;
    int height;
    struct Tree *left;
    struct Tree *right;
} tree;

typedef struct Head {
    tree *t;
}head;

tree *init_tree (int val , int height) {
    tree *p = (tree*) malloc ( sizeof (tree) );
    p->val = val;
    p->time = 1;
    p->height = height;
    p->left = NULL;
    p->right = NULL;
    return p;
}

head *init_head (int val) {
    head *h = (head*) malloc ( sizeof (head) );
    h->t = init_tree(val , 1);
    return h;
}

void clear_tree (tree* t) {
    if(t == NULL) return ;
    clear_tree (t->left);
    clear_tree (t->right);
    t->left = NULL;
    t->right = NULL;
    free (t);
    return ;
}

void clear_head (head* h) {
    clear_tree (h->t);
    free(h);
    return ;
}

void insert (int val , head* h) {
    tree *p = h->t;
    int height = 1;
    while (1) {
        if (val < p->val) {
            if (p->left != NULL) p = p->left;
            else {
            	p->left = init_tree(val , height + 1);
            	return ;
            }
        }
        else {
            if (p->right != NULL) p = p->right;
            else {
            	p->right = init_tree(val , height + 1);
            	return ;
            }
        }
        height++;
    }
    return ;
}

void print_leave(tree* t) {
    if (t == NULL) return ;
    if (t->left == NULL && t->right == NULL) {
        printf("%d %d\n" , t->val , t->height);
        return ;
    }
    print_leave(t->left);
    print_leave(t->right);
    return ;
}

int main() {
    head *h;
    int n , val;
    scanf ("%d" , &n);
    scanf ("%d" , &val);
    h = init_head (val);
    n--;
    while (n--) {
		scanf("%d" , &val);
        insert (val , h);
    }
    print_leave (h->t);
    clear_head (h);
}


