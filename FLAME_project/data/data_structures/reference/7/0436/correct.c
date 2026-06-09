#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild, *rchild;
};

struct node* insert(struct node *p, int obj){
    if(p == NULL){
            p = (struct node*)malloc(sizeof(struct node));
            p->data = obj;
            p->lchild = p->rchild = NULL;
            // printf("fst get:%d\n", obj);
        }
    else if(obj < p->data){
        p->lchild = insert(p->lchild, obj);
        // printf("left!\n");            
    }
    else if(obj >= p->data){
        p->rchild = insert(p->rchild, obj);
        // printf("right!\n");            
    }
    return p;
}
void print(struct node *root, int depth){
    if(root != NULL){
        if(root->lchild==NULL && root->rchild==NULL){
        printf("%d %d\n", root->data, depth);
    }
        print(root->lchild, depth+1);
        print(root->rchild, depth+1);
    }
}

void printit(struct node *root){
    if(root != NULL){
        printf("%d\n", root->data);
        printit(root->lchild);
        printit(root->rchild);
    }
}

int main(){
    int n, i, obj;
    scanf("%d", &n);
    struct node *root=NULL;
    for(i=0; i<n; i++){
        scanf("%d", &obj);
        root = insert(root, obj);
        // printf("here:%d\n",i);
    }
    // printit(root);
    // printf("\nthen\n");
    print(root, 1);
    return 0;
}
