#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Tree
{
    struct Tree *left;
    int num;
    struct Tree *right;    
    int depth;
};
struct Tree tree;
int flag=0;
struct Tree *createTree(int a,struct Tree *p);
void printTree(struct Tree *p);

int main()
{
    int n,a;
    struct Tree *root=NULL,*p=NULL;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(i==0){
            root=createTree(a,root);
            p=root;
        }
        else{
            p=createTree(a,p); // @@ Error: When inserting subsequent nodes, the pointer p should be updated to the root of the tree, not the result of the last insertion. This causes the tree structure to be incorrect because p is not the root for subsequent insertions.
        }    
    }
    printTree(root);
    
    return 0;
}


struct Tree *createTree(int a,struct Tree *p)
{
    flag++;
    if(p==NULL){
        p=(struct Tree *)malloc(sizeof(struct Tree));
        p->num=a;
        p->depth=flag;
        p->left=p->right=NULL;
        flag=0;
    }
    else{
        if(a<p->num){
            p->left=createTree(a,p->left);
        }
        else{
            p->right=createTree(a,p->right);
        }
    }
    return p;
}
void printTree(struct Tree *p)
{
    if(p!=NULL){
        printTree(p->left);
        printTree(p->right); // @@ Error: This prints in post-order (left, right, root), but the problem requires left-to-right order for leaf nodes only. The expected output should only print leaf nodes, and the traversal should be in-order (left, root, right) to get left-to-right order.
    }
    else{
        printf("%d %d\n",p->num,p->depth); // @@ Error: When p is NULL, dereferencing p->num and p->depth causes undefined behavior (likely a segmentation fault). The leaf node check should be done when p is not NULL.
    }
}