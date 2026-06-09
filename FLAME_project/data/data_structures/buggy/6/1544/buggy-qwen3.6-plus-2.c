#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
int STACK[MAXSIZE];
int Top; // @@ The variable 'Top' is declared but never initialized to -1. It should be initialized in main or via initStack() which is defined but never called. This leads to undefined behavior, likely causing the first pop on an "empty" stack to fail incorrectly or access invalid memory, although in this specific test case, the issue manifests as missing the "error" output for the second pop because the state is corrupted or Top starts at garbage value. However, looking closely at the provided "Reference Program" vs "Source Code", the Source Code defines `initStack` but doesn't call it. The global `Top` is uninitialized. In C, global variables are initialized to 0 by default. So Top starts at 0. An empty stack should have Top = -1. With Top=0, isEmpty() returns false (0 == -1 is false). So the first pop works (popping STACK[0] which is 0/garbage? No, wait. If Top is 0, isEmpty is false. Pop prints STACK[0] and decrements Top to -1. The first push pushes to STACK[++Top] -> STACK[1]. So STACK[0] is unused/garbage. 
// Let's re-evaluate. Global int Top is 0. 
// Push 5: isFull? No. s[++Top] = s[1] = 5. Top is 1.
// Pop 0: isEmpty? (1 == -1) False. Print s[1] (5). Top becomes 0. Output: "5 ". Correct so far.
// Pop 0: isEmpty? (0 == -1) False. Print s[0] (0, since global array is zero-initialized). Top becomes -1. Output: "5 0 ". Expected: "5 error ". 
// The error is that Top was initialized to 0 instead of -1. The stack appeared to have one element (index 0) containing 0.
// To fix this, Top must be initialized to -1.

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
    initStack(); // @@ The function initStack() is defined to set Top to -1, but it is never called. Without this call, Top remains 0 (default global initialization), causing the stack to behave incorrectly (thinking index 0 is a valid element initially).
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