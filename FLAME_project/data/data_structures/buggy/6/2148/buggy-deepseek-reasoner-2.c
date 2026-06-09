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
            exit(1); // 终止程序 @@ 错误：应打印error后继续，不应exit
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; // @@ 错误：当栈空时也会执行，导致top越界递减，应仅在非空时返回
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ 错误：条件应为scanf==1，且应将操作码和数值分别处理，不应直接存入栈数组
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ 错误：条件不应检查stack[i+1]!=0，且应跳过下一个数
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); // @@ 错误：pop在空时会返回未定义值并打印，应修改pop函数或处理空栈情况
        }
    }
    return 0;
}