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
    if(isFull()) Error("error "); // @@ The error message "error " already contains a trailing space, but the problem description and expected output imply that "error" should be printed followed by a space. However, looking at the reference program, it prints "error " (with space). The main issue is likely elsewhere. Let's look closer. Actually, the reference program prints "error " via `Error("error")` which does `printf("%s ", Stack)`. So it prints "error " . The buggy code calls `Error("error ")` which prints "error  " (two spaces). This might cause formatting issues but usually judges are tolerant or strict on exact match. Let's look at the pop logic.
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ Similar to push, this prints "error  " (double space) because Error adds a space after its argument. It should probably be Error("error").
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
            if (ele != -1) // @@ The value -1 is a valid integer that can be pushed onto the stack (as seen in the test case: `1 -56`, `1 -45`). If -1 is pushed and then popped, `pop()` returns -1. The condition `if (ele != -1)` will incorrectly treat this valid popped value as an error indicator (since `pop` returns -1 on error), causing the valid element -1 to not be printed. A separate flag or different error handling mechanism is needed to distinguish between a popped value of -1 and an error state.
            printf("%d ", ele);
        }
    }
    return 0;
}