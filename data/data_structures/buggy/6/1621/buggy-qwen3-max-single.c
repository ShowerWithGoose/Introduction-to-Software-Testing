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
            ele=pop(); // @@ [When pop() returns -1 due to an empty stack, the code still prints "-1 " because it only checks `if (ele != -1)` after calling pop(), but pop() already printed "error ". This leads to both "error " and "-1 " being printed for an empty pop, which is incorrect. The logic should avoid printing the returned value if an error occurred.]
            if (ele != -1)
            printf("%d ", ele);
        }
    }
    return 0;
}