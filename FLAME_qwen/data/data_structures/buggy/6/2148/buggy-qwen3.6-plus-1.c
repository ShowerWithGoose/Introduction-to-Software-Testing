#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 120
int stack[MAX_SIZE]; // @@ The array 'stack' is used to store both the input operation sequence and the stack data structure, causing data conflict. A separate array should be used for input.
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
            exit(1); // 终止程序 // @@ The program should not terminate when the stack is full; it should only print "error " and continue processing subsequent operations.
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; // @@ When the stack is empty, top is -1, accessing stack[-1] causes an out-of-bounds error. It should not return a value after printing "error ".
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ scanf returns the number of successfully read items, not -1. It should check for EOF. Also, input should be stored in a separate array to avoid conflict with the stack.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ // @@ After processing a push operation, the loop index i should be incremented to skip the pushed value, otherwise it will be misinterpreted as an operation in the next iteration.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop());
        }
    }
    return 0;
}