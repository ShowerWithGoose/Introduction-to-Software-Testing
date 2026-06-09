#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct zhan{
    int  data[100];
    int top;
}together;

//建栈(初始化栈顶指针)
void origin(together * s){
    s->top = -1;
}
//判断栈是否为空
//bool empty(zhan s){
//    if (s.top == -1)return true;//1
//    else return false;//0
//}
//进栈
void push(together *s, int e) {
    if (s->top == 100 - 1) {
        printf("error ");
    }
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow. The push should only occur if not full.]
    s->data[s->top] = e; // @@ [This assignment occurs even after printing "error", which is incorrect behavior.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [Accessing stack data even when stack is empty (after printing "error"), which leads to undefined behavior.]
    printf("%d ", e); // @@ [Printing popped value even when stack was empty, which is incorrect.]
    s->top--; // @@ [Decrementing top even when stack was empty, causing invalid state.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declaring an array of 101 stacks instead of a single stack. Should be 'together zhan;' or 'together zhan = {0};'.]
    origin(zhan); // @@ [Passing array of stacks to function expecting pointer to a single stack. This causes type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passing array of stacks instead of a single stack instance.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passing array instead of single stack.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}