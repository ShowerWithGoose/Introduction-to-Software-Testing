#include "stdio.h"

void push(int stack[], int data, int top) { // @@ top应该是指针类型，否则内部修改不影响外部，导致主调中的top不同步
    if (top >= 99) { // @@ 条件本身正确（栈满时top=99），但由于值传递，这里判断的是传入的旧top值，可能与实际情况不符
        printf("error ");
        return;
    }
    top++; // @@ 修改的是局部变量，不影响main中的top
    stack[top] = data; // @@ 赋值给局部top索引，但main中的top未更新，后续主调又top++，导致重复增加
    return;
}

int pop(int stack[], int top) { // @@ top应该是指针类型，否则内部无法修改主调中的top
    if (top <= -1) { // @@ 空栈判断正确，但返回后主调仍会执行top--，导致top变成-2
        printf("error ");
        return 0; // @@ 返回0后，主调会基于a!=0决定是否打印，但空栈时仍执行top--，导致索引越界
    }

    return stack[top]; // @@ 返回栈顶元素，但未减少top，需要主调手动top--，但空栈时错误
}

int main() {
    int stack[100] = {0};
    int top = -1;
    int op;
    while (scanf("%d", &op) != -1) {
        // 1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
        if (op == -1) {
            break;
        } else if (op == 1) {
            int data;
            scanf("%d", &data);
            push(stack, data, top); // @@ 调用后top未被更新，但push内部已经修改了局部top
            top++; // @@ 与push内部的top++重复，导致top每次入栈增加2

        } else {
            int a = pop(stack, top); // @@ pop返回栈顶元素，但未修改top
            if (a != 0) {
                printf("%d ", a);
            }
            top--; // @@ 空栈时也执行，导致top变为-2，后续push时访问越界
        }
    }
    return 0;
}