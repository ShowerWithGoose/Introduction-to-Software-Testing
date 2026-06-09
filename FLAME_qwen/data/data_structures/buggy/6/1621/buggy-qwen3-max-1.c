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
    if(isFull()) Error("error ");
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error ");
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
            ele=pop(); // @@ [When pop() returns -1 due to an empty stack, the program still checks 'if (ele != -1)' and skips printing, but the error message has already been printed by the Error() function inside pop(). However, the real issue is that returning -1 as an error code conflicts with valid data: if the stack actually contains -1 as a legitimate value, the caller cannot distinguish between a successful pop of -1 and an error. This leads to incorrect output behavior in cases where -1 is a valid stack element. The reference program avoids this by not using -1 as a return value for errors in pop(); instead, it prints "error " directly and does not rely on the return value to decide whether to print the popped value. In this buggy version, if a pop fails, it prints "error " via Error(), then returns -1, and main() sees ele == -1 and skips printing the value — which is correct for error handling, BUT if a real -1 was popped, main() would also skip printing it, causing missing output. Thus, the error is that the return value of pop() is used both for data and error signaling, and -1 is ambiguous.]
            if (ele != -1)
            printf("%d ", ele);
        }
    }
    return 0;
}