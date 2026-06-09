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
    stack *s=(stack *)malloc(sizeof(stack));
    s->data=malloc(sizeof(int)*1000);
    s->priority=malloc(sizeof(char)*1000);
    s->size=0;
    s->top=-1;
    return s;
}

void push(stack *s,int val,char mark,int pri){
    s->data[++s->top]=val;
    s->mark[s->top]=mark;
    s->priority[s->top]=pri;
    s->size++;
}

int peekpri(stack *s){
    return s->priority[s->top];
}
int peekdata(stack *s){
    return s->data[s->top];
}

int peekmark(stack *s){
    return s->mark[s->top];
}

void pop(stack *s){
    s->top--;
    s->size--;
}

int isempty(stack *s){
    if(s->size==0)return 1;
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
    stack *s=init();
    scanf("%d %c",&num,&mark);
    while(mark!='='){
        if(mark=='+'||mark=='-')pri=1;
        else pri=2;//pri为计算优先级与顺序优先级的综合，保证优先级序列降序；
        if(isempty(s)|| peekpri(s)<pri ){push(s, num, mark,pri);scanf("%d %c",&num,&mark);}
        else{
            num=cal(peekdata(s),peekmark(s),num);
            pop(s);
        }
    }
    while (!isempty(s)) {
        num=cal(peekdata(s),peekmark(s),num);
        pop(s);
    }
    printf("%d",num);
    
    
}

