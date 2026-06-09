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
    return stack[top--]; // @@ [当栈为空时，top为-1，执行top--后top变为-2，然后访问stack[-2]导致未定义行为；且函数没有处理空栈情况，应返回一个默认值或修改逻辑]
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ [将输入直接存入stack数组会覆盖栈内容，且无法区分操作数和操作码；应使用临时变量存储输入]
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ [条件判断错误：push操作应直接读取下一个输入作为压栈值，但这里检查stack[i+1]!=0会错误地跳过值为0的压栈操作；且当i为最后一个元素时访问stack[i+1]越界]
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop());
        }
    }
    return 0;
}