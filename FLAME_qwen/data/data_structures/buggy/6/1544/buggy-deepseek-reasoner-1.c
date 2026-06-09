#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000 // @@ 应定义为100，以符合问题描述的最大容量100。
int STACK[MAXSIZE];
int Top; // @@ 未初始化为-1，全局变量默认初始化为0，导致栈初始状态错误。应初始化为-1。

void initStack() {
    Top= -1;
}

int isEmpty( ) {
    return Top== -1;
}

int isFull() {
    return Top==MAXSIZE-1;
}

void push( int s[],  int item ) {
    if( isFull() )
        printf("error ");
    else
        s[++Top]=item;
}

void pop( int s[]) {
    if(isEmpty())
        printf("error ");
    else
        printf("%d ", s[Top--]);
}

int main() {
    while(1) {
        int sign;
        scanf("%d",&sign);

        if(sign==1) { //入栈操作
            int in;//入栈元素
            scanf("%d",&in);//后跟一个整数（不为1、0和-1）为入栈元素；
            push(STACK, in);
        } else if(sign==0) { //出栈操作
            pop(STACK);
        } else if(sign==-1) break; //操作结束。
    }

    return 0;
}