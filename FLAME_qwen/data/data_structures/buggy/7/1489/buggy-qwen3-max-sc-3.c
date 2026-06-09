#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef int Datatype;
struct node {
    Datatype data;
    struct node* left, * right;
};
typedef struct node BTNode, * BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
BTNodeptr  searchBST(BTNodeptr t,int x);

int main()
{
    int n, item;
    BTNodeptr  root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    n = 0; // @@ [The initial height should be 1, not 0, because the problem states the root's height is 1. Passing 0 causes leaf heights to be undercounted by 1.]
    searchBST(root,n);
    return 0;
}

BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if (p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item);
    else if (item >= p->data)
        p->right = insertBST(p->right, item);
    return p;
}
BTNodeptr  searchBST(BTNodeptr t,int x)
{
    if (t != NULL) {
        if (t->right == NULL && t->left == NULL)
            printf("%d %d\n", t->data, x); // @@ [Because x starts at 0 in main, this prints height as 0 for root-level leaves, but expected height is 1. The height parameter should start at 1.]       
       searchBST(t->left,x+1); 
       searchBST(t->right,x+1);
    }                                                  
    else
        return NULL;                    
}