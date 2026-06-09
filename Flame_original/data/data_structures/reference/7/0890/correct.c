#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *lchild, *rchild;
} Tree;
Tree *i;

Tree *New(Tree *root, int a, int len);
void print(Tree *root);

int main()
{
    Tree *root = NULL;
    int n,a,j,len;
    len=0;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        scanf("%d", &a);
        root = New(root, a, len);
    }
    print(root);
    return 0;
}

Tree *New(Tree *root, int a, int len)
{
    len++;
    if (root == NULL){
        root = (Tree *)malloc(sizeof(Tree));
        root->data = a;
        root->lchild = root->rchild = NULL;
        i = root;
        root->high = len;
    }
    else if (a < root->data)
        root->lchild = New(root->lchild, a, len);
    else if (a >= root->data)
        root->rchild = New(root->rchild, a, len);
    return root;
}

void print(Tree *root)
{
    if (root){
        if (!(root->lchild) && !(root->rchild)){
            printf("%d %d\n", root->data, root->high);
        }
        print(root->lchild);
        print(root->rchild);
    }
}




