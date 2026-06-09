#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
void pop();
void push(int item);
int stack[MAXSIZE];
int top=-1;
int main(){
    int op=-1,num=0;
    scanf("%d",&op);
    while(op!=EOF){
        if(op==1){
            scanf("%d",&num);
            push(num);
        }
        else if(op==0)
            pop();
    scanf("%d",&op);
    }
    return 0;
}

void pop(){
    if(top!=-1){
        printf("%d ",stack[top--]);
    }else{
        printf("error ");
    }
}

void push(int item){
    if(top!=MAXSIZE-1){
        stack[++top] = item;
    }else{
        printf("error ");
    }
}

