/*
 * @Author:
 * @Date: 2022-03-25 12:20:53
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
typedef long long ll;

typedef struct Monomial{
    ll c,exp;//coefficient,exponent
}Mono;

bool mEq(const Mono *a,const Mono *b){
    return a->exp==b->exp;
}

bool mGt(const Mono *a,const Mono *b){
    return (a->exp>b->exp);
}

//================================== list
#define Type Mono*
typedef struct Node{
    Type val;
    struct Node *pre,*nex;
}Node;

typedef struct List{
    struct Node *head,*tail;
    int sz;
}List;

// init
void listInit(List *lis){
    lis->head=(Node *)malloc(sizeof(Node));
    lis->tail=(Node *)malloc(sizeof(Node));
    lis->head->pre=NULL;
    lis->head->nex=lis->tail;
    lis->tail->pre=lis->head;
    lis->tail->nex=NULL;
    lis->sz=0;
}

// insert
void listInsertAfterNode(List *lis,Node *no,Type value){
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->val=value;
    tmp->pre=no;
    tmp->nex=no->nex;
    no->nex->pre=tmp;
    no->nex=tmp;
    lis->sz++;
}

void listInsert(List *lis,int pos,Type value){
    if(pos<0) pos=0;
    else if(pos>lis->sz) pos=lis->sz;
    Node *no=lis->head;
    while(pos>0){no=no->nex;pos--;}
    listInsertAfterNode(lis,no,value);
}

void listAppend(List *lis,Type value){
    listInsertAfterNode(lis,lis->tail->pre,value);
}

//====================================== main

int main(int argc, char const *argv[]){
    List *lis[3];//1*2=0
    for(int i=0;i<3;i++){
        lis[i]=(List *)malloc(sizeof(List));
        listInit(lis[i]);
    }
    ll c,exp;char end;
    while(true){
        scanf("%lld%lld%c",&c,&exp,&end);
        Mono *tmp=(Mono *)malloc(sizeof(Mono));
        tmp->c=c;tmp->exp=exp;
        listInsert(lis[1],0,tmp);
        if(end=='\n') break;
    }
    while(true){
        scanf("%lld%lld%c",&c,&exp,&end);
        Mono *tmp=(Mono *)malloc(sizeof(Mono));
        tmp->c=c;tmp->exp=exp;
        listInsert(lis[2],0,tmp);
        if(end=='\n') break;
    }
    for(Node *no1=lis[1]->head->nex;no1!=lis[1]->tail;no1=no1->nex){
        Node *no=lis[0]->head->nex;
        for(Node *no2=lis[2]->head->nex;no2!=lis[2]->tail;no2=no2->nex){
            Mono *tmp=(Mono *)malloc(sizeof(Mono));
            tmp->c=(no1->val->c)*(no2->val->c);
            tmp->exp=(no1->val->exp)+(no2->val->exp);
            while(no!=lis[0]->tail){
                if(mGt(tmp,no->val)){
                    no=no->nex;
                    continue;
                }else if(mEq(tmp,no->val)){
                    (no->val->c) += tmp->c;
                    free(tmp);
                    break;
                }else{
                    listInsertAfterNode(lis[0],no->pre,tmp);
                    break;
                }
            }
            if(no==lis[0]->tail){
                listAppend(lis[0],tmp);
            }
        }
    }
    for(Node *no=lis[0]->tail->pre;no!=lis[0]->head;no=no->pre){
        printf("%lld %lld ",no->val->c,no->val->exp);
    }
    printf("\n");
    return 0;
}
