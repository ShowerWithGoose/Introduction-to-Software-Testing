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
    printf("%s ", s); // @@ The error message "error " already contains a trailing space. In the reference program, the format is "%s " with argument "error", resulting in "error ". Here, passing "error " and printing "%s " results in "error  " (double space), causing a Presentation Error/Wrong Answer compared to expected output.
}
void push(ElemType item){
    if(isFull()) Error("error "); // @@ Same issue as above: passing "error " to Error which prints "%s " results in double spaces. Should pass "error".
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ Same issue as above: passing "error " to Error which prints "%s " results in double spaces. Should pass "error".
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