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
int flag=0; // @@ Global variable 'flag' is incorrectly used to track depth; depth should be passed as a parameter or calculated relative to the parent.
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
            p=createTree(a,p);
        }    
    }
    printTree(root);
    
    return 0;
}


struct Tree *createTree(int a,struct Tree *p)
{
    flag++; // @@ Incrementing a global counter on every recursive call does not correctly compute the node's depth.
    if(p==NULL){
        p=(struct Tree *)malloc(sizeof(struct Tree));
        p->num=a;
        p->depth=flag; // @@ Assigns the incorrect global counter value to depth instead of parent's depth + 1.
        p->left=p->right=NULL;
        flag=0; // @@ Resetting the global counter breaks depth calculation for subsequent insertions.
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
    if(p!=NULL){ // @@ Logic is inverted; it should check if the node is a leaf to print, not just if it's non-NULL.
        printTree(p->left); // @@ Missing leaf node check and correct in-order traversal logic.
        printTree(p->right); // @@ Missing leaf node check and correct in-order traversal logic.
    }
    else{ // @@ This branch executes when p is NULL, leading to a segmentation fault.
        printf("%d %d\n",p->num,p->depth); // @@ Dereferencing NULL pointer 'p' causes a runtime crash.
    }
}