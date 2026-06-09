#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
ElemType Stack[MAXSIZE];
int top=-1;
void initStack(){
    top=-1;
}
int isEmpty(){
    return top == -1;
}
int isFull(){
    return top==MAXSIZE-1;
}
void Error(char s[]){
    printf("%s ", s);
}
void push(ElemType item){
    if(isFull()) Error("error "); // @@ [The Error function already adds a space; passing "error " results in double space. Should be "error".]
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ [Same reason: double space due to trailing space in string.]
        return -1;
    } 
    else return Stack[top--];
}
int main(){
    int cmd;
    ElemType ele;
    initStack();
    while(1){
        scanf("%d", &cmd);
        if(cmd==-1) break;
        if(cmd==1){
            scanf("%d", &ele);
            push(ele);
        }else if(cmd==0){
            ele=pop();
            if (ele != -1)
            printf("%d ", ele);
        }
    }
    return 0;
}