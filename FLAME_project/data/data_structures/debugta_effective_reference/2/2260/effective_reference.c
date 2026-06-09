#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct stack{
    int *data;
    int *priority;
    char mark[2];
    int size;
    int top;
}stack;

stack *init(){
    stack *sss=(stack *)malloc(sizeof(stack));
    sss->data=malloc(sizeof(int)*1000);
    sss->priority=malloc(sizeof(char)*1000);
    sss->size=0;
    sss->top=-1;
    return sss;
}

void push(stack *sss,int val,char mark,int pri){
    sss->data[++sss->top]=val;
    sss->mark[sss->top]=mark;
    sss->priority[sss->top]=pri;
    sss->size++;
}

int peekpri(stack *sss){
    return sss->priority[sss->top];
}
int peekdata(stack *sss){
    return sss->data[sss->top];
}

int peekmark(stack *sss){
    return sss->mark[sss->top];
}

void pop(stack *sss){
    sss->top--;
    sss->size--;
}

int isempty(stack *sss){
    if(sss->size==0)return 1;
    return 0;
}

int cal(int a,char mark,int b){
    if(mark=='+')return a+b;
    if (mark=='-')return a-b;
    if(mark=='*')return a*b;
    return a/b;
}



int main() {
    int num;
    char mark;
    int pri;
    stack *sss=init();
    scanf("%d %c",&num,&mark);
    while(mark!='='){
        if(mark=='+'||mark=='-')pri=1;
        else pri=2;//pri为计算优先级与顺序优先级的综合，保证优先级序列降序；
        if(isempty(sss)|| peekpri(sss)<pri ){push(sss, num, mark,pri);scanf("%d %c",&num,&mark);}
        else{
            num=cal(peekdata(sss),peekmark(sss),num);
            pop(sss);
        }
    }
    while (!isempty(sss)) {
        num=cal(peekdata(sss),peekmark(sss),num);
        pop(sss);
    }
    printf("%d",num);
    
    
}

