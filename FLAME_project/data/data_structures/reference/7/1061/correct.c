#include<stdio.h>
#include <malloc.h>

typedef struct node{
    int num;
    int height;
    struct node *lchild,*rchild;
}BTnode,*BTnodeptr;

int stack[1000];
typedef struct {
    int top;
    int base;
}Snode,*Snodeptr;
Snode S;

void push(int num,Snodeptr S);
void pop(Snodeptr S);
void preorderbianli(BTnodeptr T);
void inorderbianli(BTnodeptr T);

int main(){
    int i,n,elem;
    BTnodeptr T=NULL,r,wk1;

    S.top = S.base = -1;
    scanf("%d",&n);

    for (i = 0 ; i < n ; ++i) {
        scanf("%d",&elem);
        r = (BTnodeptr)malloc(sizeof(BTnode));
        r->num = elem;
        r->lchild = r->rchild = NULL;
        wk1 = T;

        while(1){
            if(T == NULL){
                T = r;
                break;
            }else if(r->num < wk1->num){
                if(wk1->lchild != NULL){
                    wk1 = wk1->lchild;
                }else{
                    wk1->lchild = r;
                    break;
                }
            }else if(r->num >= wk1->num){
                if(wk1->rchild != NULL){
                    wk1 = wk1->rchild;
                }else{
                    wk1->rchild = r;
                    break;
                }
            }
        }
    }
    preorderbianli(T);
    inorderbianli(T);


    return 0;

}

void push(int num,Snodeptr S){
    S->top++;
    stack[S->top] = num;
}

void pop(Snodeptr S){
    S->top--;
}

void preorderbianli(BTnodeptr T){
    if(T!= NULL){
        push(T->num,&S);
        T->height = S.top+1;
        preorderbianli(T->lchild);
        if(T->lchild != NULL) pop(&S);
        preorderbianli(T->rchild);
        if(T->rchild != NULL) pop(&S);

    }
}

void inorderbianli(BTnodeptr T){
    if(T != NULL){
        inorderbianli(T->lchild);
        if(T->lchild == NULL && T->rchild == NULL){
            printf("%d %d\n",T->num,T->height);
        }
        inorderbianli(T->rchild);
    }
}
