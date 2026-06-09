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
            exit(1); // 终止程序 @@ Should not terminate the program; must continue processing subsequent operations after printing "error ".
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; @@ Executes unconditionally even when stack is empty, causing out-of-bounds access and printing garbage values after "error ".
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ @@ Uses the global stack array to store input, causing data corruption with stack operations; also fails to properly handle -1 as termination signal.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ @@ Fails to increment index to skip the pushed value, causing it to be processed as an operation next; condition stack[i+1]!=0 is incorrect per problem spec.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); @@ pop() already prints "error " when empty and returns an invalid value, resulting in duplicate/incorrect output.
        }
    }
    return 0;
}