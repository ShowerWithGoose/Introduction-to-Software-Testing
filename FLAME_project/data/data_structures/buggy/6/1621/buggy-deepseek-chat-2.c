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
    if(isFull()) Error("error "); // @@ The error message string "error " already contains a trailing space, but the Error function adds another space, resulting in "error  " (two spaces). This causes the output to have an extra space after "error", which does not match the expected output format.
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ Same issue as in push: the Error function adds a space after the string, but the string already has a trailing space, producing "error  " (two spaces) instead of "error " (one space).
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