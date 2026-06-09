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
            exit(1); // @@ 错误：栈满时应输出"error "并继续后续操作，不应终止程序。
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; // @@ 错误：空栈时不应执行此返回语句，因为top为-1导致越界；且函数应改为void，空栈时仅输出"error "。
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ 错误：将输入存入stack数组会导致与栈数组冲突，后续栈操作会覆盖未处理的输入数据，造成逻辑错误。
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ 错误：当i为最后一个索引时，stack[i+1]越界；且条件多余，应直接判断stack[i]==1。
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); // @@ 错误：pop函数在空栈时输出error后仍返回越界值，导致错误打印。
        }
    }
    return 0;
}