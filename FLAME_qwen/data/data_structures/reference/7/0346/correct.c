#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    int degree;
    struct Node *lchild, *rchild;
} BNode, *BTree;

int leaf(BTree T,int KEY,BTree F,BTree *p){
    if(!T){
        *p = F;
        return 0;
    }else if(KEY<T->data){
        return leaf(T->lchild, KEY, T, p);
    }else{
        return leaf(T->rchild, KEY, T, p);
    }
}


void insert(BTree *T,int key){
    BTree p, s;
    s = (BTree)malloc(sizeof(BNode));
    s->data = key;
    s->lchild = s->rchild = NULL;
    if(!leaf(*T, key, NULL, &p)){
        if(!p){
            *T = s;
            s->degree = 1;
        }else if(key<p->data){
            p->lchild = s;
            p->lchild->degree = p->degree + 1;
        }else{
            p->rchild = s;
            p->rchild->degree = p->degree + 1;
        }
    }
    
}
void printleave(BTree T){
    if(T){
        if((T->lchild)==NULL&&(T->rchild)==NULL){
            printf("%d %d\n", T->data,T->degree);
        }
        printleave(T->lchild);
        printleave(T->rchild);
    }
}

int n;
int a;
BTree T = NULL;

int main(){
    scanf("%d", &n);
    int i;
    for (i = 0; i < n;i++){
        scanf("%d", &a);
        insert(&T, a);
    }
    printleave(T);
}


