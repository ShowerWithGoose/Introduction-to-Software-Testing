/*
 * @Author:
 * @Date: 2022-04-14 19:14:09
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MaxN 100000

#define Type int
typedef struct Node{
    Type val;
    struct Node *nex;
}Node;

typedef struct Stack{
    struct Node *head,*tail;
    int sz;
}Stack;

// init
void stackInit(Stack *stk){
    stk->tail=stk->head=(Node *)malloc(sizeof(Node));
    stk->tail->nex=NULL;
    stk->sz=0;
}

// query
static inline bool stackEmpty(Stack *stk){return stk->sz==0;}

static inline int stackSize(Stack *stk){return stk->sz;}

Node *stackTop(Stack *stk){
    if(stackEmpty(stk)) return NULL;
    else return (stk->head->nex);
}

// push
void stackPush(Stack *stk,Type value){
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->val=value;
    tmp->nex=stk->head->nex;
    stk->head->nex=tmp;
    (stk->sz)++;
}

// pop
void stackPop(Stack *stk){
    if(stackEmpty(stk)) return;
    Node *tmp=stk->head->nex;
    stk->head->nex=tmp->nex;
    free(tmp);
    (stk->sz)--;
}

int main(int argc, char const *argv[]){
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    stackInit(stk);

    int opt,num;
    while(scanf("%d",&opt)!=EOF){
        if(opt==-1) break;
        else if(opt==0){
            if(stackEmpty(stk)){
                printf("error ");
            }else{
                printf("%d ",stackTop(stk)->val);
                stackPop(stk);
            }
        }else{
            if(stackSize(stk)==100){
                printf("error ");
            }else{
                scanf("%d",&num);
                stackPush(stk,num);
            }
        }
    }
    return 0;
}
