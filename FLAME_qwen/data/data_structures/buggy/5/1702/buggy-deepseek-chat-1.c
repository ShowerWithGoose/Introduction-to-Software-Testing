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

    while(getchar()!='\n'){ // @@ 错误：getchar()会读取第一个多项式输入后的换行符，但若输入格式中指数后无空格且直接换行，此逻辑可能正确；然而，如果输入中指数后有空格，则getchar()可能读取空格而非换行，导致循环提前结束或读取错误。更可靠的方式是使用scanf返回值或逐字符读取。
        now=(link)malloc(sizeof(body));
        scanf("%d %d",&now->coefficient,&now->exponent);
        temp->to=now;
        temp=now;
    }

    now->to=NULL;

    second=(link)malloc(sizeof(body));
    temp=second;
    scanf("%d %d",&second->coefficient,&second->exponent);

    while(getchar()!='\n'){ // @@ 错误：同上，读取第二个多项式时存在相同问题，且若第一个多项式读取后缓冲区残留字符，可能导致第二个多项式读取异常。
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