//
// Created by  on 2024/3/27.
//整系数和指数，多项式乘积，先分别乘，先别排序，先按从前到后分别，重新生成一个链表，然后再排序，同时合并
#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial{
    int coefficient;
    int exponent;
    struct polynomial *to;
    struct polynomial *from;

}body,*link;

int main(){
    link final,now,temp,first,second,begin,next,max,new;
    new = (link)malloc(sizeof(body));
    first=(link)malloc(sizeof(body));
    temp=first;
    scanf("%d %d",&first->coefficient,&first->exponent);

    while(getchar()!='\n'){
        now=(link)malloc(sizeof(body));
        scanf("%d %d",&now->coefficient,&now->exponent);
        temp->to=now;
        temp=now;
    }

    now->to=NULL;

    second=(link)malloc(sizeof(body));
    temp=second;
    scanf("%d %d",&second->coefficient,&second->exponent);

    while(getchar()!='\n'){
        now=(link)malloc(sizeof(body));
        scanf("%d %d",&now->coefficient,&now->exponent);
        temp->to=now;
        temp=now;
    }
    now->to=NULL;
    begin=second;
    new=(link)malloc(sizeof(body));
    temp=new;
    while(first!=NULL){
        while(second!=NULL){
            now=(link)malloc(sizeof(body));
            now->from=temp;
            temp->to=now;
            now->coefficient=first->coefficient*second->coefficient;
            now->exponent=first->exponent+second->exponent;
            temp=now;
            second=second->to;
        }
        second=begin;
        first=first->to;
    }
    final=(link)malloc(sizeof(body));
    now->to=final;
    final->from=new;
    now=new->to;//new->to是新链的第一个
    while(now!=final){
        next=now->to;
        max=now;
        while(next!=final){
            if(next->exponent>max->exponent){
                max=next;
            }
            else if(next->exponent==max->exponent){
                next->to->from=next->from;
                next->from->to=next->to;
                max->coefficient=max->coefficient+next->coefficient;
            }
            next=next->to;
        }
        if(max!=now){
            printf("%d %d ",max->coefficient,max->exponent);
            max->to->from=max->from;
            max->from->to=max->to;
            max->to=now;
            max->from=now->from;
            now->from->to=max;
            now->from=max;
        }
        else{
            printf("%d %d ",max->coefficient,max->exponent);
            now=now->to;
        }

    }
    return 0;
}

