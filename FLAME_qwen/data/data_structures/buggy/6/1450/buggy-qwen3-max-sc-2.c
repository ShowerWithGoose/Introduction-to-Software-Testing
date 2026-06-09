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
    s->top++; // @@ [The increment and assignment happen even when the stack is full, leading to buffer overflow. The code should return or skip the push after printing "error".]
    s->data[s->top] = e; // @@ [This line executes even when the stack is full, causing undefined behavior due to writing beyond array bounds.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This line executes even when the stack is empty, leading to reading from invalid memory (index -1).]
    printf("%d ", e); // @@ [Prints a value even when the stack is empty, which is incorrect. Should only print if pop is valid.]
    s->top--; // @@ [Decrements top even when the stack is empty, making top -2, which corrupts stack state.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declares an array of 101 stacks instead of a single stack. Should be 'together zhan;' to match usage in function calls.]
    origin(zhan); // @@ [Passes array of stacks (zhan) as if it were a single stack pointer. This causes type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passes array of stacks instead of a single stack, leading to incorrect memory access.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passes array instead of single stack instance.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}