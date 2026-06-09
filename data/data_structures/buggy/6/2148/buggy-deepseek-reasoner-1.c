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
            exit(1); // 终止程序 @@ 当栈满时应当只输出"error "并继续执行，而不是终止程序
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; // @@ 当栈空时，top为-1，访问stack[-1]导致未定义行为；且空栈时不应返回任何值
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
            printf("%d ",pop());
        }
    }
    return 0;
}