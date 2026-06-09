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
    return stack[top--]; // @@ The function prints "error " when the stack is empty but still attempts to pop and return a value, which leads to undefined behavior and incorrect output. It should not return a value when empty.
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ This reads input incorrectly. It stores all integers (including operation codes) into the stack array, which corrupts the stack data. The input should be processed sequentially as operations, not stored as a flat array.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ This condition is flawed. It assumes operation codes and values are stored consecutively in the array, but the input format has operation codes (1, 0, -1) mixed with values. It also incorrectly checks stack[i+1]!=0, which may skip valid pushes.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop());
        }
    }
    return 0;
}