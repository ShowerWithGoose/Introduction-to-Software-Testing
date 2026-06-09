#include<stdio.h>

typedef struct stack{
    int top;
    int data[100];
}stack;

int main(){
    stack s;
    s.top = 0;
    int op;
    while(scanf("%d",&op)!=EOF){
        if(op==-1) break;
        if(1==op){
            if(s.op==100) // @@ [编译错误：'stack'没有成员'op'，应为'top'；且逻辑错误：栈满时仍需读取输入的整数以避免后续输入错位]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); // @@ [输出格式错误：缺少空格，根据题目要求应在每个弹出元素后输出空格]
        }
    }
    return 0;
}