#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int level;
    int data;
    struct node *lchild;
    struct node *rchild;
}Bnode,*Btree;

Btree insert(Btree p,int data,int level){
    if(p == NULL){
        p = (Btree)malloc(sizeof(Bnode));
        p->data = data;
        p->lchild = NULL;
        p->rchild = NULL;
        level++;
        p->level = level;
    }
    else if(data < p->data){
        level++;
        p->lchild = insert(p->lchild,data,level);
    }
    else if(data >= p->data){
        level++;
        p->rchild = insert(p->rchild,data,level);
    }
    return p;
}
scan()
{	int x;
	scanf("%d",&x);
	return x;
}
void visit(Btree T){
    if(T == NULL)
        return;
    else if(T->lchild == NULL && T->rchild == NULL)
        printf("%d %d\n",T->data,T->level);
}

void perorder(Btree T){
    if(T != NULL){
        visit(T);
        perorder(T->lchild);
        perorder(T->rchild);
    }
}

int main(){
    Btree root = NULL;
    int data = 0,level = 0;
    int N;
    scanf("%d",&N);
    while(N--){
        data=scan("%d",&data);
        root = insert(root,data,level);
    }
    perorder(root);
    return 0;
}

