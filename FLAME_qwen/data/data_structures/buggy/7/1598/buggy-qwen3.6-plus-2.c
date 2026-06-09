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
            p=createTree(a,p);
        }    
    }
    printTree(root);
    
    return 0;
}


struct Tree *createTree(int a,struct Tree *p)
{
    flag++; // @@ Using a global variable 'flag' to track depth in recursive calls is incorrect and will lead to wrong depth values; depth should be passed as a parameter.
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
        printTree(p->right); // @@ Incorrect traversal order and missing leaf node check; should use in-order traversal and print only when p->left==NULL && p->right==NULL.
    }
    else{
        printf("%d %d\n",p->num,p->depth); // @@ Dereferencing NULL pointer 'p' causes undefined behavior/segmentation fault; this branch executes when p is NULL, making p->num invalid.
    }
}