#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
const int MAX_LEN=101;
typedef struct
{
    int *top,*p;
}Stack,*pStack;
pStack newStack(){
    pStack p=(pStack)malloc(sizeof(Stack));
    p->top=(int*)malloc(MAX_LEN*sizeof(int));
    p->p=p->top;
    return p;
}
bool Stack_Push(int i,pStack p){
    if(p->p-p->top>=MAX_LEN)return false;
    *++(p->p)=i;
    return true;
}
int Stack_Pop(pStack p){
    if(p->p==p->top)return false;
    return *p->p--;
}
int main(){
    int op,t;
    pStack p=newStack();
    while(scanf("%d",&op)!=-1){
        if(op==1){
        scanf("%d",&t);
        if(!Stack_Push(t,p))printf("error ");
        }
        else if(op==0){
            t=Stack_Pop(p);
            if(t)printf("%d ",t);
            else printf("error ");
            }
        else break;
    }
    return 0;
}


