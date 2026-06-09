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
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow. The assignment should only occur if there's space.]
    s->data[s->top] = e; // @@ [This writes beyond the array bounds when the stack is full because s->top was incremented unconditionally.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [Accessing s->data[s->top] when the stack is empty (s->top == -1) leads to undefined behavior. This line should only execute if the stack is not empty.]
    printf("%d ", e); // @@ [Printing 'e' even when the stack is empty results in printing garbage or undefined values instead of just "error ".]
    s->top--; // @@ [Decrementing s->top when the stack is already empty causes it to go below -1, corrupting the stack state.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declaring an array of 101 stacks is unnecessary and incorrect; only one stack instance is needed. Should be 'together zhan;' instead.]
    origin(zhan); // @@ [Passing an array of stacks (zhan) to a function expecting a pointer to a single stack causes type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passing an array of stacks instead of a single stack instance leads to incorrect memory access.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passing an array instead of a single stack instance.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}