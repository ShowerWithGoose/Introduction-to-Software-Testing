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
    n = 0; // @@ [The variable 'n' is reused to store the starting height, but it's set to 0. The problem states that the root height is 1, so this should be 1 instead of 0.]
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
            printf("%d %d\n", t->data, x);       
       searchBST(t->left,x+1); 
       searchBST(t->right,x+1);
    }                                                  
    else
        return NULL; // @@ [The function is declared to return BTNodeptr, but in the non-null branch, there is no return statement. This leads to undefined behavior and is a logical error. However, since the function is used only for traversal and printing, it should be changed to return void. But as per instructions, we only mark errors without changing structure. The real issue causing wrong output is the initial height passed as 0 instead of 1.]
}