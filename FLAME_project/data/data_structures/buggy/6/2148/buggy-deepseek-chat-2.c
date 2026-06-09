#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 120
int stack[MAX_SIZE];
int top=-1;
// 判断栈是否为空
int isEmpty() {
    return top == -1;
}

// 判断栈是否满了
int isFull() {
    return top == MAX_SIZE - 1;
}

// 入栈操作
void push(int item) {
    if (isFull()) {
         printf("error ");
            exit(1); // 终止程序
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; // @@ The function prints "error " when the stack is empty but still attempts to return stack[top--], which accesses an invalid index (top is -1). This causes undefined behavior and incorrect output. The function should not return a value when empty, or should handle the error differently.
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ This reads input incorrectly. It stores all integers (including operation codes 1, 0, -1) into the stack array, treating them as stack elements. The problem requires processing operations sequentially, not storing all input in the stack. Also, scanf returns the number of items read, not -1 on end-of-file; the loop condition should check for EOF or use a different approach.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ This logic is flawed. It assumes operation 1 is always followed by a value, but it doesn't correctly handle the sequence of operations. It also incorrectly checks stack[i+1]!=0, which may skip valid pushes. The program should process operations sequentially, not by scanning the array for patterns.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop());
        }
    }
    return 0;
}