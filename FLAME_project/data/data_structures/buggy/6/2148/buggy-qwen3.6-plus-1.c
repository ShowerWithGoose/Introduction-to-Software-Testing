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
    return stack[top--]; // @@ The function returns a value even when the stack is empty, leading to undefined behavior or incorrect output. It should only return after checking isEmpty and printing error, or handle the return value carefully in main. More critically, the main logic below is flawed.
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ // @@ This reads all input into the 'stack' array, overwriting the actual stack data structure intended for push/pop operations. The variable name 'stack' is reused confusingly for input storage.
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){ // @@ The loop iterates through the raw input array. The logic for identifying operations is incorrect.
        if(stack[i]==1&&stack[i+1]!=0){ // @@ This condition assumes that every '1' is followed by a value to push, but it doesn't correctly skip the pushed value in the iteration, leading to misinterpretation of subsequent inputs. Also, it fails to handle the end marker -1 properly within the loop bounds.
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); // @@ When pop() prints "error ", it still returns a value (garbage or out of bounds), which is then printed here. The problem requires printing "error " instead of the popped value if an error occurs.
        }
    }
    return 0;
}