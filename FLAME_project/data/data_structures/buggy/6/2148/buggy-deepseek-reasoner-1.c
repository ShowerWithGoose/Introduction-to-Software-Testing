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
            exit(1); // 终止程序 @@ 错误：栈满时应该只输出"error "并继续，而不是终止程序。
    }
    stack[++top] = item;
}

// 出栈操作
int pop() {
    if (isEmpty()) {
         printf("error ");
    }
    return stack[top--]; @@ 错误：栈空时应该只输出"error "，不应修改top或返回值，否则导致后续状态错误。
}
int main(){
    int i=0,num;
    while(scanf("%d",&stack[i])!=-1){ @@ 错误：应该按顺序读取操作码，而不是将所有数字读入数组。这种处理方式无法正确处理操作序列。
        i++;
        num=i;
    }
    for(int i=0;i<num;i++){
        if(stack[i]==1&&stack[i+1]!=0){ @@ 错误：条件多余，应直接push(stack[i+1])；且可能越界。
            push(stack[i+1]);
        }
        else if(stack[i]==0){
            printf("%d ",pop()); @@ 错误：pop内部已经输出元素或error，此处不应再输出返回值。应改为pop(); 但pop返回值会导致多余输出。
        }
    }
    return 0;
}