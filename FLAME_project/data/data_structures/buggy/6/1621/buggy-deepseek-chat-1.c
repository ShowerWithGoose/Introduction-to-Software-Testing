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
    if(isFull()) Error("error "); // @@ The error message "error " includes a trailing space, but the problem expects "error" without a space before the space that follows in the output. This causes an extra space in the output when printed.
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ Same issue as in push: the error message "error " has a trailing space, leading to an extra space in the output. The expected output is "error" followed by a single space from the printf in Error, but here it becomes "error  " (two spaces).
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