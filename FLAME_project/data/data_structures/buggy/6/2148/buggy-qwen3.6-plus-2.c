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
    return stack[top--]; // @@ The function prints "error " but still executes stack[top--], which accesses invalid memory (index -1) when the stack is empty. It should return immediately or handle the error state without modifying the stack pointer. Additionally, the main loop prints the return value of pop() even when an error occurs, leading to incorrect output like "0" or garbage values instead of just "error ".
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); // @@ This line blindly prints the return value of pop(). If pop() encounters an empty stack, it prints "error " internally but returns an undefined/invalid value (due to accessing stack[-1]), which is then printed here. The logic should check if the stack is empty before calling pop, or pop should not return a value to be printed in case of error. Also, the problem requires handling push errors (full stack), but the current push implementation exits the program entirely instead of printing "error " and continuing.
        }
    }
    return 0;
}