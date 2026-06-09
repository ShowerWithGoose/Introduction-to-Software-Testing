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
    return stack[top--]; // @@ When the stack is empty, this line still executes and accesses stack[-1], causing undefined behavior. It should return without accessing the stack or handle the error properly.
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ This reads input directly into the stack array, which is incorrect. The input contains operation codes (1, 0, -1) and values, not just values to be stored. It should read into a separate array for processing.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ This condition incorrectly checks stack[i+1]!=0, but the problem requires pushing the next integer after operation 1 regardless of its value. Also, it does not skip the pushed value in the loop, causing it to be processed again as an operation.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop());
        }
    }
    return 0;
}